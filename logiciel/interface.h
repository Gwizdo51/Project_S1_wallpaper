#ifndef _HEADER_INTERFACE
#define _HEADER_INTERFACE

#include "types.h"
#include "..\listes_chainees\ll_rouleaux.h"

void interface_rouleaux(LL_ROULEAU *liste_rouleaux);
void interface_colle(float *volume_pots);
void interface_murs(SerieMurs liste_serie_murs, Rouleau liste_rouleaux);

#endif
