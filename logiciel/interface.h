#ifndef _HEADER_INTERFACE
#define _HEADER_INTERFACE

#include "types.h"
#include "..\listes_chainees\ll_rouleaux.h"
#include "..\listes_chainees\ll_series_murs.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_obstacles.h"

void interface_rouleaux(LL_ROULEAU *liste_rouleaux);
void interface_murs(LL_SERIE_MURS *liste_serie_murs, LL_ROULEAU *liste_rouleaux);
void interface_colle(float *volume_pots);

#endif
