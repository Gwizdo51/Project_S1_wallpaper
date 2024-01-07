#include "main.h"


int main() {
    // variables
    LL_ROULEAU liste_rouleaux = llr_create();
    LL_SERIE_MURS liste_series_murs = llsm_create();
    float quantite_colle, volume_pots;
    int nombre_pots;
    char nom_fichier_resultat[STRING_BUFFER_MAX_SIZE];

    // saisie des dimensions des murs
    interface_rouleaux(&liste_rouleaux);
    interface_murs(&liste_series_murs, &liste_rouleaux);
    interface_colle(&volume_pots);

    // calcul de la quantité de colle et du nombre de rouleaux
    calcul_les(&liste_series_murs, &liste_rouleaux);
    calcul_pans_coupes(&liste_series_murs);
    calcul_decoupage_les(&liste_series_murs, &liste_rouleaux);
    calcul_obstacles(&liste_series_murs, &liste_rouleaux);
    calcul_assemblage_les(&liste_series_murs, &liste_rouleaux);
    calcul_tapissage(&liste_series_murs, &liste_rouleaux);
    calcul_colle(&liste_series_murs, &quantite_colle, &volume_pots, &nombre_pots);

    // affichage et enregistrement du résultat
    enregistrer_resultat(&liste_rouleaux, &quantite_colle, &nombre_pots, nom_fichier_resultat);
    afficher_resultat(&liste_rouleaux, &quantite_colle, &nombre_pots, nom_fichier_resultat);

    return EXIT_SUCCESS;
}
