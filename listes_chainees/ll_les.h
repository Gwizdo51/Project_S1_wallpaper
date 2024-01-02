#ifndef _HEADER_LL_LES
#define _HEADER_LL_LES

#include "..\logiciel\types.h"

LL_LE lll_create();
int lll_length(LL_LE *linked_list);
void lll_append(LL_LE *linked_list, LE new_data);
LE *lll_get(LL_LE *linked_list, int index);
void lll_remove(LL_LE *linked_list, int index);
void lll_free(LL_LE *linked_list);

#endif
