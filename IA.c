#include "IA.h"
#include "grille.h"
#include "victoire.h"
#include <stdlib.h>

int jouer_ia_facile(char symbole, int *ligne, int *colonne) {
    int cases_vides[TAILLE_GRILLE * TAILLE_GRILLE];
    int nombre_cases_vides = 0;

    // Parcourir la grille pour trouver les cases vides
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
            if (grille[ligne][colonne] == ' ')
                cases_vides[nombre_cases_vides++] = ligne * TAILLE_GRILLE + colonne;
        }
    }

    if (nombre_cases_vides == 0)
        return 0;
    // Choisir une case vide aléatoire
    int choix = rand() % nombre_cases_vides;
    // Convertir l'index choisi en coordonnées de ligne et de colonne
    int index = cases_vides[choix];
    int ligne_case = index / TAILLE_GRILLE;
    int colonne_case = index % TAILLE_GRILLE;
    grille[ligne_case][colonne_case] = symbole;
    *ligne = ligne_case + 1;
    *colonne = colonne_case + 1;
    return 1;
}

static int trouver_coup(char symbole, int tour)
{
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
            if (grille[ligne][colonne] == ' ') {
                grille[ligne][colonne] = symbole;
                int resultat = verifier_reussite(grille, tour, TAILLE_GRILLE * TAILLE_GRILLE);
                grille[ligne][colonne] = ' ';

                if (resultat == tour)
                    return ligne * TAILLE_GRILLE + colonne;
            }
        }
    }
    return -1;
}

int jouer_ia_moyenne(char symbole, int *ligne, int *colonne) {
    char symbole_joueur = (symbole == 'X') ? 'O' : 'X';

    /* Niveau moyen : il commet parfois une erreur et joue au hasard. */
    if (rand() % 100 < 45) {
        return jouer_ia_facile(symbole, ligne, colonne);
    }

    /* 1. Teste chaque case vide pour trouver une victoire immediate. */
    int coup = trouver_coup(symbole, 2);
    if (coup != -1) {
        grille[coup / TAILLE_GRILLE][coup % TAILLE_GRILLE] = symbole;
        *ligne = coup / TAILLE_GRILLE + 1;
        *colonne = coup % TAILLE_GRILLE + 1;
        return 1;
    }

    /* 2. Si aucune victoire immediate n'est possible, bloque le joueur. */
    coup = trouver_coup(symbole_joueur, 1);
    if (coup != -1) {
        grille[coup / TAILLE_GRILLE][coup % TAILLE_GRILLE] = symbole;
        *ligne = coup / TAILLE_GRILLE + 1;
        *colonne = coup % TAILLE_GRILLE + 1;
        return 1;
    }

    /* 3. Sinon, choisit une case vide au hasard comme en mode facile. */
    return jouer_ia_facile(symbole, ligne, colonne);
}


void jouer_ia_difficile(char symbole) {
    // Implémentation de l'IA difficile
}

void jouer_ia_expert(char symbole) {
    // Implémentation de l'IA expert
}