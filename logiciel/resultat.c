#include "resultat.h"


void enregistrer_resultat(LL_ROULEAU *liste_rouleaux, float *quantite_colle, int *nombre_pots, char *nom_fichier_resultat) {
    // variables
    int indice_rouleau;
    time_t timestamp_now;
    struct tm *time_now_pointer;
    FILE *stream;
    char date_heure_humain[STRING_BUFFER_MAX_SIZE];

    // création du nouveau nom de fichier
    // on place dans time_now_pointer la date et l'heure actuelles
    time(&timestamp_now);
    time_now_pointer = localtime(&timestamp_now);
    strftime(nom_fichier_resultat, 100, "%Y%m%d-%H%M%S - resultats.txt", time_now_pointer);

    // on crée le fichier et on l'ouvre en écriture
    stream = fopen(nom_fichier_resultat, "w");

    // on ajoute la date et l'heure de l'obtention du résultat
    strftime(date_heure_humain, 100, "%c", time_now_pointer);
    // on ajoute les résultats
    fprintf(stream, "date et heure : %s\n\n", date_heure_humain);
    fprintf(stream, "Matiere premiere a commander :\n\n");
    fprintf(stream, "Nombre de rouleaux, par types :\n");
    for (indice_rouleau = 0; indice_rouleau < llr_length(liste_rouleaux); indice_rouleau++) {
        fprintf(stream, "\ttype de papier peint n°%d : %d\n", indice_rouleau, llr_get(liste_rouleaux, indice_rouleau)->quantite);
    }
    fprintf(stream, "\nVolume de colle : %.2fL\n", *quantite_colle * 1000);
    if (nombre_pots != 0) {
        fprintf(stream, "Nombre de pots de colle : %d\n", *nombre_pots);
    }
}


void afficher_resultat(LL_ROULEAU *liste_rouleaux, float *quantite_colle, int *nombre_pots, char *nom_fichier_resultat) {
    // variables
    int indice_rouleau;

    printf("4) MATIERE PREMIERE A COMMANDER\n");
    printf("Nombre de rouleaux, par types :\n");
    for (indice_rouleau = 0; indice_rouleau < llr_length(liste_rouleaux); indice_rouleau++) {
        printf("\ttype de papier peint n°%d : %d\n", indice_rouleau, llr_get(liste_rouleaux, indice_rouleau)->quantite);
    }
    // on affiche la quantité de colle en litres
    printf("Volume de colle : %.2fL\n", *quantite_colle * 1000);
    if (nombre_pots != 0) {
        printf("Nombre de pots de colle : %d\n", *nombre_pots);
    }
    printf("\nLe resultat est enregistre dans \"%s\".\n", nom_fichier_resultat);
    printf("\n");
    system("pause");
}
