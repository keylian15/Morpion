#include "partie.h"
#include "grille.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "sauvegarde.h"

/* Initialise une nouvelle partie et cree son fichier de sauvegarde.
 * Retourne : 0 = ok, -1 = erreur (id impossible, dossier ou fichier non cree) */
int initialiser_partie(Partie *p, char j1, char j2, const char *mode)
{
    // Etape 1 : Initialiser la structure Partie
    memset(p, 0, sizeof(*p)); /* nb_coups = 0, coups[] et id a zero */
    p->etat = 3;
    p->j1 = j1;
    p->j2 = j2;
    snprintf(p->mode, sizeof(p->mode), "%s", mode);

    // Etape 2 : Initialiser la grille
    initialiser_grille();

    // Etape 3 : Créer un identifiant unique pour la partie
    if (generer_id(p->id, sizeof(p->id)) != 0)
    {
        p->id[0] = '\0'; /* pas d'id = pas de sauvegarde */
        return -1;
    }

    // Etape 4 : Sauvegarder la partie
    return sauvegarder_partie(p);
}