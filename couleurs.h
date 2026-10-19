#ifndef COULEURS_H
#define COULEURS_H

/* ============================================================
 * couleurs.h : codes d'échappement ANSI pour le terminal
 *
 * Usage : printf(ROUGE "texte" RESET "\n");
 * Combiner : printf(GRAS ROUGE FOND_BLANC "texte" RESET "\n");
 * Toujours finir par RESET, sinon le style reste actif.
 * ============================================================ */

/* ---------- Reset ---------- */
#define RESET "\033[0m"

/* ---------- Styles ---------- */
#define GRAS "\033[1m"
#define FAIBLE "\033[2m"   /* texte atténué */
#define ITALIQUE "\033[3m" /* pas supporté partout */
#define SOULIGNE "\033[4m"
#define CLIGNOTANT "\033[5m" /* pas supporté partout */
#define INVERSE "\033[7m"    /* échange texte / fond */
#define CACHE "\033[8m"      /* texte invisible */
#define BARRE "\033[9m"      /* texte barré */

/* ---------- Couleurs du texte (normales) ---------- */
#define NOIR "\033[30m"
#define ROUGE "\033[31m"
#define VERT "\033[32m"
#define JAUNE "\033[33m"
#define BLEU "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BLANC "\033[37m"

/* ---------- Couleurs du texte (claires) ---------- */
#define GRIS "\033[90m" /* noir clair */
#define ROUGE_CLAIR "\033[91m"
#define VERT_CLAIR "\033[92m"
#define JAUNE_CLAIR "\033[93m"
#define BLEU_CLAIR "\033[94m"
#define MAGENTA_CLAIR "\033[95m"
#define CYAN_CLAIR "\033[96m"
#define BLANC_CLAIR "\033[97m"

/* ---------- Couleurs de fond (normales) ---------- */
#define FOND_NOIR "\033[40m"
#define FOND_ROUGE "\033[41m"
#define FOND_VERT "\033[42m"
#define FOND_JAUNE "\033[43m"
#define FOND_BLEU "\033[44m"
#define FOND_MAGENTA "\033[45m"
#define FOND_CYAN "\033[46m"
#define FOND_BLANC "\033[47m"

/* ---------- Couleurs de fond (claires) ---------- */
#define FOND_GRIS "\033[100m"
#define FOND_ROUGE_CLAIR "\033[101m"
#define FOND_VERT_CLAIR "\033[102m"
#define FOND_JAUNE_CLAIR "\033[103m"
#define FOND_BLEU_CLAIR "\033[104m"
#define FOND_MAGENTA_CLAIR "\033[105m"
#define FOND_CYAN_CLAIR "\033[106m"
#define FOND_BLANC_CLAIR "\033[107m"

/* ---------- Couleurs 256 et RGB (macros) ----------
 * COULEUR_256(n)   : n de 0 à 255
 * FOND_256(n)      : idem pour le fond
 * COULEUR_RGB(r,g,b) / FOND_RGB(r,g,b) : valeurs de 0 à 255
 */
#define COULEUR_256(n) "\033[38;5;" #n "m"
#define FOND_256(n) "\033[48;5;" #n "m"
#define COULEUR_RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
#define FOND_RGB(r, g, b) "\033[48;2;" #r ";" #g ";" #b "m"

/* ---------- Contrôle du curseur / écran ---------- */
#define EFFACER_ECRAN "\033[2J\033[H" /* efface tout + curseur en haut à gauche */
#define EFFACER_LIGNE "\033[2K\r"
#define EFFACER_HISTORIQUE "\033[3J"
#define CURSEUR_CACHE "\033[?25l"
#define CURSEUR_VISIBLE "\033[?25h"

#endif /* COULEURS_H */
