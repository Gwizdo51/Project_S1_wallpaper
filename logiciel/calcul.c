#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "calcul.h"

void calcul_colle( LL_SERIE_MURS_NODE liste_series_murs, float *volume_pots, float *quantité_colle, int nombre_pots){
    int indice_mur, indice_obstacle, indice_serie_mur;
    float surface_totale_mur;
    mur *mur_actuel;

    surface_totale_mur = 0;
    for(indice_serie_mur = 0; indice_serie_mur < (liste_series_murs) - 1 ; indice_serie_mur++){
        for(indice_mur = 0; indice_mur < longueur(liste_series_murs, indice_serie_mur).liste_mur - 1 ; indice_mur++){
            *mur_actuel = liste_series_murs(indice_serie_mur).liste_mur(indice_mur);
            surface_totale_mur = surface_totale_mur + (*mur_actuel).hauteur * (*mur_actuel).largeur;
            
        }
    }
}