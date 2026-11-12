#include <stdio.h>
#include <time.h>
#include "sauvegarde.h"

#include <direct.h>
#define DOSSIER_SAVES "saves"

/* Construit "saves/<id>.txt" dans buf. */
static void chemin_partie(char *buf, size_t taille, const char *id)
{
    snprintf(buf, taille, DOSSIER_SAVES "/%s.txt", id);
}

int generer_id(char *id, size_t taille)
{
    char base[32];
    char chemin[64];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    if (tm == NULL || strftime(base, sizeof(base), "%Y%m%d_%H%M%S", tm) == 0)
        return -1;

    _mkdir(DOSSIER_SAVES); /* echoue si deja existant : sans importance */

    for (int n = 1; n <= 99; n++)
    {
        if (n == 1)
            snprintf(id, taille, "%s", base);
        else
            snprintf(id, taille, "%s_%d", base, n);

        chemin_partie(chemin, sizeof(chemin), id);

        FILE *f = fopen(chemin, "r");
        if (f == NULL)
            return 0; /* nom libre */
        fclose(f);
    }
    return -1; /* 99 collisions : abandon */
}

int sauvegarder_partie(const Partie *p)
{
    char chemin[64];

    if (p->id[0] == '\0')
        return -1;

    chemin_partie(chemin, sizeof(chemin), p->id);

    FILE *f = fopen(chemin, "w");
    if (f == NULL)
        return -1;

    fprintf(f, "mode=%s\n", p->mode);
    fprintf(f, "j1=%c\n", p->j1);
    fprintf(f, "j2=%c\n", p->j2);
    fprintf(f, "etat=%d\n", p->etat);

    for (int i = 0; i < p->nb_coups; i++)
        fprintf(f, "%d %d %d\n", p->coups[i].joueur, p->coups[i].ligne, p->coups[i].colonne);

    return (fclose(f) == 0) ? 0 : -1;
}