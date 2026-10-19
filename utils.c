#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>

// ========== Fonctions utilitaires ==========

/* Fonction pour vider la ligne, jette les caractères jusqu'au prochain retour à la ligne */
static void vider_ligne(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

/* Affiche un message et demande un entier a l'utilisateur et le stocke dans *val.
 * Retourne 1 si la saisie est valide, 0 sinon (saisie invalide ou fin d'entree). */
int lire_int(const char *msg, int *val)
{
    printf("%s", msg); /* affiche le message */

    /* scanf retourne le nombre de conversions reussies :
     * 1 = entier lu ; 0 = texte non numerique ; EOF = fin de l'entree. */
    if (scanf("%d", val) != 1)
    {
        /* Saisie invalide : on jette la ligne fautive pour ne pas
         * relire la meme erreur au prochain appel.
         * Si on est en fin d'entree (EOF), il n'y a rien a vider. */
        if (!feof(stdin))
            vider_ligne();
        return 0;
    }

    vider_ligne();
    return 1;
}

/* Initialise la console pour permettre l'affichage des couleurs ANSI sur Windows ainsi que les caractères spéciaux */
void init_console(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); /* accents en UTF-8 */

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    if (h != INVALID_HANDLE_VALUE && GetConsoleMode(h, &mode))
        SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING); /* couleurs ANSI */
#endif
}
