
Mode Facile : L'IA purement aléatoire

L'IA joue de manière totalement imprévisible et ne cherche ni à gagner ni à bloquer le joueur.
• Type d'IA : Algorithme de choix aléatoire (Random).
• Fonctionnement : L'IA liste toutes les cases vides disponibles et en choisit une au hasard.

Mode Medium : L'IA semi-intelligente (Heuristique)

L'IA commence à comprendre les règles de base mais fait encore des erreurs flagrantes.
• Type d'IA : Algorithme à base de règles (Heuristique) ou Minimax bridé.
• Fonctionnement :
	1. Si l'IA peut gagner en un coup, elle le fait.
	2. Si le joueur est sur le point de gagner au coup suivant, l'IA le bloque.
	3. Sinon, elle joue un coup aléatoire.

Mode Difficile : L'IA probabiliste

L'IA joue très bien la plupart du temps, mais commet parfois une erreur qui laisse une chance au joueur humain.
• Type d'IA : Algorithme Minimax avec un taux d'erreur (Probability-based Minimax).
• Fonctionnement : On introduit un facteur de probabilité (ex: 70% de chances de faire le meilleur coup, 30% de faire un coup aléatoire). Une autre méthode consiste à limiter la profondeur de calcul du Minimax (ne regarder que 2 coups à l'avance).

Mode expert : L'IA invincible

Il est mathématiquement impossible de battre cette IA. Si vous jouez parfaitement, la partie se terminera obligatoirement par un match nul.
• Type d'IA : Algorithme Minimax complet.
• Fonctionnement : L'IA simule l'intégralité des configurations possibles du jeu jusqu'à la fin de la partie. Elle attribue un score à chaque scénario (Victoire = +10, Défaite = -10, Nul = 0) et choisit systématiquement le coup qui maximise ses chances de gagner et minimise celles du joueur. Le morpion n'ayant que 255 168 combinaisons possibles, le calcul est instantané pour un ordinateur moderne.
