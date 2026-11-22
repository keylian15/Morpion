#include "IA.h"
#include "grille.h"
#include "victoire.h"
#include <stdlib.h>

void jouer_ia_facile(char symbole, int *ligne, int *colonne) {
    int cases_vides[TAILLE_GRILLE * TAILLE_GRILLE];
    int nombre_cases_vides = 0;
    *ligne = 0;
    *colonne = 0;

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
    int index = cases_vides[choix];
    int ligne_case = index / TAILLE_GRILLE;
    int colonne_case = index % TAILLE_GRILLE;
    grille[ligne_case][colonne_case] = symbole;
    *ligne = ligne_case + 1;
    *colonne = colonne_case + 1;
}

/* Teste si 'symbole' gagne en jouant sur une case vide.
 * On passe nb_coups = 9 volontairement à verifier_reussite : ça évite
 * qu'elle renvoie 3 (partie en cours). Elle renvoie alors 'tour' s'il y a
 * un alignement, 0 sinon. Ne pas "corriger" ce 9 en nb_coups réel.
 * 'tour' doit être le numéro du joueur qui possède 'symbole'
 * (1 = humain, 2 = IA), car verifier_reussite renvoie 'tour' et non
 * le symbole gagnant. */
static int trouver_coup(char symbole, int tour, int *ligne, int *colonne)
{
    for (int ligne_case = 0; ligne_case < TAILLE_GRILLE; ligne_case++) {
        for (int colonne_case = 0; colonne_case < TAILLE_GRILLE; colonne_case++) {
            if (grille[ligne_case][colonne_case] == ' ') {
                grille[ligne_case][colonne_case] = symbole;
                // On passe volontairement nb_coups = 9 pour forcer verifier_reussite à renvoyer 0 ou tour, pas partie en cours (3)
                int resultat = verifier_reussite(grille, tour, TAILLE_GRILLE * TAILLE_GRILLE);
                grille[ligne_case][colonne_case] = ' ';

                if (resultat == tour) {
                    *ligne = ligne_case + 1;
                    *colonne = colonne_case + 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void jouer_ia_moyenne(char symbole, int *ligne, int *colonne) {
    char symbole_joueur = (symbole == 'X') ? 'O' : 'X';
    *ligne = 0;
    *colonne = 0;

    /* Niveau moyen : il commet parfois une erreur et joue au hasard. */
    if (rand() % 100 < 45) {
        jouer_ia_facile(symbole, ligne, colonne);
        return;
    }

    /* 1. Teste chaque case vide pour trouver une victoire immediate. */
    if (trouver_coup(symbole, 2, ligne, colonne)) {
        grille[*ligne - 1][*colonne - 1] = symbole;
        return;
    }

    /* 2. Si aucune victoire immediate n'est possible, bloque le joueur. */
    if (trouver_coup(symbole_joueur, 1, ligne, colonne)) {
        grille[*ligne - 1][*colonne - 1] = symbole;
        return;
    }

    /* 3. Sinon, choisit une case vide au hasard comme en mode facile. */
    jouer_ia_facile(symbole, ligne, colonne);
}


void jouer_ia_difficile(char symbole) {
    // Implémentation de l'IA difficile
}

void jouer_ia_expert(char symbole) {
    // Implémentation de l'IA expert
}