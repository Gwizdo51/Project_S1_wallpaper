#include "..\logiciel\types.h"
#include "..\logiciel\interface.h"
#include "..\logiciel\calcul.h"
#include "..\listes_chainees\ll_rouleaux.h"
#include "..\listes_chainees\ll_float.h"
#include "..\listes_chainees\ll_les.h"
#include "..\listes_chainees\ll_murs.h"
#include "..\listes_chainees\ll_obstacles.h"
#include "..\listes_chainees\ll_series_murs.h"


void test_float_equality() {
    float a = .1, b = .3, left_rounded, right_rounded;
    if (b == a * 3) {
        printf("0.1 + 0.1 + 0.1 == 0.3\n");
    }
    else {
        printf("0.1 + 0.1 + 0.1 != 0.3\n");
    }
    left_rounded = roundf(b * 100) / 100;
    right_rounded = roundf((3 * a) * 100) / 100;
    if (left_rounded == right_rounded) {
        printf("round(0.1 + 0.1 + 0.1, 2) == round(0.3, 2)\n");
    }
    else {
        printf("round(0.1 + 0.1 + 0.1, 2) != round(0.3, 2)\n");
    }
    printf("b == %f, 3 * a == %f\n", b, a * 3);
}


void test_interface_rouleaux() {
    int indice_rouleau;
    ROULEAU *rouleau_pointeur;
    LL_ROULEAU liste_rouleaux = llr_create();
    interface_rouleaux(&liste_rouleaux);
    printf("nombre de rouleaux entres : %d\n\n", llr_length(&liste_rouleaux));
    for (indice_rouleau = 0; indice_rouleau < llr_length(&liste_rouleaux); indice_rouleau++) {
        rouleau_pointeur = llr_get(&liste_rouleaux, indice_rouleau);
        printf("rouleau n°%d\n", indice_rouleau);
        printf("longueur : %.2f\n", rouleau_pointeur->longueur);
        printf("largeur : %.2f\n", rouleau_pointeur->largeur);
        printf("longueur motif : %.2f\n", rouleau_pointeur->longueur_motif);
        printf("longueur restante : %.2f\n", rouleau_pointeur->longueur_restante);
        printf("quantite : %d\n", rouleau_pointeur->quantite);
        printf("longueur(liste_chutes) : %d\n", llf_length(&rouleau_pointeur->liste_chutes));
        printf("\n");
    }
}


/*
pour tester:
    1 piece, 3 murs
    mur 1 : largeur 10, hauteur 4
    pan coupé gauche 2 large 1 haut, pan coupé droit 2 large 1.5 haut
    1 obstacle 1, 1, 1, 1
    pp 0

    mur 2: largeur 15, hauteur 4.5
    pas de pans coupés
    pas d'obstacles
    pp 1

    mur 3: largeur 15, hauteur 3.75
    pas de pas coupés
    1 obstacle 1.5, 2, 0.5, 0.5
    pp 1, adjacent
*/
void test_interface_murs() {
    int indice_serie_murs, indice_mur, indice_obstacle;
    LL_ROULEAU liste_rouleaux = llr_create();
    LL_SERIE_MURS liste_series_murs = llsm_create();
    ROULEAU rouleau;
    SERIE_MURS *series_mur_pointeur;
    MUR *mur_pointeur;
    OBSTACLE *obstacle_pointeur;
    // on ajoute des rouleaux à la liste
    rouleau.longueur = 10;
    rouleau.largeur = 1;
    rouleau.longueur_motif = 0;
    llr_append(&liste_rouleaux, rouleau);
    rouleau.longueur_motif = 5;
    llr_append(&liste_rouleaux, rouleau);
    // appel interface_murs
    interface_murs(&liste_series_murs, &liste_rouleaux);
    // check des séries de murs créées
    printf("nombre de series de murs creees : %d\n\n", llsm_length(&liste_series_murs));
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(&liste_series_murs); indice_serie_murs++) {
        series_mur_pointeur = llsm_get(&liste_series_murs, indice_serie_murs);
        printf("serie de murs n°%d\n", indice_serie_murs);
        printf("\ttype de papier peint : %d\n", series_mur_pointeur->type_papier_peint);
        printf("\tnombre de murs dans la serie : %d\n", llm_length(&series_mur_pointeur->liste_murs));
        for (indice_mur = 0; indice_mur < llm_length(&series_mur_pointeur->liste_murs); indice_mur++) {
            mur_pointeur = llm_get(&series_mur_pointeur->liste_murs, indice_mur);
            printf("\tmur n°%d\n", indice_mur);
            printf("\t\tlargeur : %.2f\n", mur_pointeur->largeur);
            printf("\t\thauteur : %.2f\n", mur_pointeur->hauteur);
            printf("\t\thauteur_pan_droit : %.2f\n", mur_pointeur->hauteur_pan_droit);
            printf("\t\tlargeur_pan_droit : %.2f\n", mur_pointeur->largeur_pan_droit);
            printf("\t\thauteur_pan_gauche : %.2f\n", mur_pointeur->hauteur_pan_gauche);
            printf("\t\tlargeur_pan_gauche : %.2f\n", mur_pointeur->largeur_pan_gauche);
            printf("\t\tlongueur(liste_les) : %d\n", lll_length(&mur_pointeur->liste_les));
            printf("\t\tlongueur(liste_obstacles) : %d\n", llo_length(&mur_pointeur->liste_obstacles));
            for (indice_obstacle = 0; indice_obstacle < llo_length(&mur_pointeur->liste_obstacles); indice_obstacle++) {
                obstacle_pointeur = llo_get(&mur_pointeur->liste_obstacles, indice_obstacle);
                printf("\t\tobstacle n°%d\n", indice_obstacle);
                printf("\t\t\tX : %.2f\n", obstacle_pointeur->X);
                printf("\t\t\tY : %.2f\n", obstacle_pointeur->Y);
                printf("\t\t\tlargeur : %.2f\n", obstacle_pointeur->largeur);
                printf("\t\t\thauteur : %.2f\n", obstacle_pointeur->hauteur);
            }
        }
        printf("\n");
    }
}


void test_interface_colle() {
    float volume_pots;
    interface_colle(&volume_pots);
    printf("volume pots : %.4f\n", volume_pots);
}


void test_calcul() {
    LL_ROULEAU liste_rouleaux = llr_create();
    LL_SERIE_MURS liste_series_murs = llsm_create();
    int indice_serie_murs, indice_mur, indice_obstacle, indice_le, indice_rouleau;
    ROULEAU rouleau, *rouleau_pointeur;
    SERIE_MURS serie_murs, *serie_murs_pointeur;
    MUR mur, *mur_pointeur;
    OBSTACLE obstacle, *obstacle_pointeur;
    LE *le_pointeur;
    float quantite_colle, volume_pots;
    int nombre_pots;
    // on ajoute des rouleaux à la liste
    rouleau.liste_chutes = llf_create();
    rouleau.longueur = 10;
    rouleau.largeur = 1;
    rouleau.longueur_restante = 0;
    rouleau.quantite = 0;
    rouleau.longueur_motif = 0;
    llr_append(&liste_rouleaux, rouleau);
    rouleau.liste_chutes = llf_create();
    // rouleau.largeur = 1;
    rouleau.longueur_motif = 1;
    llr_append(&liste_rouleaux, rouleau);
    // on ajoute des séries de murs
    serie_murs.liste_murs = llm_create();
    serie_murs.type_papier_peint = 0;
    mur.largeur = 5;
    mur.hauteur = 4;
    mur.largeur_pan_droit = 2;
    mur.hauteur_pan_droit = 3;
    mur.largeur_pan_gauche = 3;
    mur.hauteur_pan_gauche = 3;
    // mur.largeur_pan_droit = 0;
    // mur.hauteur_pan_droit = 0;
    // mur.largeur_pan_gauche = 0;
    // mur.hauteur_pan_gauche = 0;
    mur.liste_les = lll_create();
    mur.liste_obstacles = llo_create();
    obstacle.X = 1;
    obstacle.Y = 1;
    obstacle.largeur = 3;
    obstacle.hauteur = 2;
    llo_append(&mur.liste_obstacles, obstacle);
    llm_append(&serie_murs.liste_murs, mur);
    llsm_append(&liste_series_murs, serie_murs);
    serie_murs.liste_murs = llm_create();
    serie_murs.type_papier_peint = 1;
    mur.largeur = 5;
    mur.hauteur = 4;
    mur.largeur_pan_droit = 0;
    mur.hauteur_pan_droit = 0;
    mur.largeur_pan_gauche = 5;
    mur.hauteur_pan_gauche = 0;
    mur.liste_les = lll_create();
    mur.liste_obstacles = llo_create();
    llm_append(&serie_murs.liste_murs, mur);
    mur.largeur = 5;
    mur.hauteur = 4;
    mur.largeur_pan_droit = 0;
    mur.hauteur_pan_droit = 0;
    mur.largeur_pan_gauche = 0;
    mur.hauteur_pan_gauche = 0;
    mur.liste_les = lll_create();
    mur.liste_obstacles = llo_create();
    obstacle.X = 1;
    obstacle.Y = 1;
    obstacle.largeur = 3;
    obstacle.hauteur = 2;
    llo_append(&mur.liste_obstacles, obstacle);
    llm_append(&serie_murs.liste_murs, mur);
    llsm_append(&liste_series_murs, serie_murs);
    volume_pots = 2. / 1000;
    // appel calcul_les
    calcul_les(&liste_series_murs, &liste_rouleaux);
    // appel calcul_pans_coupés
    calcul_pans_coupes(&liste_series_murs);
    // appel calcul_decoupage_les
    calcul_decoupage_les(&liste_series_murs, &liste_rouleaux);
    // appel calcul_obstacles
    calcul_obstacles(&liste_series_murs, &liste_rouleaux);
    // appel calcul_assemblage_les
    calcul_assemblage_les(&liste_series_murs, &liste_rouleaux);
    // check des lés créés
    printf("nombre de series de murs crees : %d\n\n", llsm_length(&liste_series_murs));
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(&liste_series_murs); indice_serie_murs++) {
        serie_murs_pointeur = llsm_get(&liste_series_murs, indice_serie_murs);
        printf("serie de murs n°%d\n", indice_serie_murs);
        printf("\ttype de papier peint : %d\n", serie_murs_pointeur->type_papier_peint);
        printf("\tnombre de murs dans la serie : %d\n", llm_length(&serie_murs_pointeur->liste_murs));
        for (indice_mur = 0; indice_mur < llm_length(&serie_murs_pointeur->liste_murs); indice_mur++) {
            mur_pointeur = llm_get(&serie_murs_pointeur->liste_murs, indice_mur);
            printf("\tmur n°%d\n", indice_mur);
            printf("\t\tlargeur : %.2f\n", mur_pointeur->largeur);
            printf("\t\thauteur : %.2f\n", mur_pointeur->hauteur);
            printf("\t\thauteur_pan_droit : %.2f\n", mur_pointeur->hauteur_pan_droit);
            printf("\t\tlargeur_pan_droit : %.2f\n", mur_pointeur->largeur_pan_droit);
            printf("\t\thauteur_pan_gauche : %.2f\n", mur_pointeur->hauteur_pan_gauche);
            printf("\t\tlargeur_pan_gauche : %.2f\n", mur_pointeur->largeur_pan_gauche);
            printf("\t\tlongueur(liste_obstacles) : %d\n", llo_length(&mur_pointeur->liste_obstacles));
            for (indice_obstacle = 0; indice_obstacle < llo_length(&mur_pointeur->liste_obstacles); indice_obstacle++) {
                obstacle_pointeur = llo_get(&mur_pointeur->liste_obstacles, indice_obstacle);
                printf("\t\tobstacle n°%d\n", indice_obstacle);
                printf("\t\t\tX : %.2f\n", obstacle_pointeur->X);
                printf("\t\t\tY : %.2f\n", obstacle_pointeur->Y);
                printf("\t\t\tlargeur : %.2f\n", obstacle_pointeur->largeur);
                printf("\t\t\thauteur : %.2f\n", obstacle_pointeur->hauteur);
            }
            printf("\t\tlongueur(liste_les) : %d\n", lll_length(&mur_pointeur->liste_les));
            for (indice_le = 0; indice_le < lll_length(&mur_pointeur->liste_les); indice_le++) {
                le_pointeur = lll_get(&mur_pointeur->liste_les, indice_le);
                printf("\t\tle n°%d\n", indice_le);
                printf("\t\t\tX : %.2f\n", le_pointeur->X);
                printf("\t\t\tY : %.2f\n", le_pointeur->Y);
                printf("\t\t\tlargeur : %.2f\n", le_pointeur->largeur);
                printf("\t\t\thauteur : %.2f\n", le_pointeur->hauteur);
            }
        }
        printf("\n");
    }
    // appel calcul_tapissage
    calcul_tapissage(&liste_series_murs, &liste_rouleaux);
    // check des quantité de rouleaux
    for (indice_rouleau = 0; indice_rouleau < llr_length(&liste_rouleaux); indice_rouleau++) {
        rouleau_pointeur = llr_get(&liste_rouleaux, indice_rouleau);
        printf("rouleau n°%d\n", indice_rouleau);
        printf("quantite : %d\n", rouleau_pointeur->quantite);
    }
    // appel calcul_colle
    calcul_colle(&liste_series_murs, &quantite_colle, &volume_pots, &nombre_pots);
    // check quantité colle
    printf("quantite colle : %.2f\n", quantite_colle * 1000);
    printf("nombre_pots : %d", nombre_pots);
}


int main() {
    // test_float_equality();
    // test_interface_rouleaux();
    // test_interface_murs();
    // test_interface_colle();
    test_calcul();

    return EXIT_SUCCESS;
}
