#include "resultat.h"


void afficher_resultat(LL_ROULEAU *liste_rouleaux, float *quantite_colle, int *nombre_pots, char *nom_fichier_resultat) {
    // variables
    int indice_rouleau;

    printf("4) MATIERE PREMIERE A COMMANDER\n");
    printf("Nombre de rouleaux, par types :\n");
    for (indice_rouleau = 0; indice_rouleau < llr_length(liste_rouleaux); indice_rouleau++) {
        printf("\tType de papier peint n°%d : %d\n", indice_rouleau, llr_get(liste_rouleaux, indice_rouleau)->quantite);
    }
    // on affiche la quantité de colle en litres
    printf("Volume de colle : %.2fL\n", *quantite_colle * 1000);
    if (nombre_pots != 0) {
        printf("Nombre de pots de colle : %d\n", *nombre_pots);
    }
    printf("\nLe resultat est enregistre dans \"%s\".\n", nom_fichier_resultat);
}
