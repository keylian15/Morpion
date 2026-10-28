#include <stdio.h>

#include "grille.h"
#include "jeu.h"

char grille[3][3];

/* Initialise la grille de morpion avec des espaces vides. */
void initialiser_grille(void)
{
    int ligne;
    int colonne;

    for (ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        for (colonne = 0; colonne < TAILLE_GRILLE; colonne++)
            grille[ligne][colonne] = ' ';
    }
}

/* Affiche la grille de morpion. */
void afficher_grille(void)
{
    int ligne;

    printf("\n");
    for (ligne = 0; ligne < TAILLE_GRILLE; ligne++)
    {
        printf(" %c | %c | %c \n",
               grille[ligne][0], grille[ligne][1], grille[ligne][2]);
        if (ligne < TAILLE_GRILLE - 1)
            printf("---+---+---\n");
    }
    printf("\n");
}
