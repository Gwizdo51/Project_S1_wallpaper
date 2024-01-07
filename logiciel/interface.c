#include "interface.h"


void interface_rouleaux(LL_ROULEAU *liste_rouleaux) {
    // variables
    char caractere_entre;
    BOOL caractere_valide;
    int indice_rouleau;
    int nombre_types_rouleaux;
    ROULEAU nouveau_rouleau;

    printf("1) INVENTAIRE PAPIER PEINT\n\n");
    printf("Nombre de type de papier peints differents : ");
    scanf("%d", &nombre_types_rouleaux);
    printf("\n");
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


void interface_murs(LL_SERIE_MURS *liste_series_murs, LL_ROULEAU *liste_rouleau) {
    // variables
    int nombre_pieces, indice_piece, nombre_murs, indice_mur, indice_rouleau_utilise, nb_pans, indice_pan, nb_obstacles, indice_obstacle;
    char caractere_entre;
    BOOL caractere_valide, pan_coupe_gauche_entre, ajouter_a_serie_precedente, premiere_serie_murs;
    OBSTACLE nouvel_obstacle;
    MUR nouveau_mur;
    SERIE_MURS serie_murs_actuelle;

    printf("2) PIECES ET MURS\n\n");
    premiere_serie_murs = TRUE;

    printf("Nombre de pieces a tapisser : ");
    scanf("%d", &nombre_pieces);
    printf("\n");

    for (indice_piece = 0; indice_piece < nombre_pieces; indice_piece++) {
        // on commence une nouvelle série de murs pour chaque nouvelle pièce
        printf("Piece numero %d\n", indice_piece);

        printf("Nombre de murs a tapisser dans la piece : ");
        scanf("%d", &nombre_murs);

        printf("\n");
        for (indice_mur = 0; indice_mur < nombre_murs; indice_mur++) {
            printf("Mur numero %d\n", indice_mur);
            // initialiser les listes de lés et d’obstacles
            nouveau_mur.liste_les = lll_create();
            nouveau_mur.liste_obstacles = llo_create();
            // initialiser les dimensions des pans coupés à 0
            nouveau_mur.hauteur_pan_gauche = 0;
            nouveau_mur.largeur_pan_gauche = 0;
            nouveau_mur.hauteur_pan_droit = 0;
            nouveau_mur.largeur_pan_droit = 0;

            // saisir les dimensions du mur
            printf("Hauteur : ");
            scanf("%f", &nouveau_mur.hauteur);
            printf("Largeur : ");
            scanf("%f", &nouveau_mur.largeur);

            // saisir le type de papier peint utilisé
            printf("Entrez le numero du papier peint a utiliser pour tapisser ce mur : ");
            scanf("%d", &indice_rouleau_utilise);

            // saisir les dimensions des pans coupés
            caractere_valide = FALSE;
            printf("Ce mur a-t-il des pans coupes ? [O]ui/[N]on\n");
            while (!caractere_valide) {
                // scanf(" %c", &caractere_entre);
                caractere_entre = _getch();
                if (caractere_entre == 'o' || caractere_entre == 'n') {
                    caractere_valide = TRUE;
                }
            }

            if (caractere_entre == 'o') {
                printf("Nombre de pans coupes : ");
                scanf("%d", &nb_pans);
                for (indice_pan = 0; indice_pan < nb_pans; indice_pan++) {
                    printf("Pan coupe numero %d\n", indice_pan);
                    if (indice_pan == 0) {
                        caractere_valide = FALSE;
                        // demander quel pan l’utilisateur veut entrer en premier
                        printf("Le pan est-il a gauche ou a droite ? [G]auche/[D]roite\n");
                        while (!caractere_valide) {
                            // scanf(" %c", &caractere_entre);
                            caractere_entre = _getch();
                            if (caractere_entre == 'g' || caractere_entre == 'd') {
                                caractere_valide = TRUE;
                            }
                        }
                        if (caractere_entre == 'g') {
                            pan_coupe_gauche_entre = TRUE;
                            printf("Hauteur du pan gauche : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_gauche);
                            printf("Largeur du pan gauche : ");
                            scanf("%f", &nouveau_mur.largeur_pan_gauche);
                        } else {
                            pan_coupe_gauche_entre = FALSE;
                            printf("Hauteur du pan droit : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_droit);
                            printf("Largeur du pan droit : ");
                            scanf("%f", &nouveau_mur.largeur_pan_droit);
                        }
                    } else {
                        // saisir les dimensions de l’autre pan coupé
                        if (pan_coupe_gauche_entre) {
                            printf("Hauteur pan droit : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_droit);
                            printf("Largeur pan droit : ");
                            scanf("%f", &nouveau_mur.largeur_pan_droit);
                        } else {
                            // saisir les dimensions du pan coupé gauche
                            printf("Hauteur pan gauche : ");
                            scanf("%f", &nouveau_mur.hauteur_pan_gauche);
                            printf("Largeur pan gauche : ");
                            scanf("%f", &nouveau_mur.largeur_pan_gauche);
                        }
                    }
                }
            }

            // saisir les dimensions des obstacles
            caractere_valide = FALSE;
            printf("Presence d'obstacles ? [O]ui/[N]on\n");
            while (!caractere_valide) {
                // scanf(" %c", &caractere_entre);
                caractere_entre = _getch();
                if (caractere_entre == 'o' || caractere_entre == 'n') {
                    caractere_valide = TRUE;
                }
            }
            if (caractere_entre == 'o') {
                printf("Nombre d'obstacles : ");
                scanf("%d", &nb_obstacles);

                for (indice_obstacle = 0; indice_obstacle < nb_obstacles; indice_obstacle++) {
                    printf("Obstacle numero %d\n", indice_obstacle);

                    printf("Distance de l'obstacle par rapport au sol : ");
                    scanf("%f", &nouvel_obstacle.Y);

                    printf("Distance de l'obstacle par rapport au coin gauche : ");
                    scanf("%f", &nouvel_obstacle.X);

                    printf("Hauteur obstacle : ");
                    scanf("%f", &nouvel_obstacle.hauteur);

                    printf("Largeur obstacle : ");
                    scanf("%f", &nouvel_obstacle.largeur);

                    llo_append(&nouveau_mur.liste_obstacles, nouvel_obstacle);
                }
            }

            // déterminer si le mur doit être ajouté à une nouvelle série ou à la série précédente
            // on ajoute le mur à la série précédente si:
            // - le mur n’est pas le premier de la pièce
            // - le mur est tapissé avec un papier peint à motifs, et le même que le mur précédent
            // - le mur est indiqué comme étant adjacent au mur précédent
            // sinon, on crée une nouvelle série de murs
            ajouter_a_serie_precedente = FALSE;
            if (indice_mur != 0 && llr_get(liste_rouleau, indice_rouleau_utilise)->longueur_motif > 0 && serie_murs_actuelle.type_papier_peint == indice_rouleau_utilise) {
                caractere_valide = FALSE;
                printf("Le mur est-il adjacent au mur precedent ? [O]ui/[N]on\n");
                while (!caractere_valide) {
                    // scanf(" %c", &caractere_entre);
                    caractere_entre = _getch();
                    if (caractere_entre == 'o' || caractere_entre == 'n') {
                        caractere_valide = TRUE;
                    }
                }
                if (caractere_entre == 'o') {
                    ajouter_a_serie_precedente = TRUE;
                }
            }
            if (ajouter_a_serie_precedente) {
                // on ajoute le mur à la série précédente
                llm_append(&serie_murs_actuelle.liste_murs, nouveau_mur);
            } else {
                // on ajoute la série actuelle (si elle existe) à liste_série_murs
                if (premiere_serie_murs) {
                    premiere_serie_murs = FALSE;
                } else {
                    llsm_append(liste_series_murs, serie_murs_actuelle);
                }
                // on ajoute le mur dans nouvelle série de murs
                serie_murs_actuelle.liste_murs = llm_create();
                llm_append(&serie_murs_actuelle.liste_murs, nouveau_mur);
                // on ajoute le type de papier peint à la série
                serie_murs_actuelle.type_papier_peint = indice_rouleau_utilise;
            }
            printf("\n");
        }
        printf("\n");
    }
    // on ajoute la dernière série créée à la liste de séries de murs
    llsm_append(liste_series_murs, serie_murs_actuelle);
}


void interface_colle(float *volume_pots) {
    // variables
    char caractere_entre;
    BOOL caractere_valide;

    printf("3) CONDITIONNEMENT COLLE\n");
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
        printf("Entrez le volume de colle par pots (en litres) : ");
        scanf("%f", volume_pots);
        // volume de colle dans un pots stocké en m3
        *volume_pots /= 1000;
    }
    else {
        *volume_pots = 0;
    }
    printf("\n");
}
