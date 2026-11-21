#include "IA.h"
#include "grille.h"
#include <stdlib.h>
#include <time.h>

void jouer_ia_facile(char symbole) {
    int cases_vides[TAILLE_GRILLE * TAILLE_GRILLE];
    int nombre_cases_vides = 0;

    /* Initialise une fois le hasard pour les choix de l'IA. */
    static int graines_initialisee = 0;
    if (!graines_initialisee) {
        srand((unsigned int)time(NULL));
        graines_initialisee = 1;
    }

    // Parcourir la grille pour trouver les cases vides
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
            if (grille[ligne][colonne] == ' ')
                cases_vides[nombre_cases_vides++] = ligne * TAILLE_GRILLE + colonne;
        }
    }

    if (nombre_cases_vides == 0)
        return;
    // Choisir une case vide aléatoire
    int choix = rand() % nombre_cases_vides;
    // Convertir l'index choisi en coordonnées de ligne et de colonne
    int ligne = cases_vides[choix] / TAILLE_GRILLE;
    int colonne = cases_vides[choix] % TAILLE_GRILLE;  
    grille[ligne][colonne] = symbole;
}

void jouer_ia_moyenne(char symbole) {
    char symbole_joueur = (symbole == 'X') ? 'O' : 'X';
    int coup_gagnant = -1;

    /* Niveau moyen : il commet parfois une erreur et joue au hasard. */
    if (rand() % 100 < 45) {
        jouer_ia_facile(symbole);
        return;
    }

    /* 1. Teste chaque case vide pour trouver une victoire immediate. */
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
            if (grille[ligne][colonne] == ' ') {
                grille[ligne][colonne] = symbole;

                int gagnant =
                    (grille[0][0] == symbole && grille[0][1] == symbole && grille[0][2] == symbole) ||
                    (grille[1][0] == symbole && grille[1][1] == symbole && grille[1][2] == symbole) ||
                    (grille[2][0] == symbole && grille[2][1] == symbole && grille[2][2] == symbole) ||
                    (grille[0][0] == symbole && grille[1][0] == symbole && grille[2][0] == symbole) ||
                    (grille[0][1] == symbole && grille[1][1] == symbole && grille[2][1] == symbole) ||
                    (grille[0][2] == symbole && grille[1][2] == symbole && grille[2][2] == symbole) ||
                    (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole) ||
                    (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole);

                grille[ligne][colonne] = ' ';
                if (gagnant)
                    coup_gagnant = ligne * TAILLE_GRILLE + colonne;

                if (coup_gagnant != -1)
                    break;
            }
        }
        if (coup_gagnant != -1)
            break;
    }

    if (coup_gagnant != -1) {
        grille[coup_gagnant / TAILLE_GRILLE][coup_gagnant % TAILLE_GRILLE] = symbole;
        return;
    }

    /* 2. Si aucune victoire immediate n'est possible, bloque le joueur. */
    for (int ligne = 0; ligne < TAILLE_GRILLE; ligne++) {
        for (int colonne = 0; colonne < TAILLE_GRILLE; colonne++) {
            if (grille[ligne][colonne] == ' ') {
                grille[ligne][colonne] = symbole_joueur;

                int gagnant =
                    (grille[0][0] == symbole_joueur && grille[0][1] == symbole_joueur && grille[0][2] == symbole_joueur) ||
                    (grille[1][0] == symbole_joueur && grille[1][1] == symbole_joueur && grille[1][2] == symbole_joueur) ||
                    (grille[2][0] == symbole_joueur && grille[2][1] == symbole_joueur && grille[2][2] == symbole_joueur) ||
                    (grille[0][0] == symbole_joueur && grille[1][0] == symbole_joueur && grille[2][0] == symbole_joueur) ||
                    (grille[0][1] == symbole_joueur && grille[1][1] == symbole_joueur && grille[2][1] == symbole_joueur) ||
                    (grille[0][2] == symbole_joueur && grille[1][2] == symbole_joueur && grille[2][2] == symbole_joueur) ||
                    (grille[0][0] == symbole_joueur && grille[1][1] == symbole_joueur && grille[2][2] == symbole_joueur) ||
                    (grille[0][2] == symbole_joueur && grille[1][1] == symbole_joueur && grille[2][0] == symbole_joueur);

                grille[ligne][colonne] = ' ';
                if (gagnant) {
                    grille[ligne][colonne] = symbole;
                    return;
                }
            }
        }
    }

    /* 3. Sinon, choisit une case vide au hasard comme en mode facile. */
    jouer_ia_facile(symbole);
}


void jouer_ia_difficile(char symbole) {
    // Implémentation de l'IA difficile
}

void jouer_ia_expert(char symbole) {
    // Implémentation de l'IA expert
}