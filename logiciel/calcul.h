#ifndef _HEADER_CALCUL
#define _HEADER_CALCUL

#include "types.h"
#include "..\listes_chainees\ll_series_murs.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_obstacles.h"

void calcul_les(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux);
void calcul_pans_coupes(LL_SERIE_MURS *liste_series_murs);
void calcul_colle(LL_SERIE_MURS_NODE *liste_series_murs, float *quantite_colle, float *volume_pots, int *nombre_pots);

#endif
