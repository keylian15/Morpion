
#include <stdio.h>
#include <stdbool.h>
#include "couleurs.h"
#include "victoire.h"
#include "jeu.h"
#include "grille.h"

/*fonction principal du jeu mode 2 joueurs*/

int deux_joueurs(char x, char o) //variables for the players' symbols
{
    int ligne, colonne;
    int tour = 1;
    bool gameover = false;

    //removed the two if statements and replaced with a single if statement to check for gameover

    while(!gameover )
    {
        /* Tour du joueur 1 ou 2 */

            printf("tour du joueur %d:\n", tour); //can later be changed for symbols instead of numbers

            while (lire_case(&ligne, &colonne)== 0)
            {
                printf(ROUGE "Saisie invalide. Veuillez réessayer.\n" RESET);
            } 

        /* on place le pion - à determiner comment personnalier le symbole*/
        /*on verifie qu'il est vide */

        if (grille[ligne - 1][colonne - 1] == ' ')
        {
            if (tour == 1) {
                grille[ligne - 1 ][colonne - 1]=x;
            } else {
                grille[ligne - 1 ][colonne - 1]=o;
            }
        }
        else
        {
            printf(ROUGE "Case déjà occupée. Veuillez réessayer.\n" RESET);
            continue; // Recommence le tour du même joueur
        }
                
        afficher_grille();

        int result = verifier_reussite(grille, tour);

        if(result != 3)
        {
            afficher_resultat(result);
            gameover = true;

        }
        else
        {
            tour = (tour == 1) ? 2 : 1;
        }

        /* Affichage de la table */


    }

        
     return 0;  
}

