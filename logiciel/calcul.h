#ifndef _HEADER_CALCUL
#define _HEADER_CALCUL

#include "types.h"
#include "..\listes_chainees\ll_series_murs.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_les.h"

void calcul_colle(LL_SERIE_MURS_NODE liste_series_murs, float *volume_pots, float *quantite_colle, int nombre_pots)
void calcul_pans_coupes(LL_SERIE_MURS *liste_series_murs);

#endif