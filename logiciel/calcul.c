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
        for (indice_mur = 0; indice_mur < llm_length(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs); indice_mur++) {
            mur_actuel_pointeur = llm_get(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs, indice_mur);
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

    // printf("debut calcul_pans_coupes\n");
    // pour chaque série de murs ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        // printf("serie de murs actuelle : %d\n", indice_serie_murs);
        // pour chaque mur de la série ...
        for (indice_mur = 0; indice_mur < llm_length(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs); indice_mur++) {
            mur_actuel_pointeur = llm_get(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs, indice_mur);
            // printf("mur actuel : %d\n", indice_mur);
            // pour chaque lé du mur ...
            for (indice_le = 0; indice_le < lll_length(&mur_actuel_pointeur->liste_les); indice_le++) {
                le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le);
                // printf("le actuel : %d\n", indice_le);
                // si le lé est complètement en dessous du pan coupé gauche ...
                if (le_actuel_pointeur->X + le_actuel_pointeur->largeur < mur_actuel_pointeur->largeur_pan_gauche) {
                    // printf("le le est completement en dessous du pan coupe gauche\n");
                    // on donne au lé la hauteur de son bord droit
                    le_actuel_pointeur->hauteur = mur_actuel_pointeur->hauteur_pan_gauche +
                                                  (mur_actuel_pointeur->hauteur - mur_actuel_pointeur->hauteur_pan_gauche) *
                                                  (le_actuel_pointeur->X + le_actuel_pointeur->largeur) /
                                                  mur_actuel_pointeur->largeur_pan_gauche;
                }
                // si le lé est complètement en dessous du pan coupé droit ...
                else if (le_actuel_pointeur->X > mur_actuel_pointeur->largeur - mur_actuel_pointeur->largeur_pan_droit) {
                    // printf("le le est completement en dessous du pan coupe droit\n");
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


void calcul_decoupage_les(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux) {
    // variables
    int indice_serie_murs, indice_mur, indice_le;
    MUR *mur_actuel_pointeur;
    LE *le_actuel_pointeur;
    LE nouveau_le;
    float hauteur_le_initial, largeur_le_initial, X_le_initial, longueur_motif, hauteur_totale_decoupee;

    // pour chaque mur, si le papier peint a un motif ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        longueur_motif = llr_get(liste_rouleaux, llsm_get(liste_series_murs, indice_serie_murs)->type_papier_peint)->longueur_motif;
        if (longueur_motif > 0) {
            for (indice_mur = 0; indice_mur < llm_length(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs); indice_mur++) {
                mur_actuel_pointeur = llm_get(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs, indice_mur);
                // pour chaque lé de la liste initiale (la liste va grandir au cours de l’algo) ...
                for (indice_le = 0; indice_le < lll_length(&mur_actuel_pointeur->liste_les); indice_le++) {
                    le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le);
                    // on conserve les grandeurs associées au lé
                    hauteur_le_initial = le_actuel_pointeur->hauteur;
                    largeur_le_initial = le_actuel_pointeur->largeur;
                    X_le_initial = le_actuel_pointeur->X;
                    // on définit la hauteur du lé initial à une longueur du motif
                    le_actuel_pointeur->hauteur = longueur_motif;
                    // on initialise la hauteur du lé déjà découpé à la longueur du motif
                    hauteur_totale_decoupee = longueur_motif;
                    // tant qu’on a pas découpé toute la hauteur du lé initial ...
                    while (hauteur_totale_decoupee < hauteur_le_initial) {
                        // on crée un nouveau lé une longueur de motif au-dessus du précédent
                        nouveau_le.X = X_le_initial;
                        nouveau_le.Y = le_actuel_pointeur->Y + longueur_motif;
                        nouveau_le.largeur = largeur_le_initial;
                        nouveau_le.hauteur = longueur_motif;
                        // on ajoute le lé créé à la fin de la liste des lés
                        lll_append(&mur_actuel_pointeur->liste_les, nouveau_le);
                        // on incrémente la hauteur totale découpée d’une longueur de motif
                        hauteur_totale_decoupee += longueur_motif;
                        // on passe au lé suivant
                        le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, lll_length(&mur_actuel_pointeur->liste_les) - 1);
                    }
                }
            }
        }
    }
}


void calcul_obstacles(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux) {
    // variables
    int indice_serie_murs, indice_mur, indice_obstacle, indice_le;
    MUR *mur_actuel_pointeur;
    LE *le_actuel_pointeur;
    OBSTACLE *obstacle_actuel_pointeur;
    BOOL obstacle_recouvre_le;
    LE nouveau_le;

    // pour chaque mur ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        for (indice_mur = 0; indice_mur < llm_length(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs); indice_mur++) {
            mur_actuel_pointeur = llm_get(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs, indice_mur);
            // si le papier peint a des motifs ...
            if (llr_get(liste_rouleaux, llsm_get(liste_series_murs, indice_serie_murs)->type_papier_peint)->longueur_motif > 0) {
                // on retire les lés de la liste de lés si ils sont recouverts sur toute leur surface
                for (indice_obstacle = 0; indice_obstacle < llo_length(&mur_actuel_pointeur->liste_obstacles); indice_obstacle++) {
                    obstacle_actuel_pointeur = llo_get(&mur_actuel_pointeur->liste_obstacles, indice_obstacle);
                    obstacle_recouvre_le = TRUE;
                    while (obstacle_recouvre_le) {
                        obstacle_actuel_pointeur = FALSE;
                        for (indice_le = 0; indice_le < lll_length(&mur_actuel_pointeur->liste_les); indice_le++) {
                            le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le);
                            if (
                                le_actuel_pointeur->X >= obstacle_actuel_pointeur->X &&
                                le_actuel_pointeur->X + le_actuel_pointeur->largeur <= obstacle_actuel_pointeur->X + obstacle_actuel_pointeur->largeur &&
                                le_actuel_pointeur->Y >= obstacle_actuel_pointeur->Y &&
                                le_actuel_pointeur->Y + le_actuel_pointeur->hauteur <= obstacle_actuel_pointeur->Y + obstacle_actuel_pointeur->hauteur
                            ) {
                                obstacle_recouvre_le = TRUE;
                                lll_remove(&mur_actuel_pointeur->liste_les, indice_le);
                                break;
                            }
                        }
                    }
                }
            }
            // si le papier peint n'a pas de motifs ...
            else {
                // on sépare le lé en 2 lés distincts si ils sont recouverts sur toute leur largeur
                for (indice_obstacle = 0; indice_obstacle < llo_length(&mur_actuel_pointeur->liste_obstacles); indice_obstacle++) {
                    obstacle_actuel_pointeur = llo_get(&mur_actuel_pointeur->liste_obstacles, indice_obstacle);
                    obstacle_recouvre_le = TRUE;
                    while (obstacle_recouvre_le) {
                        obstacle_recouvre_le = FALSE;
                        for (indice_le = 0; indice_le < lll_length(&mur_actuel_pointeur->liste_les); indice_le++) {
                            le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le);
                            if (
                                le_actuel_pointeur->X >= obstacle_actuel_pointeur->X &&
                                le_actuel_pointeur->X + le_actuel_pointeur->largeur <= obstacle_actuel_pointeur->X + obstacle_actuel_pointeur->largeur &&
                                le_actuel_pointeur->Y <= obstacle_actuel_pointeur->Y &&
                                le_actuel_pointeur->Y + le_actuel_pointeur->hauteur >= obstacle_actuel_pointeur->Y + obstacle_actuel_pointeur->hauteur
                            ) {
                                obstacle_recouvre_le = TRUE;
                                // on crée un nouveau lé au-dessus de l’obstacle, qu’on ajoute à la liste
                                nouveau_le.X = le_actuel_pointeur->X;
                                nouveau_le.Y = obstacle_actuel_pointeur->Y + obstacle_actuel_pointeur->hauteur;
                                nouveau_le.largeur = le_actuel_pointeur->largeur;
                                nouveau_le.hauteur = le_actuel_pointeur->hauteur - obstacle_actuel_pointeur->hauteur - (obstacle_actuel_pointeur->Y - le_actuel_pointeur->Y);
                                lll_append(&mur_actuel_pointeur->liste_les, nouveau_le);
                                // on réduit la hauteur du lé en dessous de l’obstacle
                                le_actuel_pointeur->hauteur = obstacle_actuel_pointeur->Y - le_actuel_pointeur->Y;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}


void calcul_assemblage_les(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux) {
    // variables
    int indice_serie_murs, indice_mur, indice_le_i, indice_le_j;
    float longueur_motif;
    MUR *mur_actuel_pointeur;
    LE *le_actuel_pointeur, *le_compare_pointeur;
    BOOL les_tous_assembles;

    // pour chaque mur, si le papier peint a un motif ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        longueur_motif = llr_get(liste_rouleaux, llsm_get(liste_series_murs, indice_serie_murs)->type_papier_peint)->longueur_motif;
        if (longueur_motif > 0) {
            for (indice_mur = 0; indice_mur < llm_length(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs); indice_mur++) {
                mur_actuel_pointeur = llm_get(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs, indice_mur);
                // tant que des lés du mur sont assemblables ...
                les_tous_assembles = FALSE;
                while (!les_tous_assembles) {
                    // on suppose que tous les lés sont assemblés
                    les_tous_assembles = TRUE;
                    // pour chaque paire de lés ...
                    for (indice_le_i = 0; indice_le_i < lll_length(&mur_actuel_pointeur->liste_les) - 1; indice_le_i++) {
                        le_actuel_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le_i);
                        for (indice_le_j = indice_le_i + 1; indice_le_j < lll_length(&mur_actuel_pointeur->liste_les); indice_le_j++) {
                            le_compare_pointeur = lll_get(&mur_actuel_pointeur->liste_les, indice_le_j);
                            // si les deux lés ont la même coordonnées X ...
                            if (le_actuel_pointeur->X == le_compare_pointeur->X) {
                                // si le lé comparé est juste au dessus du lé actuel ...
                                if (le_compare_pointeur->Y == le_actuel_pointeur->Y + le_actuel_pointeur->hauteur) {
                                    // les deux lés sont assemblables
                                    les_tous_assembles = FALSE;
                                    // on donne comme hauteur au lé du dessous (le lé actuel) la somme des hauteurs des deux lés
                                    le_actuel_pointeur->hauteur += le_compare_pointeur->hauteur;
                                    // on supprime le lé du dessus (le lé comparé) de la liste
                                    lll_remove(&mur_actuel_pointeur->liste_les, indice_le_j);
                                    break;
                                }
                                // sinon, si le lé actuel est juste au dessus du lé comparé ...
                                else if (le_actuel_pointeur->Y == le_compare_pointeur->Y + le_compare_pointeur->hauteur) {
                                    // les deux lés sont assemblables
                                    les_tous_assembles = FALSE;
                                    // on donne comme hauteur au lé du dessous (le lé comparé) la somme des hauteurs des deux lés
                                    le_compare_pointeur->hauteur += le_actuel_pointeur->hauteur;
                                    // on supprime le lé du dessus (le lé actuel) de la liste
                                    lll_remove(&mur_actuel_pointeur->liste_les, indice_le_i);
                                    break;
                                }
                            }
                        }
                        if (!les_tous_assembles) {
                            break;
                        }
                    }
                }
            }
        }
    }
}


void calcul_tapissage(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleaux) {
    // variables
    int indice_serie_murs, indice_mur, indice_chute, indice_le;
    ROULEAU *rouleau_actuel_pointeur;
    LE *le_actuel_pointeur;
    BOOL chute_utilisable;
    MUR *mur_actuel_pointeur;

    // pour chaque mur ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        rouleau_actuel_pointeur = llr_get(liste_rouleaux, llsm_get(liste_series_murs, indice_serie_murs)->type_papier_peint);
        for (indice_mur = 0; indice_mur < llm_length(&(llsm_get(liste_series_murs, indice_serie_murs)->liste_murs)); indice_mur++) {
            mur_actuel_pointeur = llm_get(&(llsm_get(liste_series_murs, indice_serie_murs)->liste_murs), indice_mur);
            // pour chaque lé du mur ...
            for (indice_le = 0; lll_length(&(mur_actuel_pointeur->liste_les)); indice_le++) {
                le_actuel_pointeur = lll_get(&(mur_actuel_pointeur->liste_les), indice_le);
                // on vérifie si le lé peut être recouvert par une chute
                chute_utilisable = FALSE;
                // pour chaque chute ...
                for (indice_chute = 0; llf_length(&(rouleau_actuel_pointeur->liste_chutes)); indice_chute++) {
                    // si la longueur de la chute est supérieure à la longueur du lé ...
                    if (*llf_get(&(rouleau_actuel_pointeur->liste_chutes), indice_chute) >= le_actuel_pointeur->hauteur) {
                        // on utilise la chute pour tapisser le lé
                        *llf_get(&(rouleau_actuel_pointeur->liste_chutes), indice_chute) -= le_actuel_pointeur->hauteur;
                        // on passe chute_utilisable à VRAI et on arrête de chercher
                        chute_utilisable = TRUE;
                        break;
                    }
                }
                // si aucune chute n’est utilisable ...
                if (!chute_utilisable) {
                    // si la longueur restante de rouleau est plus petite que la hauteur du lé ...
                    if (rouleau_actuel_pointeur->longueur_restante < le_actuel_pointeur->hauteur) {
                        // on place la longueur restante de rouleau dans les chutes
                        if (rouleau_actuel_pointeur->longueur_restante > 0) {
                            llf_append(&rouleau_actuel_pointeur->liste_chutes, rouleau_actuel_pointeur->longueur_restante);
                        }
                        // on commence un nouveau rouleau
                        rouleau_actuel_pointeur->quantite += 1;
                        rouleau_actuel_pointeur->longueur_restante = rouleau_actuel_pointeur->longueur;
                    }
                }
                // on tapisse le lé avec la longueur restante de rouleau
                rouleau_actuel_pointeur->longueur_restante -= le_actuel_pointeur->hauteur;
            }
        }
    }
}


void calcul_colle(LL_SERIE_MURS *liste_series_murs, float *quantite_colle, float *volume_pots, int *nombre_pots) {
    // variables
    int indice_mur, indice_obstacle, indice_serie_murs;
    float surface_totale;
    MUR *mur_actuel;

    surface_totale = 0;
    // pour chaque mur ...
    for (indice_serie_murs = 0; indice_serie_murs < llsm_length(liste_series_murs); indice_serie_murs++) {
        for (indice_mur = 0; indice_mur < llm_length(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs); indice_mur++) {
            mur_actuel = llm_get(&llsm_get(liste_series_murs, indice_serie_murs)->liste_murs, indice_mur);
            // on ajoute la surface du mur à la surface totale
            surface_totale += mur_actuel->hauteur * mur_actuel->largeur;
            // on retire la surface de chaque obstacle du mur à la surface totale
            for (indice_obstacle = 0; indice_obstacle < llo_length(&mur_actuel->liste_obstacles); indice_obstacle++) {
                surface_totale -= llo_get(&mur_actuel->liste_obstacles, indice_obstacle)->hauteur * llo_get(&mur_actuel->liste_obstacles, indice_obstacle)->largeur;
            }
            // on retire la surface des pans coupés à la surface totale
            surface_totale -= mur_actuel->hauteur_pan_gauche * mur_actuel->largeur_pan_gauche / 2;
            surface_totale -= mur_actuel->hauteur_pan_droit * mur_actuel->largeur_pan_droit / 2;
        }
    }
    // calcul de la quantité de colle (en m3)
    *quantite_colle = surface_totale * 0.002;
    // calcul du nombre de pots
    if (*volume_pots != 0) {
        *nombre_pots = (int) ceilf(*quantite_colle / *volume_pots);
    }
    else {
        *nombre_pots = 0;
    }
}
