#ifndef _HEADER_LL_FLOAT
#define _HEADER_LL_FLOAT

#include "..\logiciel\types.h"

LL_FLOAT llf_create();
int llf_length(LL_FLOAT *linked_list);
void llf_append(LL_FLOAT *linked_list, float new_data);
float *llf_get(LL_FLOAT *linked_list, int index);
void llf_remove(LL_FLOAT *linked_list, int index);
void llf_free(LL_FLOAT *linked_list);

#endif
