#ifndef IA_H
#define IA_H

#include "partie.h"

int jouer_ia_facile(char symbole, int *ligne, int *colonne);
int jouer_ia_moyenne(char symbole, int *ligne, int *colonne);
void jouer_ia_difficile(char symbole);
void jouer_ia_expert(char symbole);
#endif 