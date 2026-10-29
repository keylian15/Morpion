#include <stdio.h>
#include "couleurs.h"
#include "utils.h"
#include "jeu.h"
#include "grille.h"
#include "mode_2j.h"

void help_and_rules(void)
{
    printf("\n");
    printf(GRAS CYAN "╔══════════════════════════════════════════════╗" RESET "\n");
    printf(GRAS CYAN "║" RESET GRAS BLANC_CLAIR "               MORPION : AIDE                 " RESET GRAS CYAN "║" RESET "\n");
    printf(GRAS CYAN "╚══════════════════════════════════════════════╝" RESET "\n\n");

    /* ---------- Aide ---------- */
    printf(GRAS JAUNE "  [ AIDE ]" RESET "\n");
    printf("  " VERT_CLAIR "•" RESET " Les saisies se font entre " GRAS VERT_CLAIR "1" RESET " et " GRAS VERT_CLAIR "3" RESET ".\n");
    printf("  " MAGENTA_CLAIR "•" RESET " Personnalisation " GRAS MAGENTA_CLAIR "5" RESET " du menu : " GRAS "couleurs" RESET " et " GRAS "symboles" RESET ".\n");
    printf("  " ROUGE_CLAIR "•" RESET " Tape " GRAS ROUGE_CLAIR "7" RESET " pour " GRAS "quitter" RESET " la partie.\n\n");

    /* ---------- Modes de jeu ---------- */
    printf(GRAS JAUNE "  [ MODES DE JEU ]" RESET "\n");
    printf("  " VERT_CLAIR "•" RESET " " GRAS "1 vs 1" RESET "   : deux joueurs s'affrontent.\n");
    printf("  " VERT_CLAIR "•" RESET " " GRAS "1 vs Ordi" RESET " : tu affrontes l'ordinateur.\n\n");

    /* ---------- Règles ---------- */
    printf(GRAS JAUNE "  [ RÈGLES ]" RESET "\n");
    printf("  " CYAN_CLAIR "1." RESET " Le jeu se joue sur une grille de " GRAS "3x3" RESET ".\n");
    printf("  " CYAN_CLAIR "2." RESET " Chaque joueur a un symbole (par défaut " GRAS ROUGE_CLAIR "X" RESET " et " GRAS BLEU_CLAIR "O" RESET ").\n");
    printf("  " CYAN_CLAIR "3." RESET " Chacun son tour, on place son symbole dans une case " GRAS "vide" RESET ".\n");
    printf("  " CYAN_CLAIR "4." RESET " Le premier qui aligne " GRAS "3 symboles" RESET " gagne : en " GRAS "ligne" RESET ",\n");
    printf("     en " GRAS "colonne" RESET " ou en " GRAS "diagonale" RESET ".\n");
    printf("  " CYAN_CLAIR "5." RESET " Si la grille est pleine sans alignement : " GRAS JAUNE_CLAIR "match nul" RESET ".\n\n");

    printf(FAIBLE GRIS "  ────────────────────────────────────────────" RESET "\n");
    printf(ITALIQUE GRIS "  Bonne partie !" RESET "\n\n");
}

/* Affiche le menu principal et gère les choix de l'utilisateur */
void afficher_menu(void)
{
    int choix = 0;
    const char *message =
        "\n" GRAS CYAN "╔══════════════════════════════════════════════╗" RESET "\n" GRAS CYAN "║" RESET GRAS BLANC_CLAIR "                   MORPION                    " RESET GRAS CYAN "║" RESET "\n" GRAS CYAN "╚══════════════════════════════════════════════╝" RESET "\n\n"
        "  " GRAS CYAN "1." RESET " Nouvelle partie\n"
        "  " GRAS CYAN "2." RESET " Charger une partie sauvegardée\n"
        "  " GRAS CYAN "3." RESET " Re-visualiser une partie terminée\n"
        "  " GRAS CYAN "4." RESET " Statistiques\n"
        "  " GRAS CYAN "5." RESET " Options et personnalisation\n"
        "  " GRAS CYAN "6." RESET " Aide et règles\n"
        "  " GRAS CYAN "7." RESET " Quitter " FAIBLE GRIS "(valable à tout moment)" RESET "\n\n" GRAS CYAN "Choix : " RESET;

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
            deux_joueurs('X', 'O');
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
            help_and_rules();
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
