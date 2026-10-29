#include "utils.h"
#include "menu.h"

int main(void)
{
    init_console();
    afficher_menu();
    return 0;
}

// gcc -Wall -Wextra -std=c99 main.c grille.c jeu.c menu.c mode_2j.c utils.c victoire.c -o main.exe
// .\main.exe