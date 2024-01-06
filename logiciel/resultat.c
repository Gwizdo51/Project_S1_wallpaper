#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "resultat.h"

int resultat(LL_ROULEAU *liste_rouleaux, float *quantite_colle, int *nombre_pots, char *nom_fichier_resultat); 

{
    printf("4) RESULTAT \n");
    printf("Nombre de rouleaux : \n");

    for (int i = 0; i < llr_lenght(liste_rouleaux) - 1; i++)
    {
        // printf("PAPIER PEINT #", "%i", ":", obtenir (liste_rouleaux i.quantité_rouleaux));
        printf("PAPIER PEINT #", "%i", ":", llr_get(liste_rouleaux, i).quantité_rouleaux);
    }

    printf("Volume colle : ", quantite_colle);

    if (nombre_pots != 0)
    {
        printf("Nombre de pots de colle : ", nombre_pots);
    }

    printf("Le resultat est enregistré dans ", nom_fichier);
}
