
#include <stdio.h>

#include <stdbool.h>

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
            return board[i][0]; /* Retourne le symbole du joueur gagnant */
        }
        /* Vérification des colonnes */
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
        {
            return board[0][i]; /* Retourne le symbole du joueur gagnant */
        }

        /* Vérification des diagonales */
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
        {
            return board[0][0]; /* Retourne le symbole du joueur gagnant */
        }
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
        {
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
