#include "interface.h"


void interface_rouleaux(LL_ROULEAU *liste_rouleaux) {
    // variables
    char caractere_entre;
    BOOL caractere_valide;
    int indice_rouleau;
    int nombre_types_rouleaux;
    ROULEAU nouveau_rouleau;

    printf("1) INVENTAIRE PAPIER PEINT\n");
    printf("Nombre de type de papier peints differents : ");
    scanf("%d", &nombre_types_rouleaux);
    for (indice_rouleau = 0; indice_rouleau < nombre_types_rouleaux; indice_rouleau++) {
        printf("Type de papier n°%d\n", indice_rouleau);
        printf("Dimension rouleaux papier peints :\n");
        printf("Largeur : ");
        scanf("%f", &nouveau_rouleau.largeur);
        printf("Longueur : ");
        scanf("%f", &nouveau_rouleau.longueur);
        printf("Le papier peint a-t-il un motif ? [O]ui/[N]on\n");
        caractere_valide = FALSE;
        while(caractere_valide == FALSE) {
            // scanf("%c", &caractere_entre);
            caractere_entre = _getch();
            if (caractere_entre == 'o' || caractere_entre == 'n') {
                caractere_valide = TRUE;
            }
        }
        if (caractere_entre == 'o') {
            printf("Entrez la longueur motif : ");
            scanf("%f", &nouveau_rouleau.longueur_motif);
        }
        else {
            nouveau_rouleau.longueur_motif = 0.;
        }
        // initialisation des attributs du nouveau rouleau
        nouveau_rouleau.longueur_restante = 0;
        nouveau_rouleau.quantite = 0;
        nouveau_rouleau.liste_chutes = llf_create();
        llr_append(liste_rouleaux, nouveau_rouleau);
        printf("\n");
    }
}


void interface_colle(float *volume_pots) {
    // variables
    char caractere_entre;
    BOOL caractere_valide;

    printf("4) CONDITIONNEMENT COLLE\n");
    printf("Est-ce que la colle est conditionnée ? [O]ui/ [N]on\n");
    caractere_valide = FALSE;
    while (!caractere_valide) {
        // scanf("%c", &caractere_entre);
        caractere_entre = _getch();
        if (caractere_entre == 'o' || caractere_entre == 'n') {
            caractere_valide = TRUE;
        }
    }
    if (caractere_entre == 'o') {
        printf("Entrez le volume de colle par pots : ");
        scanf("%f", volume_pots);
    }
    else {
        *volume_pots = 0;
    }
}
