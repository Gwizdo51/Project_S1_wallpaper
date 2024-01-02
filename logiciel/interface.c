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


void interface_murs(SerieMurs liste_serie_murs, Rouleau liste_rouleaux) {
    int nombre_pieces, indice_piece, nombre_murs, indice_mur, indice_rouleau_utilise, nb_pans, indice_pan, nb_obstacles, indice obstacle;
    char caractere_entre;
    bool caractere_valide, pan_coupe_gauche_entre, ajouter_a_serie_precedente, premiere_serie_murs;

    printf("2) PIECES ET MURS\n");
    premiere_serie_murs = true;

    printf("NOMBRE DE PIECES : ");
    scanf("%d", &nombre_pieces);

    for (indice_piece = 0; indice_piece < nombre_pieces; indice_piece++) {
        printf("Pièce numéro %d\n", indice_piece);

        printf("Nombre de murs : ");
        scanf("%d", &nombre_murs);

        for (indice_mur = 0; indice_mur < nombre_murs; indice_mur++) {
            printf("Mur numéro %d\n", indice_mur);

            Mur nouveau_mur;
            nouveau_mur.liste_les = creer();
            nouveau_mur.liste_obstacles = creer();
            nouveau_mur.hauteur_pan_gauche = 0;
            nouveau_mur.largeur_pan_gauche = 0;
            nouveau_mur.hauteur_pan_droit = 0;
            nouveau_mur.largeur_pan_droit = 0;

            printf("Hauteur : ");
            scanf("%f", &nouveau_mur.hauteur);

            printf("Largeur : ");
            scanf("%f", &nouveau_mur.largeur);

            printf("Quel papier peint utiliser pour ce mur : ");
            scanf("%d", &indice_rouleau_utilise);

            caractere_valide = false;
            printf("Ce mur a-t-il des pans coupés ? [O]ui/[N]on\n");
            while (!caractere_valide) {
                scanf(" %c", &caractere_entre);
                if (caractere_entre == 'o' || caractere_entre == 'n') {
                    caractere_valide = true;
                }
            }

            if (caractere_entre == 'o') {
                printf("Nombre de pans coupés : ");
                scanf("%d", &nb_pans);

                for (indice_pan = 0; indice_pan < nb_pans; indice_pan++) {
                    printf("Pan coupé numéro %d\n", indice_pan);

                    if (indice_pan == 0) {
                        caractere_valide = false;
                        printf("Pan à gauche ou à droite ?");
                        while (!caractere_valide) {
                            scanf(" %c", &caractere_entre);
                            if (caractere_entre == 'g' || caractere_entre == 'd') {
                                caractere_valide = true;
                            }
                        }

                        if (caractere_entre == 'g') {
                            pan_coupe_gauche_entre = true;
                            printf("Hauteur du pan gauche : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_gauche);
                            printf("Largeur du pan gauche : ");
                            scanf("%f", &nouveau_mur.largeur_pan_gauche);
                        } else {
                            pan_coupe_gauche_entre = false;
                            printf("Hauteur du pan droit : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_droit);
                            printf("Largeur du pan droit : ");
                            scanf("%f", &nouveau_mur.largeur_pan_droit);
                        }
                    } else {
                        if (pan_coupe_gauche_entre) {
                            printf("Hauteur pan droit : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_droit);
                            printf("Largeur pan droit : ");
                            scanf("%f", &nouveau_mur.largeur_pan_droit);
                        } else {
                            printf("Hauteur pan gauche : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_gauche);
                            printf("Largeur pan gauche : ");
                            scanf("%f", &nouveau_mur.largeur_pan_gauche);
                        }
                    }
                }
            }

            caractere_valide = false;
            printf("Présence d’obstacles ? [O]ui/[N]on\n");
            while (!caractere_valide) {
                scanf(" %c", &caractere_entre);
                if (caractere_entre == 'o' || caractere_entre == 'n') {
                    caractere_valide = true;
                }
            }

            if (caractere_entre == 'o') {
                Obstacle nouvel_obstacle;
                printf("Nombre d’obstacles : ");
                scanf("%d", &nb_obstacles);

                for (indice_obstacle = 0; indice_obstacle < nb_obstacles; indice_obstacle++) {
                    printf("Obstacle numéro %d\n", indice_obstacle);

                    printf("Distance de l’obstacle par rapport au sol : ");
                    scanf("%f", &nouvel_obstacle.Y);

                    printf("Distance de l’obstacle par rapport au coin gauche : ");
                    scanf("%f", &nouvel_obstacle.X);

                    printf("Hauteur obstacle : ");
                    scanf("%f", &nouvel_obstacle.hauteur);

                    printf("Largeur obstacle : ");
                    scanf("%f", &nouvel_obstacle.largeur);

                    ajouter(nouveau_mur.liste_obstacles, nouvel_obstacle);
                }
            }

            // ... (restant du code pour déterminer si le mur doit être ajouté à une nouvelle série ou à la série précédente)
        }
    }

    return 0;
}
