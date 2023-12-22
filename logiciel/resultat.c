#include <stdio.h>
#include <stdlib.h>

int resultat(float quantite_colle, int nombre_pots, char* nom_fichier, LL_ROULEAU)
{

printf("4) RESULTAT \n");
printf("Nombre de rouleaux : \n");

for (int i = 0; i < longueur(liste_rouleaux) - 1; i++){
    printf("PAPIER PEINT #", "%i", ":", obtenir (liste_rouleaux[i].quantité_rouleaux));
}

printf("Volume colle : ", quantité_colle); 

if (nombre_pots != 0){
    printf("Nombre de pots de colle : ", nombre_pots);  
}

printf("Le resultat est enregistré dans ", nom_fichier);

}
