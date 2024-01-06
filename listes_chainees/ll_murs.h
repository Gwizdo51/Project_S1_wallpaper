#ifndef _HEADER_LL_MURS
#define _HEADER_LL_MURS

#include "..\logiciel\types.h"
#include "ll_les.h"
#include "ll_obstacles.h"

LL_MUR llm_create();
int llm_length(LL_MUR *linked_list);
void llm_append(LL_MUR *linked_list, MUR new_data);
MUR *llm_get(LL_MUR *linked_list, int index);
void llm_remove(LL_MUR *linked_list, int index);
void llm_free(LL_MUR *linked_list);

#endif
