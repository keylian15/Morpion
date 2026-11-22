#include "utils.h"
#include "menu.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
    init_console();
    srand((unsigned int)time(NULL));
    afficher_menu();
    return 0;
}

// gcc -Wall -Wextra -std=c99 main.c grille.c jeu.c menu.c mode_2j.c utils.c victoire.c -o main.exe
// .\main.exe