#include "jeu.h"
#include "couleurs.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <stdbool.h>

/* Fonction pour lire la case du morpion (ligne et colonne entre 1 et 3)*/
int lire_case(int *ligne, int *colonne)
{
    printf("Entrez la ligne (1-3) : ");

    if (!lire_int("", ligne))
    {
        return 0;
    }

    if (*ligne == 7)
    {
        quitter_jeu();
    }
    if (*ligne < 1 || *ligne > 3)
    {
        return 0;
    }

    printf("Entrez la colonne (1-3) : ");
    if (!lire_int("", colonne))
    {
        return 0; // Retourne 0 si la valeur entrée n'est pas un entier
    }

    if (*colonne == 7)
    {
        quitter_jeu(); // Quitte le jeu si l'utilisateur entre 7
    }
    if (*colonne < 1 || *colonne > 3)
    {
        return 0;
    }
    return 1; // Retourne 1 si la lecture est réussie
}

/* Quitte le jeu simplement. */
void quitter_jeu(void)
{
    printf("Fermeture du jeu. Merci d'avoir joué !\n");
    // printf(EFFACER_ECRAN EFFACER_HISTORIQUE);
    exit(0);
}
