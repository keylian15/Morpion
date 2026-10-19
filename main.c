#include "utils.h"
#include "menu.h"

int main(void)
{
    init_console();
    afficher_menu();
    return 0;
}

// gcc -Wall -Wextra -std=c99 main.c menu.c jeu.c utils.c -o main.exe
// .\main.exe