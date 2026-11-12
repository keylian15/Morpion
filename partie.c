#include "partie.h"
#include "grille.h"
#include <stdlib.h>

Partie* initialiser_partie(char j1, char j2)
{
    // Initialise une nouvelle partie avec les symboles des joueurs et réinitialise l'état de la partie
    Partie *p = malloc(sizeof(Partie));
    p->nb_coups = 0;
    p->etat = 3;
    p->j1 = j1;
    p->j2 = j2;

    // Initialiser la grille de jeu
    initialiser_grille();

    return p;
}