#include <stdio.h>
#include "couleurs.h"
#include "utils.h"
#include "jeu.h"
#include "grille.h"

/* Affiche le menu principal et gère les choix de l'utilisateur */
void afficher_menu(void)
{
    int choix = 0;
    const char *message = "\n1. Nouvelle partie\n2. Charger une partie sauvegardée\n"
                          "3. Re-visualiser une partie terminée\n4. Statistiques\n"
                          "5. Options et personnalisation\n6. Aide et règles\n7. Quitter\n" GRAS "Choix : " RESET;

    while (choix != 7)
    {
        if (!lire_int(message, &choix)) // Lire le choix de l'utilisateur
        {
            if (feof(stdin)) // Fin d'entree, ctrl+D ou ctrl+Z
                break;
            printf(ROUGE "\nChoix invalide. Veuillez réessayer.\n" RESET);
            choix = 0;
            continue;
        }

        switch (choix)
        {
        case 1:
            printf("Démarrage d'une nouvelle partie...\n");
            initialiser_grille();
            afficher_grille();
            break;
        case 2:
            printf("Chargement d'une partie sauvegardée...\n");
            break;
        case 3:
            printf("Re-visualisation d'une partie terminée...\n");
            break;
        case 4:
            printf("Affichage des statistiques...\n");
            break;
        case 5:
            printf("Accès aux options et personnalisation...\n");
            break;
        case 6:
            printf("Affichage de l'aide et des règles...\n");
            break;
        case 7:
            quitter_jeu();
            break;
        default:
            printf(ROUGE "\nChoix invalide. Veuillez réessayer.\n\n" RESET);
            break;
        }
    }
}
