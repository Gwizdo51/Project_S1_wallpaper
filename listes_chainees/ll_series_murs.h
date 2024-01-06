#ifndef _HEADER_LL_SERIE_MURS
#define _HEADER_LL_SERIE_MURS

#include "..\logiciel\types.h"
#include "ll_murs.h"

LL_SERIE_MURS llsm_create();
int llsm_length(LL_SERIE_MURS *linked_list);
void llsm_append(LL_SERIE_MURS *linked_list, SERIE_MURS new_data);
SERIE_MURS *llsm_get(LL_SERIE_MURS *linked_list, int index);
void llsm_remove(LL_SERIE_MURS *linked_list, int index);
void llsm_free(LL_SERIE_MURS *linked_list);

#endif
