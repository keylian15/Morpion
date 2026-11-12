
#include <stdio.h>
#include <stdbool.h>
#include "couleurs.h"
#include "victoire.h"
#include "jeu.h"
#include "grille.h"
#include "partie.h"

/*fonction principal du jeu mode 2 joueurs*/

int deux_joueurs(Partie *p)
{
    int ligne, colonne;
    int tour;
    char symbole;
    bool gameover = false;

    while (!gameover)
    {
        /* J1 commence toujours : nb_coups pair -> J1, impair -> J2 */
        tour = (p->nb_coups % 2 == 0) ? 1 : 2;
        symbole = (tour == 1) ? p->j1 : p->j2;

        /* Tour du joueur 1 ou 2 */
        printf("Tour du joueur %d (symbole: %c):\n", tour, symbole);

        while (lire_case(&ligne, &colonne) == 0)
        {
            printf(ROUGE "Saisie invalide. Veuillez entrer un entier entre 1 et 3.\n" RESET);
        }

        /* On verifie que la case est vide */
        if (grille[ligne - 1][colonne - 1] != ' ')
        {
            printf(ROUGE "Case déjà occupée. Veuillez réessayer.\n" RESET);
            continue; // Recommence le tour du même joueur
        }

        grille[ligne - 1][colonne - 1] = symbole;
        // On enregistre le coup dans la partie
        p->coups[p->nb_coups++] = (Coup){tour, ligne, colonne};

        afficher_grille();

        p->etat = verifier_reussite(grille, tour, p->nb_coups);

        if (p->etat != 3)
        {
            afficher_resultat(p->etat);
            gameover = true;
        }
    }
    return 0;
}
