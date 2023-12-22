#ifndef _HEADER_TYPES
#define _HEADER_TYPES

// standard libraries
#include <stdio.h>
#include <stdlib.h>

// booléen
#define BOOL char
#define FALSE 0
#define TRUE 1

// liste chaînée de décimaux
typedef struct _LL_FLOAT_NODE {
    float data;
    struct _LL_FLOAT_NODE *next_node;
} LL_FLOAT_NODE;
typedef struct _LL_FLOAT {
    LL_FLOAT_NODE *first_node;
} LL_FLOAT;

// lé
typedef struct _LE {
    float X,
          Y,
          hauteur,
          largeur;
} LE;

// liste chaînée de lés
typedef struct _LL_LE_NODE {
    LE data;
    struct _LL_LE_NODE *next_node;
} LL_LE_NODE;
typedef struct _LL_LE {
    LL_LE_NODE *first_node;
} LL_LE;

// obstacles
typedef struct _OBSTACLE {
    float X,
          Y,
          hauteur,
          largeur;
} OBSTACLE;

// liste chaînée de décimaux
typedef struct _LL_OBSTACLE_NODE {
    OBSTACLE data;
    struct _LL_OBSTACLE_NODE *next_node;
} LL_OBSTACLE_NODE;
typedef struct _LL_OBSTACLE {
    LL_OBSTACLE_NODE *first_node;
} LL_OBSTACLE;

// rouleaux
typedef struct _ROULEAU {
    float longueur,
          largeur,
          longueur_motif,
          longueur_restante;
    int quantite;
    LL_FLOAT liste_chutes;
} ROULEAU;

// liste chaînée de rouleaux
typedef struct _LL_ROULEAU_NODE {
    ROULEAU data;
    struct _LL_ROULEAU_NODE *next_node;
} LL_ROULEAU_NODE;
typedef struct _LL_ROULEAU {
    LL_ROULEAU_NODE *first_node;
} LL_ROULEAU;

// murs
typedef struct _MUR {
    float hauteur,
          largeur,
          hauteur_pan_gauche,
          largeur_pan_gauche,
          hauteur_pan_droit,
          largeur_pan_droit;
    LL_LE liste_lés;
    LL_OBSTACLE liste_obstacles;
} MUR;

// liste chaînée de murs
typedef struct _LL_MUR_NODE {
    MUR data;
    struct _LL_MUR_NODE *next_node;
} LL_MUR_NODE;
typedef struct _LL_MUR {
    LL_MUR_NODE *first_node;
} LL_MUR;

// série de murs
typedef struct _SERIE_MURS {
    LL_MUR liste_murs;
    int type_papier_peint;
} SERIE_MURS;

// liste de chaînée de séries de murs
typedef struct _LL_SERIE_MURS_NODE {
    SERIE_MURS data;
    struct _LL_SERIE_MURS_NODE *next_node;
} LL_SERIE_MURS_NODE;
typedef struct _LL_SERIE_MURS {
    LL_SERIE_MURS_NODE *first_node;
} LL_SERIE_MURS;

#endif
