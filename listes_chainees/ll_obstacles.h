#ifndef _HEADER_LL_OBSTACLE
#define _HEADER_LL_OBSTACLE
#include "..\logiciel\types.h"

LL_OBSTACLE llo_create();
int llo_length(LL_OBSTACLE *linked_list);
void llo_append(LL_OBSTACLE *linked_list, OBSTACLE new_data);
OBSTACLE *llo_get(LL_OBSTACLE *linked_list, int index);
void llo_remove(LL_OBSTACLE *linked_list, int index);
void llo_free(LL_OBSTACLE *linked_list);

#endif