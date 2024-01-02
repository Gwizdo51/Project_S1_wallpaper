#include "..\logiciel\types.h"
#include "..\listes_chainees\ll_float.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_les.h"
#include "..\listes_chainees\ll_series_murs.h"

int main() {
    LL_FLOAT list_float;
    LL_MUR list_murs;
    MUR mur_temp;
    LL_SERIE_MURS list_series_murs;
    SERIE_MURS serie_murs_temp;
    LL_LE list_les;
    LE le_temp;
    float flottant;
    int index;
    printf("Tests linked lists float\n\n");

    printf("cree une liste vide\n");
    list_float = llf_create();
    printf("llf_length(&list_float) = %d\n", llf_length(&list_float));
    printf("\n");

    printf("ajoute des flottants a la liste\n");
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


    printf("\nTests linked lists murs\n\n");

    printf("cree une liste vide\n");
    list_murs = llm_create();
    printf("llm_length(&list_murs) = %d\n", llm_length(&list_murs));
    printf("\n");

    printf("ajoute des murs a la liste\n");
    mur_temp.hauteur = 10.3;
    mur_temp.largeur = 5.6;
    llm_append(&list_murs, mur_temp);
    mur_temp.hauteur = 15.0;
    mur_temp.largeur = 7.2;
    llm_append(&list_murs, mur_temp);
    mur_temp.hauteur = 32.5;
    mur_temp.largeur = 5.1;
    llm_append(&list_murs, mur_temp);
    printf("llm_length(&list_murs) = %d\n", llm_length(&list_murs));
    printf("\n");

    printf("accede aux elements de la liste\n");
    index = 0;
    printf("list_murs[%d].hauteur = %.2f\n", index, (llm_get(&list_murs, index))->hauteur);
    printf("list_murs[%d].largeur = %.2f\n", index, (llm_get(&list_murs, index))->largeur);
    index = 1;
    printf("list_murs[%d].hauteur = %.2f\n", index, (llm_get(&list_murs, index))->hauteur);
    printf("list_murs[%d].largeur = %.2f\n", index, (llm_get(&list_murs, index))->largeur);
    index = 2;
    printf("list_murs[%d].hauteur = %.2f\n", index, (llm_get(&list_murs, index))->hauteur);
    printf("list_murs[%d].largeur = %.2f\n", index, (llm_get(&list_murs, index))->largeur);
    printf("\n");

    printf("retire un element de la liste\n");
    index = 1;
    llm_remove(&list_murs, index);
    index = 0;
    printf("list_murs[%d].hauteur = %.2f\n", index, (llm_get(&list_murs, index))->hauteur);
    printf("list_murs[%d].largeur = %.2f\n", index, (llm_get(&list_murs, index))->largeur);
    index = 1;
    printf("list_murs[%d].hauteur = %.2f\n", index, (llm_get(&list_murs, index))->hauteur);
    printf("list_murs[%d].largeur = %.2f\n", index, (llm_get(&list_murs, index))->largeur);
    printf("llm_length(list_murs) = %d\n", llm_length(&list_murs));
    printf("\n");

    printf("supprime le contenu de la liste\n");
    llm_free(&list_murs);
    printf("llm_length(&list_murs) = %d\n", llm_length(&list_murs));
    printf("\n");


    printf("\nTests linked lists les\n\n");

    printf("cree une liste vide\n");
    list_les = lll_create();
    printf("lll_length(&list_murs) = %d\n", lll_length(&list_les));
    printf("\n");

    printf("ajoute des les a la liste\n");
    le_temp.hauteur = 10.8;
    le_temp.largeur = 28.2;
    lll_append(&list_les, le_temp);
    le_temp.hauteur = 3.5;
    le_temp.largeur = 8.197;
    lll_append(&list_les, le_temp);
    le_temp.hauteur = 4.9;
    le_temp.largeur = 25.0;
    lll_append(&list_les, le_temp);
    printf("lll_length(&list_les) = %d\n", lll_length(&list_les));
    printf("\n");

    printf("accede aux elements de la liste\n");
    index = 0;
    printf("list_les[%d].hauteur = %.2f\n", index, (lll_get(&list_les, index))->hauteur);
    printf("list_les[%d].largeur = %.2f\n", index, (lll_get(&list_les, index))->largeur);
    index = 1;
    printf("list_les[%d].hauteur = %.2f\n", index, (lll_get(&list_les, index))->hauteur);
    printf("list_les[%d].largeur = %.2f\n", index, (lll_get(&list_les, index))->largeur);
    index = 2;
    printf("list_les[%d].hauteur = %.2f\n", index, (lll_get(&list_les, index))->hauteur);
    printf("list_les[%d].largeur = %.2f\n", index, (lll_get(&list_les, index))->largeur);
    printf("\n");

    printf("retire un element de la liste\n");
    index = 1;
    lll_remove(&list_les, index);
    index = 0;
    printf("list_les[%d].hauteur = %.2f\n", index, (lll_get(&list_les, index))->hauteur);
    printf("list_les[%d].largeur = %.2f\n", index, (lll_get(&list_les, index))->largeur);
    index = 1;
    printf("list_les[%d].hauteur = %.2f\n", index, (lll_get(&list_les, index))->hauteur);
    printf("list_les[%d].largeur = %.2f\n", index, (lll_get(&list_les, index))->largeur);
    printf("lll_length(&list_les) = %d\n", lll_length(&list_les));
    printf("\n");

    printf("supprime le contenu de la liste\n");
    lll_free(&list_les);
    printf("lll_length(&list_les) = %d\n", lll_length(&list_les));
    printf("\n");


    printf("\nTests linked lists series de murs\n\n");

    printf("cree une liste vide\n");
    list_series_murs = llsm_create();
    printf("llsm_length(&list_series_murs) = %d\n", llsm_length(&list_series_murs));
    printf("\n");

    printf("ajoute des series de murs a la liste\n");
    serie_murs_temp.liste_murs = llm_create();
    serie_murs_temp.type_papier_peint = 0;
    llsm_append(&list_series_murs, serie_murs_temp);
    serie_murs_temp.type_papier_peint = 1;
    llsm_append(&list_series_murs, serie_murs_temp);
    serie_murs_temp.type_papier_peint = 2;
    llsm_append(&list_series_murs, serie_murs_temp);
    printf("llsm_length(&list_series_murs) = %d\n", llsm_length(&list_series_murs));
    printf("\n");

    printf("accede aux elements de la liste\n");
    index = 0;
    printf("list_series_murs[%d].type_papier_peint = %d\n", index, (llsm_get(&list_series_murs, index))->type_papier_peint);
    index = 1;
    printf("list_series_murs[%d].type_papier_peint = %d\n", index, (llsm_get(&list_series_murs, index))->type_papier_peint);
    index = 2;
    printf("list_series_murs[%d].type_papier_peint = %d\n", index, (llsm_get(&list_series_murs, index))->type_papier_peint);
    printf("\n");

    printf("retire un element de la liste\n");
    index = 1;
    llsm_remove(&list_series_murs, index);
    index = 0;
    printf("list_series_murs[%d].type_papier_peint = %d\n", index, (llsm_get(&list_series_murs, index))->type_papier_peint);
    index = 1;
    printf("list_series_murs[%d].type_papier_peint = %d\n", index, (llsm_get(&list_series_murs, index))->type_papier_peint);
    printf("llsm_length(&list_series_murs) = %d\n", llsm_length(&list_series_murs));
    printf("\n");

    printf("supprime le contenu de la liste\n");
    llsm_free(&list_series_murs);
    printf("llsm_length(&list_series_murs) = %d\n", llsm_length(&list_series_murs));
    printf("\n");
}
