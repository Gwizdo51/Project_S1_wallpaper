#include "calcul.h"


void calcul_les(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux) {
    // variables
    float largeur_dernier_le, largeur_restante_mur;
    int indice_serie_murs, indice_mur;
    ROULEAU *rouleau_actuel_pointeur;
    MUR *mur_actuel_pointeur;
    LE nouveau_le;

    // pour chaque série de murs ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        rouleau_actuel_pointeur = llr_get(liste_rouleaux, llsm_get(liste_series_murs, indice_serie_murs)->type_papier_peint);
        // on initialise largeur_dernier_le à 0
        largeur_dernier_le = 0.;
        // pour chaque mur de la série ...
        for (indice_mur = 0; indice_mur < llm_length(&(llsm_get(liste_series_murs, indice_serie_murs))->liste_murs); indice_mur++) {
            mur_actuel_pointeur = llm_get(&(llsm_get(liste_series_murs, indice_serie_murs))->liste_murs, indice_mur);
            // on initialise largeur_restante_mur à la largeur totale du mur
            largeur_restante_mur = mur_actuel_pointeur->largeur;
            // on crée le premier lé
            // il aura comme largeur la largeur du papier peint moins la largeur du dernier lé
            nouveau_le.largeur = rouleau_actuel_pointeur->largeur - largeur_dernier_le;
            // il aura comme hauteur la hauteur maximale du mur
            nouveau_le.hauteur = mur_actuel_pointeur->hauteur;
            // il partira du sol et de la gauche du mur
            nouveau_le.Y = 0.;
            nouveau_le.X = 0.;
            // on ajoute le nouveau lé crée à la liste de lés du mur actuel
            lll_append(&mur_actuel_pointeur->liste_les, nouveau_le);
            // on retire de la largeur restante du mur la largeur du lé créé
            largeur_restante_mur -= nouveau_le.largeur;
            // tant que la largeur restante du mur est supérieure à la largeur du papier peint ...
            while (largeur_restante_mur > rouleau_actuel_pointeur->largeur) {
                // on crée un nouveau lé
                // il aura comme largeur la largeur du papier peint
                nouveau_le.largeur = rouleau_actuel_pointeur->largeur;
                // il aura comme hauteur la hauteur maximale du mur
                nouveau_le.hauteur = mur_actuel_pointeur->hauteur;
                // il partira du sol
                nouveau_le.Y = 0.;
                // il aura comme coordonnée X la largeur totale du mur moins la largeur restante
                nouveau_le.X = mur_actuel_pointeur->largeur - largeur_restante_mur;
                // on ajoute le lé créé à la liste de lés du mur
                lll_append(&mur_actuel_pointeur->liste_les, nouveau_le);
                // on retire de la largeur restante du mur la largeur du lé créé
                largeur_restante_mur -= nouveau_le.largeur;
            }
            // on crée le dernier lé de largeur égale à la largeur restante du mur
            nouveau_le.largeur = largeur_restante_mur;
            // il aura comme hauteur la hauteur maximale du mur
            nouveau_le.hauteur = mur_actuel_pointeur->hauteur;
            // il partira du sol
            nouveau_le.Y = 0.;
            // il aura comme coordonnée X la largeur totale du mur moins la largeur restante
            nouveau_le.X = mur_actuel_pointeur->largeur - largeur_restante_mur;
            // on ajoute le lé créé à la liste de lés du mur
            lll_append(&mur_actuel_pointeur->liste_les, nouveau_le);
            // on place dans largeur_dernier_lé la largeur du dernier lé du mur
            largeur_dernier_le = largeur_restante_mur;
        }
    }
}


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
