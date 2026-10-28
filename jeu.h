/* jeu.h */
#ifndef JEU_H
#define JEU_H

int  lire_case(int *ligne, int *colonne);
void quitter_jeu(void);
int deux_joueurs(void);
char verifier_reussite(char board[3][3]);
void afficher_resultat(char result);
int afficherGrill(void);
#endif