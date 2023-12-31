#ifndef _HEADER_RESULTAT
#define _HEADER_RESULTAT

#include "types.h"
#include "..\listes_chainees\ll_rouleaux.h"

#define STRING_BUFFER_MAX_SIZE 256

void enregistrer_resultat(LL_ROULEAU *liste_rouleaux, float *quantite_colle, int *nombre_pots, char *nom_fichier_resultat);
void afficher_resultat(LL_ROULEAU *liste_rouleaux, float *quantite_colle, int *nombre_pots, char *nom_fichier_resultat);

#endif
