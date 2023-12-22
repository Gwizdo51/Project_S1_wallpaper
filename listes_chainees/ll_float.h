#ifndef _HEADER_LL_FLOAT
#define _HEADER_LL_FLOAT

#include "..\logiciel\types.h"

LL_FLOAT llf_creer();
int llf_longueur(LL_FLOAT *linked_list);
void llf_ajouter(LL_FLOAT *linked_list, float new_data);
float *llf_obtenir(LL_FLOAT *linked_list, int index);
void llf_retirer(LL_FLOAT *linked_list, int index);
void llf_free(LL_FLOAT *linked_list);

#endif
