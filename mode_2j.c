
#include <stdio.h>
#include <stdbool.h>
#include "couleurs.h"
#include "victoire.h"
#include "jeu.h"
#include "grille.h"

/*fonction principal du jeu mode 2 joueurs*/

int deux_joueurs(char x, char o) // Les deux variables pour les deux joueurs avec leur propres symbole.
{
    int ligne, colonne;
    int tour = 1;
    char symbole;
    bool gameover = false;

    while (!gameover)
    {
        /* Stockage du symbole du joueur courant */
        symbole = (tour == 1) ? x : o;

        /* Tour du joueur 1 ou 2 */
        printf("Tour du joueur %d (symbole: %c):\n", tour, symbole);

        while (lire_case(&ligne, &colonne) == 0)
        {
            printf(ROUGE "Saisie invalide. Veuillez entrer un entier entre 1 et 3.\n" RESET);
        }

        /* On verifie qu'il est vide */
        if (grille[ligne - 1][colonne - 1] == ' ')
        {
            grille[ligne - 1][colonne - 1] = symbole;
        }
        else
        {
            printf(ROUGE "Case déjà occupée. Veuillez réessayer.\n" RESET);
            continue; // Recommence le tour du même joueur
        }

        afficher_grille();

        int result = verifier_reussite(grille, tour);

        if (result != 3)
        {
            afficher_resultat(result);
            gameover = true;
        }
        else
        {
            tour = (tour == 1) ? 2 : 1;
        }
    }
    return 0;
}
