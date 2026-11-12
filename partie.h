/* partie.h */
#ifndef PARTIE_H
#define PARTIE_H

typedef struct
{
    int joueur;  /* 1 ou 2 */
    int ligne;   /* 1 a 3 */
    int colonne; /* 1 a 3 */
} Coup;

typedef struct
{
    char j1;  /* symbole du joueur 1 */
    char j2;  /* symbole du joueur 2 */
    int etat; /* 3 = en cours, 0 = nul, 1/2 = gagnant */
    int nb_coups;
    char id[32]; /* "AAAAMMJJ_HHMMSS", sert aussi de nom de fichier */
    char mode[8]; /* "2j" ou "ordi" */
    Coup coups[9];
} Partie;

/* Initialise une nouvelle partie et cree son fichier de sauvegarde.
 * Retourne : 0 = ok, -1 = erreur (id impossible, dossier ou fichier non cree) */
int initialiser_partie(Partie *p, char j1, char j2, const char *mode);

#endif