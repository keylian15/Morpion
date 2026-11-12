#include <stdio.h>
#include <string.h>
#include <time.h>
#include <direct.h> /* _mkdir (Windows) */
#include <dirent.h> /* opendir / readdir (MinGW) */
#include "sauvegarde.h"
#include "grille.h"
#include "victoire.h"

#define DOSSIER_SAVES "saves"

/* ========== Utilitaires internes ========== */

/* Construit le chemin "saves/<id>.txt" dans buf. */
static void chemin_partie(char *buf, size_t taille, const char *id)
{
    snprintf(buf, taille, DOSSIER_SAVES "/%s.txt", id);
}

/* ========== Creation / sauvegarde ========== */

/* Genere un id unique "AAAAMMJJ_HHMMSS" a partir de l'heure courante.
 * Cree le dossier saves/ s'il n'existe pas.
 * Si le fichier existe deja (deux parties dans la meme seconde),
 * ajoute un suffixe _2, _3... jusqu'a _99.
 * Retourne : 0 = ok (id rempli), -1 = erreur */
int generer_id(char *id, size_t taille)
{
    char base[32];
    char chemin[64];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    /* Date et heure formatees : le tri alphabetique = tri chronologique */
    if (tm == NULL || strftime(base, sizeof(base), "%Y%m%d_%H%M%S", tm) == 0)
        return -1;

    _mkdir(DOSSIER_SAVES); /* echoue si le dossier existe deja : sans importance */

    for (int n = 1; n <= 99; n++)
    {
        /* n == 1 : id sans suffixe ; ensuite _2, _3... */
        if (n == 1)
            snprintf(id, taille, "%s", base);
        else
            snprintf(id, taille, "%s_%d", base, n);

        chemin_partie(chemin, sizeof(chemin), id);

        /* Si on ne peut pas ouvrir en lecture, le fichier n'existe pas : nom libre */
        FILE *f = fopen(chemin, "r");
        if (f == NULL)
            return 0;
        fclose(f);
    }
    return -1; /* 99 collisions : abandon */
}

/* Reecrit entierement saves/<id>.txt a partir de la partie.
 * Format : en-tete "cle=valeur" puis une ligne "joueur ligne colonne" par coup.
 * Retourne : 0 = ok, -1 = erreur (id vide, ouverture ou fermeture echouee) */
int sauvegarder_partie(const Partie *p)
{
    char chemin[64];

    /* Id vide = la creation a echoue : pas de sauvegarde pour cette partie */
    if (p->id[0] == '\0')
        return -1;

    chemin_partie(chemin, sizeof(chemin), p->id);

    FILE *f = fopen(chemin, "w"); /* "w" tronque le fichier : on reecrit tout */
    if (f == NULL)
        return -1;

    /* En-tete */
    fprintf(f, "mode=%s\n", p->mode);
    fprintf(f, "j1=%c\n", p->j1);
    fprintf(f, "j2=%c\n", p->j2);
    fprintf(f, "etat=%d\n", p->etat);

    /* Coups, dans l'ordre : la ligne N de cette section = le coup N */
    for (int i = 0; i < p->nb_coups; i++)
        fprintf(f, "%d %d %d\n", p->coups[i].joueur, p->coups[i].ligne, p->coups[i].colonne);

    /* fclose peut echouer (disque plein) : on remonte l'erreur */
    return (fclose(f) == 0) ? 0 : -1;
}

/* ========== Chargement ========== */

/* Cherche l'id de la partie la plus recente dans saves/.
 * Les ids etant "AAAAMMJJ_HHMMSS[_n]", le plus grand par ordre
 * alphabetique est le plus recent.
 * Retourne : 0 = ok (id rempli), -1 = aucune partie trouvee */
int derniere_partie(char *id, size_t taille)
{
    DIR *d = opendir(DOSSIER_SAVES);
    if (d == NULL)
        return -1; /* dossier absent : aucune partie */

    char cand[64]; /* nom candidat, sans l'extension */
    struct dirent *e;
    id[0] = '\0'; /* vide = rien trouve pour l'instant */

    while ((e = readdir(d)) != NULL)
    {
        size_t len = strlen(e->d_name);

        /* On ne garde que les fichiers "*.txt" (ignore ".", "..", etc.) */
        if (len <= 4 || strcmp(e->d_name + len - 4, ".txt") != 0)
            continue;
        len -= 4; /* longueur du nom sans ".txt" */

        /* Nom trop long pour nos buffers : on l'ignore */
        if (len >= sizeof(cand) || len >= taille)
            continue;

        memcpy(cand, e->d_name, len);
        cand[len] = '\0';

                if (strcmp(cand, "index") == 0)
            continue;

        /* On garde le plus grand nom = le plus recent */
        if (id[0] == '\0' || strcmp(cand, id) > 0)
            snprintf(id, taille, "%s", cand);
    }
    closedir(d);

    return (id[0] != '\0') ? 0 : -1;
}

/* Rejoue les coups de p sur la grille globale, en verifiant leur coherence :
 *  - alternance stricte des joueurs (J1 commence)
 *  - ligne et colonne dans [1, 3]
 *  - case vide au moment du coup
 *  - aucun coup apres la fin de la partie
 * Met p->etat a jour avec l'etat recalcule.
 * Retourne : 0 = ok, -1 = incoherent */
static int rejouer_coups(Partie *p)
{
    int etat = 3; /* partie en cours tant qu'aucun coup n'a ete rejoue */

    initialiser_grille();

    for (int i = 0; i < p->nb_coups; i++)
    {
        const Coup *c = &p->coups[i];
        int attendu = (i % 2 == 0) ? 1 : 2; /* coup 1 -> J1, coup 2 -> J2... */

        /* Validation du coup avant de toucher a la grille */
        if (c->joueur != attendu ||
            c->ligne < 1 || c->ligne > 3 ||
            c->colonne < 1 || c->colonne > 3 ||
            grille[c->ligne - 1][c->colonne - 1] != ' ')
            return -1;

        /* On pose le symbole du joueur (les symboles sont dans l'en-tete) */
        grille[c->ligne - 1][c->colonne - 1] = (c->joueur == 1) ? p->j1 : p->j2;

        /* Meme verification qu'en jeu normal */
        etat = verifier_reussite(grille, c->joueur, i + 1);

        /* Partie finie mais il reste des coups dans le fichier : incoherent */
        if (etat != 3 && i != p->nb_coups - 1)
            return -1;
    }

    p->etat = etat;
    return 0;
}

/* Charge une partie depuis saves/<id>.txt (id == NULL : la derniere).
 * Apres un chargement reussi : p est rempli, la grille globale est
 * reconstruite et p->etat est recalcule (donc fiable).
 * Retourne : CHARGER_OK, CHARGER_ABSENT (pas de fichier)
 *            ou CHARGER_CORROMPU (fichier illisible ou incoherent) */
int charger_partie(const char *id, Partie *p)
{
    char cible[32]; /* id de la partie a charger */
    char chemin[64];
    char ligne[64];                                 /* ligne courante du fichier */
    int a_mode = 0, a_j1 = 0, a_j2 = 0, a_etat = 0; /* champs d'en-tete trouves */
    int etat_fichier = 0;                           /* etat ecrit dans le fichier */

    /* Copie locale de l'id : l'appelant peut passer p->id, que le memset efface */
    if (id == NULL)
    {
        if (derniere_partie(cible, sizeof(cible)) != 0)
            return CHARGER_ABSENT;
    }
    else
        snprintf(cible, sizeof(cible), "%s", id);

    memset(p, 0, sizeof(*p));
    snprintf(p->id, sizeof(p->id), "%s", cible); /* la reprise reecrira ce fichier */

    chemin_partie(chemin, sizeof(chemin), cible);
    FILE *f = fopen(chemin, "r");
    if (f == NULL)
        return CHARGER_ABSENT;

    /* Lecture ligne par ligne : en-tete (cle=valeur) puis coups */
    while (fgets(ligne, sizeof(ligne), f) != NULL)
    {
        int j, l, c;

        /* Lignes vides ignorees */
        if (ligne[0] == '\n' || ligne[0] == '\0')
            continue;

        /* En-tete : chaque sscanf retourne 1 si la ligne correspond a la cle */
        if (sscanf(ligne, "mode=%7s", p->mode) == 1)
            a_mode = 1;
        else if (sscanf(ligne, "j1=%c", &p->j1) == 1)
            a_j1 = 1;
        else if (sscanf(ligne, "j2=%c", &p->j2) == 1)
            a_j2 = 1;
        else if (sscanf(ligne, "etat=%d", &etat_fichier) == 1)
            a_etat = 1;
        /* Coup : "joueur ligne colonne" */
        else if (sscanf(ligne, "%d %d %d", &j, &l, &c) == 3)
        {
            if (p->nb_coups >= 9) /* plus de 9 coups : impossible */
            {
                fclose(f);
                return CHARGER_CORROMPU;
            }
            p->coups[p->nb_coups++] = (Coup){j, l, c};
        }
        /* Ligne non reconnue ou tronquee (sauvegarde interrompue) */
        else
        {
            fclose(f);
            return CHARGER_CORROMPU;
        }
    }
    fclose(f);

    /* Tous les champs d'en-tete doivent etre presents */
    if (!(a_mode && a_j1 && a_j2 && a_etat))
        return CHARGER_CORROMPU;

    /* Reconstruit la grille et valide les coups */
    if (rejouer_coups(p) != 0)
        return CHARGER_CORROMPU;

    /* L'etat ecrit dans le fichier doit correspondre a l'etat recalcule */
    if (p->etat != etat_fichier)
        return CHARGER_CORROMPU;

    return CHARGER_OK;
}