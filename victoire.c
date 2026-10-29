
#include "couleurs.h"
#include <stdio.h>

#include <stdbool.h>

void afficher_resultat(int result)
{
    if (result == 1)
    {
        printf(VERT "Le joueur 1 a gagné !\n" RESET);
    }
    else if (result == 2)
    {
        printf(VERT "Le joueur 2 a gagné !\n" RESET);
    }
    else if (result == 0)
    {
        printf(JAUNE_CLAIR "Match nul !\n" RESET);
    }
}


/* fonction pour vérifier si une ligne est gagnante */

static int ligne_gagnante(char a, char b, char c)
{
    return (a == b && b == c && a != ' ');
}

int verifier_reussite(char board[3][3], int tour)
{

    for(int i=0;i<3;i++)
    {
        /* il suffit de vérifier si les trois cases d'une ligne/colonne sont identiques et non vides */
        /* pour cela c'est suffisant de voir is la première case est le même que le deuxième, et que le deuxième et identiqe à la troisième*/
        /* Vérification des lignes */
        
        if(ligne_gagnante(board[i][0], board[i][1], board[i][2]))
        {
            return tour; /* Retourne numero du joueur gagnant */
        }
        /* Vérification des colonnes */
        if(ligne_gagnante(board[0][i], board[1][i], board[2][i]))
        {
            return tour;
        }

        /* Vérification des diagonales */
        if(ligne_gagnante(board[0][0], board[1][1], board[2][2]))
        {
            return tour; 
        }
        if(ligne_gagnante(board[0][2], board[1][1], board[2][0]))
        {
            return tour;
        }
    }

    /* verifier si match nul */
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                return 3; /* on continue*/
            }
        }
    }
    return 0; /* si tous les conditions cité ci-dessus sont non vérifié, on Retourne 'D'  */
}
