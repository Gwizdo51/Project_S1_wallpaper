
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "interface.h"

void interface_colle(float *volume_pots);
{

    char caractere_entre;
    BOOL caractere_valide;

    printf("4) CONDITIONNEMENT COLLE \n");
    printf("Est-ce que la colle est conditionnée ? [O]ui/ [N]on");

    caractere_valide = FALSE;

    while (caractere_valide == FALSE)
    {
        scanf("%c", &caractere_entre);
        if (caractere_entre == 'o' || caractere_entre == 'n')
        {
            caractere_valide = TRUE;
        }
    }

    if (caractere_entre == 'o')
    {
        printf("Volume de colle par pots : ");
        scanf("%f", volume_pots);
    }
    else
    {
        *volume_pots = 0;
    }
}

void interface_rouleaux(LL_ROULEAU *ROULEAU);
{
    char caractere_entre;
    BOOL caractere_valide;
    int indice_rouleau;
    int nombre_types;

    printf("1) INVENTAIRE PAPIER PEINT");
    printf("Nombre de type de papier peints differents : ");
    scanf("%d", &nombre_types);
    for (indice_rouleau = 0; indice_rouleau < longueur(nombre_types) - 1; indice_rouleau++)
    {
        LL_ROULEAU liste_rouleau = llr_create();
        ROULEAU nouveau_rouleau;
        // rouleau <- NOUVEAU rouleau
        printf("Dimension rouleaux papier peints : ");
        printf("Largeur : ");
        scanf("%d", &rouleau.largeur);
        printf("Longueur : ");
        scanf("%d", &rouleau.longueur);
        printf("Motif ? [O]ui/ [N]on");
        caractere_valide = FALSE;
        while(caractere_valide == FALSE)
        {
            scanf("%c", &caractere_entre);
            if (caractere_entre == 'o' || caractere_entre == 'n')
            {
                caractere_valide = TRUE;
            }
        }
        if (caractere_entre == 'o')
        {
            printf("Longueur motif : ");
            scanf("%s", &rouleau.longueur_motif);
        }
        else
        {
            rouleau.longueur_motif = 0;
        }
        rouleau.longueur_restante = 0;
        rouleau.quantité = 0;
        LL_ROULEAU liste_chutes = llr_create();
        // rouleau.liste_chutes <- créer()
        llr_append(&liste_rouleau, nouveau_rouleau);        
        // ajouter(liste_rouleau, rouleau)
    }
}