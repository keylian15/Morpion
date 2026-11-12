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

#define CHARGER_OK 0
#define CHARGER_ABSENT -1   /* aucun fichier / dossier */
#define CHARGER_CORROMPU -2 /* fichier illisible ou incoherent */

/* Cherche l'id de la partie la plus recente dans saves/.
 * Retourne : 0 = ok (id rempli), -1 = aucune partie trouvee */
int derniere_partie(char *id, size_t taille);

/* Charge une partie depuis saves/<id>.txt (id == NULL : la derniere).
 * Rejoue les coups : apres un chargement reussi, la grille globale est
 * reconstruite et p->etat recalcule.
 * Retourne : CHARGER_OK, CHARGER_ABSENT ou CHARGER_CORROMPU */
int charger_partie(const char *id, Partie *p);

#endif