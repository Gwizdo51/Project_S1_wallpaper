
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int interface_colle(float volume_pots){

    char caractere_entre;
    BOOL caractere_valide;

    printf("4) CONDITIONNEMENT COLLE \n");
    printf("Est-ce que la colle est conditionnée ? [O]ui/ [N]on");

    caractere_valide = FALSE;

    while (caractere_valide == FALSE){
        scanf("%c", &caractere_entre);
        if(caractere_entre == 'o' || caractere_entre == 'n'){
            caractere_valide = TRUE;
        }   
    }

    if (caractere_entre == 'o'){
        printf("Volume de colle par pots : ");
        scanf("%f", &volume_pots);}
    else {volume_pots = 0;
     }
}