#include "..\logiciel\types.h"
#include "..\listes_chainees\ll_float.h"

int main() {
    LL_FLOAT list_float;
    float flottant;
    int index;
    printf("Tests linked lists float\n\n");

    printf("cree une liste vide\n");
    list_float = llf_create();
    printf("\n");

    printf("ajoute des flottants à la liste\n");
    flottant = 1.2;
    printf("flottant = %.2f\n", flottant);
    llf_append(&list_float, flottant);
    flottant = -5.18;
    printf("flottant = %.2f\n", flottant);
    llf_append(&list_float, flottant);
    flottant = 17.3;
    printf("flottant = %.2f\n", flottant);
    llf_append(&list_float, flottant);
    printf("llf_length(&list_float) = %d\n", llf_length(&list_float));
    printf("\n");

    printf("accede aux elements de la liste\n");
    index = 0;
    printf("list_float[%d] = %.2f\n", index, *llf_get(&list_float, index));
    index = 1;
    printf("list_float[%d] = %.2f\n", index, *llf_get(&list_float, index));
    index = 2;
    printf("list_float[%d] = %.2f\n", index, *llf_get(&list_float, index));
    printf("\n");

    printf("retire un element de la liste\n");
    index = 1;
    llf_remove(&list_float, index);
    index = 0;
    printf("list_float[%d] = %.2f\n", index, *llf_get(&list_float, index));
    index = 1;
    printf("list_float[%d] = %.2f\n", index, *llf_get(&list_float, index));
    printf("llf_length(list_float) = %d\n", llf_length(&list_float));
    printf("\n");

    printf("supprime le contenu de la liste\n");
    llf_free(&list_float);
    printf("llf_length(&list_float) = %d\n", llf_length(&list_float));
    printf("\n");
}
