#ifndef _HEADER_CALCUL
#define _HEADER_CALCUL

#include "types.h"
#include "..\listes_chainees\ll_series_murs.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_les.h"

void calcul_les(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux);
void calcul_pans_coupes(LL_SERIE_MURS *liste_series_murs);

#endif
