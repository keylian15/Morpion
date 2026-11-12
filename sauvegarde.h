#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <stddef.h>
#include "partie.h"

/* Genere un id unique "AAAAMMJJ_HHMMSS" (suffixe _2, _3... si le fichier existe)
 * et cree le dossier saves/ si besoin.
 * Retourne : 0 = ok, -1 = erreur */
int generer_id(char *id, size_t taille);

/* Reecrit saves/<id>.txt a partir de la partie.
 * Retourne : 0 = ok, -1 = erreur (id vide, fichier non ouvert ou ecriture echouee) */
int sauvegarder_partie(const Partie *p);

#endif