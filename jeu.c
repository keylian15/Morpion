#include "couleurs.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <stdbool.h>

/*déclarons variable global pour la table*/

/* Fonction pour lire la case du morpion (ligne et colonne entre 1 et 3)*/
int lire_case(int *ligne, int *colonne)
{
    printf("Entrez la ligne (1-3) : ");
    if (!lire_int("", ligne) || *ligne < 1 || *ligne > 3)
    {
        printf(ROUGE "Ligne invalide. Veuillez entrer un entier entre 1 et 3.\n" RESET);
        return 0;
    }
    printf("Entrez la colonne (1-3) : ");
    if (!lire_int("", colonne) || *colonne < 1 || *colonne > 3)
    {
        printf(ROUGE "Colonne invalide. Veuillez entrer un entier entre 1 et 3.\n" RESET);
        return 0;
    }
    return 1;
}


/* Quitte le jeu simplement. */
void quitter_jeu(void)
{
    printf("Fermeture du jeu. Merci d'avoir joué !\n");
    // printf(EFFACER_ECRAN EFFACER_HISTORIQUE);
    exit(0);
}
