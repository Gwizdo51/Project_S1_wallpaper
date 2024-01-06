#include "..\logiciel\types.h"
#include "..\listes_chainees\ll_float.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_les.h"
#include "..\listes_chainees\ll_series_murs.h"
#include "..\listes_chainees\ll_obstacles.h"
#include "..\listes_chainees\ll_rouleaux.h"

int main() {
    LL_FLOAT list_float;
    LL_MUR list_murs;
    MUR mur_temp;
    LL_SERIE_MURS list_series_murs;
    SERIE_MURS serie_murs_temp;
    LL_LE list_les;
    LE le_temp;
    LL_OBSTACLE list_obstacles;
    OBSTACLE obstacle_temp;
    LL_ROULEAU list_rouleaux;
    ROULEAU rouleau_temp;
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
    mur_temp.liste_les = lll_create();
    mur_temp.liste_obstacles = llo_create();
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


    printf("\nTests linked lists d'obstacles\n\n");

    printf("cree une liste vide\n");
    list_obstacles = llo_create();
    printf("llo_length(&list_obstacles) = %d\n", llo_length(&list_obstacles));
    printf("\n");

    printf("ajoute des obstacles a la liste\n");
    obstacle_temp.X = 0.;
    obstacle_temp.Y = 1.5;
    llo_append(&list_obstacles, obstacle_temp);
    obstacle_temp.X = 10.2;
    obstacle_temp.Y = 7.5;
    llo_append(&list_obstacles, obstacle_temp);
    obstacle_temp.X = 5.4;
    obstacle_temp.Y = 8.1;
    llo_append(&list_obstacles, obstacle_temp);
    printf("llo_length(&list_obstacles) = %d\n", llo_length(&list_obstacles));
    printf("\n");

    printf("accede aux elements de la liste\n");
    index = 0;
    printf("list_obstacles[%d].X = %.2f\n", index, (llo_get(&list_obstacles, index))->X);
    printf("list_obstacles[%d].Y = %.2f\n", index, (llo_get(&list_obstacles, index))->Y);
    index = 1;
    printf("list_obstacles[%d].X = %.2f\n", index, (llo_get(&list_obstacles, index))->X);
    printf("list_obstacles[%d].Y = %.2f\n", index, (llo_get(&list_obstacles, index))->Y);
    index = 2;
    printf("list_obstacles[%d].X = %.2f\n", index, (llo_get(&list_obstacles, index))->X);
    printf("list_obstacles[%d].Y = %.2f\n", index, (llo_get(&list_obstacles, index))->Y);
    printf("\n");

    printf("retire un element de la liste\n");
    index = 1;
    llo_remove(&list_obstacles, index);
    index = 0;
    printf("list_obstacles[%d].X = %.2f\n", index, (llo_get(&list_obstacles, index))->X);
    printf("list_obstacles[%d].Y = %.2f\n", index, (llo_get(&list_obstacles, index))->Y);
    index = 1;
    printf("list_obstacles[%d].X = %.2f\n", index, (llo_get(&list_obstacles, index))->X);
    printf("list_obstacles[%d].Y = %.2f\n", index, (llo_get(&list_obstacles, index))->Y);
    printf("llo_length(&list_obstacles) = %d\n", llo_length(&list_obstacles));
    printf("\n");

    printf("supprime le contenu de la liste\n");
    llo_free(&list_obstacles);
    printf("llo_length(&list_obstacles) = %d\n", llo_length(&list_obstacles));
    printf("\n");


    printf("\nTests linked lists de rouleaux\n\n");

    printf("cree une liste vide\n");
    list_rouleaux = llr_create();
    printf("llr_length(&list_rouleaux) = %d\n", llr_length(&list_rouleaux));
    printf("\n");

    printf("ajoute des rouleaux a la liste\n");
    rouleau_temp.liste_chutes = llf_create();
    rouleau_temp.longueur = 7.1;
    rouleau_temp.largeur = 5.0;
    llr_append(&list_rouleaux, rouleau_temp);
    rouleau_temp.longueur = 1.7;
    rouleau_temp.largeur = 10.2;
    llr_append(&list_rouleaux, rouleau_temp);
    rouleau_temp.longueur = 4.2;
    rouleau_temp.largeur = 5.4;
    llr_append(&list_rouleaux, rouleau_temp);
    printf("llr_length(&list_rouleaux) = %d\n", llr_length(&list_rouleaux));
    printf("\n");

    printf("accede aux elements de la liste\n");
    index = 0;
    printf("list_rouleaux[%d].longueur = %.2f\n", index, (llr_get(&list_rouleaux, index))->longueur);
    printf("list_rouleaux[%d].largeur = %.2f\n", index, (llr_get(&list_rouleaux, index))->largeur);
    index = 1;
    printf("list_rouleaux[%d].longueur = %.2f\n", index, (llr_get(&list_rouleaux, index))->longueur);
    printf("list_rouleaux[%d].largeur = %.2f\n", index, (llr_get(&list_rouleaux, index))->largeur);
    index = 2;
    printf("list_rouleaux[%d].longueur = %.2f\n", index, (llr_get(&list_rouleaux, index))->longueur);
    printf("list_rouleaux[%d].largeur = %.2f\n", index, (llr_get(&list_rouleaux, index))->largeur);
    printf("\n");

    printf("retire un element de la liste\n");
    index = 1;
    llr_remove(&list_rouleaux, index);
    index = 0;
    printf("list_rouleaux[%d].longueur = %.2f\n", index, (llr_get(&list_rouleaux, index))->longueur);
    printf("list_rouleaux[%d].largeur = %.2f\n", index, (llr_get(&list_rouleaux, index))->largeur);
    index = 1;
    printf("list_rouleaux[%d].longueur = %.2f\n", index, (llr_get(&list_rouleaux, index))->longueur);
    printf("list_rouleaux[%d].largeur = %.2f\n", index, (llr_get(&list_rouleaux, index))->largeur);
    printf("llr_length(&list_rouleaux) = %d\n", llr_length(&list_rouleaux));
    printf("\n");

    printf("supprime le contenu de la liste\n");
    llr_free(&list_rouleaux);
    printf("llr_length(&list_rouleaux) = %d\n", llr_length(&list_rouleaux));
    printf("\n");
}
