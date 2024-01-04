#ifndef _HEADER_LL_ROULEAU
#define _HEADER_LL_ROULEAU
#include "..\logiciel\types.h"

LL_ROULEAU llr_create();
int llr_length(LL_ROULEAU *linked_list);
void llr_append(LL_ROULEAU *linked_list, float new_data);
float *llr_get(LL_ROULEAU *linked_list, int index);
void llr_remove(LL_ROULEAU *linked_list, int index);
void llr_free(LL_ROULEAU *linked_list);

#endif