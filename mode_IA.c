#include <stdio.h>
#include <stdbool.h>
#include "couleurs.h"
#include "grille.h"
#include "IA.h"
#include "jeu.h"
#include "partie.h"
#include "sauvegarde.h"
#include "victoire.h"

int partie_contre_ia(Partie *p, int niveau)
{
    int ligne;
    int colonne;
    bool partie_terminee = false;

    while (!partie_terminee)
    {
        /* Le joueur humain commence toujours en tant que joueur 1. */
        int tour = (p->nb_coups % 2 == 0) ? 1 : 2;
        char symbole = (tour == 1) ? p->j1 : p->j2;

        /* Tour du joueur humain : saisie et verification de la case. */
        if (tour == 1)
        {
            printf("Votre tour (symbole: %c):\n", symbole);

            while (lire_case(&ligne, &colonne) == 0)
                printf(ROUGE "Saisie invalide. Veuillez entrer un entier entre 1 et 3.\n" RESET);

            if (grille[ligne - 1][colonne - 1] != ' ')
            {
                printf(ROUGE "Case déjà occupée. Veuillez réessayer.\n" RESET);
                continue;
            }

            grille[ligne - 1][colonne - 1] = symbole;
        }
        else
        {
            printf("Tour de l'ordinateur (symbole: %c):\n", symbole);
            int coup_joue;
            if (niveau == 2)
                coup_joue = jouer_ia_moyenne(symbole, &ligne, &colonne);
            else
                coup_joue = jouer_ia_facile(symbole, &ligne, &colonne);

            /* Ne sauvegarde jamais un coup si la grille est pleine. */
            if (!coup_joue)
            {
                p->etat = verifier_reussite(grille, tour, p->nb_coups);
                if (p->id[0] != '\0')
                    sauvegarder_partie(p);
                if (p->etat != 3)
                    afficher_resultat(p->etat);
                partie_terminee = true;
                continue;
            }
        }

        p->coups[p->nb_coups++] = (Coup){tour, ligne, colonne};
        afficher_grille();

        p->etat = verifier_reussite(grille, tour, p->nb_coups);
        if (p->id[0] != '\0')
            sauvegarder_partie(p);

        if (p->etat != 3)
        {
            afficher_resultat(p->etat);
            partie_terminee = true;
        }
    }

    return 0;
}
