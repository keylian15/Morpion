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
    Coup coups[9];
} Partie;

Partie* initialiser_partie(char j1, char j2);

#endif