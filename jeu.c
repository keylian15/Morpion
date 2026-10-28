#include "couleurs.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <stdbool.h>

/*déclarons variable global pour la table*/
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

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
            board[ligne][colonne]='X';
            tour=2;
        }
        /* Tour du joueur 1 */
        else{
            printf("tour due joueur 2:\n");
            lire_case(&ligne,&colonne);
            board[ligne][colonne]='O';
            tour=1;
        }

        /*nombre limit des tours, à changer lors de l'implémentation de veriier_reussite*/
        temp_var++;
        if(temp_var==9)
        {
            printf("Match nul !\n");
            gameover=true;
        }
    }

}

/*Placeholder Verifier le réussit/échot*/

int verifier_reussite()
{
    return 0;

}


/*Placeholder pour Affichage de grill*/

int afficherGrill(){
    //for Rom to do
    return 0;
}
/* Quitte le jeu simplement. */
void quitter_jeu(void)
{
    printf("Fermeture du jeu. Merci d'avoir joué !\n");
    // printf(EFFACER_ECRAN EFFACER_HISTORIQUE);
    exit(0);
}
