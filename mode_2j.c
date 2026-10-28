
#include <stdio.h>
#include <stdbool.h>
#include "victoire.h"
#include "jeu.h"
#include "grille.h"

/*fonction principal du jeu mode 2 joueurs*/

int deux_joueurs(void)
{
    int ligne, colonne;
    int tour = 1;
    int temp_var = 0;
    bool gameover = false;

    while(!gameover )
    {
        /* Tour du joueur 1 */
        if(tour==1)
        {
            printf("tour du joueur 1:\n");
            lire_case(&ligne, &colonne);
            grille[ligne][colonne]='X';
            tour=2;
        }
        /* Tour du joueur 1 */
        else{
            printf("tour due joueur 2:\n");
            lire_case(&ligne,&colonne);
            grille[ligne][colonne]='O';
            tour=1;
        }

        /* Affichage de la table */

        afficherGrill();

        /* Vérification de la réussite et affichage du résultat*/
        
        char result = verifier_reussite(grille);
        if(result!=' '){
            
            afficher_resultat(result);
            gameover = true;

        }
    }
return 0;
}
