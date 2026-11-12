
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

/* Retourne : 1 ou 2 = victoire du joueur correspondant, 0 = match nul (grille pleine, pas de gagnant),3= partie en cours */
int verifier_reussite(char board[3][3], int tour, int nb_coups)
{
    for (int i = 0; i < 3; i++)
    {
        /* Lignes */
        if (ligne_gagnante(board[i][0], board[i][1], board[i][2]))
            return tour; /* numero du joueur gagnant */

        /* Colonnes */
        if (ligne_gagnante(board[0][i], board[1][i], board[2][i]))
            return tour;
    }

    /* Diagonales */
    if (ligne_gagnante(board[0][0], board[1][1], board[2][2]))
        return tour;
    if (ligne_gagnante(board[0][2], board[1][1], board[2][0]))
        return tour;

    /* Pas de gagnant : nul si la grille est pleine (9 coups), sinon on continue */
    return (nb_coups < 9) ? 3 : 0;
}