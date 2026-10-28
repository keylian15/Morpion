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

        /* Affichage de la table */

        afficherGrill();

        /* Vérification de la réussite et affichage du résultat*/
        
        char result = verifier_reussite(board);
        if(result!=' '){
            
            afficher_resultat(result);
            gameover = true;

        }
    }

}

/* fonction pour annoncer les résultat (peut être utilisée pour afficher le gagnant ou un message de match nul)*/

void afficher_resultat(char result)
{
    if (result == 'X')
    {
        printf("Le joueur 1 a gagné !\n");
    }
    else if (result == 'O')
    {
        printf("Le joueur 2 a gagné !\n");
    }
    else if (result == 'D')
    {
        printf("Match nul !\n");
    }
}

/*fonction pour vérifier la réussite du jeu (peut être utilisée pour les statistiques du jeu)*/

char verifier_reussite(char board[3][3])
{

    for(int i=0;i<3;i++)
    {
        /* il suffit de vérifier si les trois cases d'une ligne/colonne sont identiques et non vides */
        /* pour cela c'est suffisant de voir is la première case est le même que le deuxième, et que le deuxième et identiqe à la troisième*/
        /* Vérification des lignes */
        
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' ')
        {
            printf("Le joueur %c a gagné !\n", board[i][0]);
            return board[i][0]; /* Retourne le symbole du joueur gagnant */
        }
        /* Vérification des colonnes */
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
        {
            printf("Le joueur %c a gagné !\n", board[0][i]);
            return board[0][i]; /* Retourne le symbole du joueur gagnant */
        }

        /* Vérification des diagonales */
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
        {
            printf("Le joueur %c a gagné !\n", board[0][0]);
            return board[0][0]; /* Retourne le symbole du joueur gagnant */
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
        {
            printf("Le joueur %c a gagné !\n", board[0][2]);
            return board[0][2]; /* Retourne le symbole du joueur gagnant */
        }
    }

    /* verifier si match nul */
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                return ' '; /* on continue*/
            }
        }
    }
    return 'D'; /* si tous les conditions cité ci-dessus sont non vérifié, on Retourne 'D'  */
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
