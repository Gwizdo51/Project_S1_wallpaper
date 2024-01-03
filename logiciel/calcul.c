#include "calcul.h"


void calcul_pans_coupes(LL_SERIE_MURS *liste_series_murs) {
    // variables
    int indice_serie_murs, indice_mur, indice_le;
    MUR *mur_actuel_pointeur;
    LE *le_actuel_pointeur;

    // pour chaque série de murs ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        // pour chaque mur de la série ...
        for (indice_mur = 0; indice_mur < llm_length(&(llsm_get(liste_series_murs, indice_serie_murs))->liste_murs); indice_mur++) {
            mur_actuel_pointeur = llm_get(&(llsm_get(liste_series_murs, indice_serie_murs))->liste_murs, indice_mur);
            // pour chaque lé du mur ...
            for (indice_le = 0; indice_le < lll_length(&mur_actuel_pointeur->liste_les); indice_le++) {
                le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le);
                // si le lé est complètement en dessous du pan coupé gauche ...
                if (le_actuel_pointeur->X + le_actuel_pointeur->largeur < mur_actuel_pointeur->largeur_pan_gauche) {
                    // on donne au lé la hauteur de son bord droit
                    le_actuel_pointeur->hauteur = mur_actuel_pointeur->hauteur_pan_gauche +
                                                  (mur_actuel_pointeur->hauteur - mur_actuel_pointeur->hauteur_pan_gauche) *
                                                  (le_actuel_pointeur->X + le_actuel_pointeur->largeur) /
                                                  mur_actuel_pointeur->hauteur_pan_gauche;
                }
                // si le lé est complètement en dessous du pan coupé droit ...
                else if (le_actuel_pointeur->X > mur_actuel_pointeur->largeur - mur_actuel_pointeur->hauteur_pan_droit) {
                    // on donne au lé la hauteur de son bord gauche
                    le_actuel_pointeur->hauteur = mur_actuel_pointeur->hauteur_pan_droit +
                                                  (mur_actuel_pointeur->hauteur - mur_actuel_pointeur->hauteur_pan_droit) *
                                                  (mur_actuel_pointeur->largeur - le_actuel_pointeur->X) /
                                                  mur_actuel_pointeur->largeur_pan_droit;
                }
            }
        }
    }
}
