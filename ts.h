#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TABLE 100
#define MAX_IDF 8


typedef enum {
    TYPE_INTEGER,
    TYPE_FLOAT
} TypeVar;


typedef enum {
    NATURE_VAR,
    NATURE_CONST,
    NATURE_TAB
} NatureSymb;

/* une entree dans la table des symboles */
typedef struct {
    char nom[MAX_IDF + 1];
    TypeVar type;
    NatureSymb nature;
    int taille;         /* taille du tableau, 1 pour variable simple */
    int is_init;        /* 1 si la variable a ete initialisee */
    union {
        int val_int;
        float val_float;
    } val;              /* valeur pour les constantes */
} Symbole;

/* la table elle-meme */
typedef struct {
    Symbole entries[TAILLE_TABLE];
    int nb;             /* nombre d'entrees courantes */
} TableSymboles;

/* variable globale (declaree dans ts.c) */
extern TableSymboles ts;

/* fonctions */
void ts_init(void);
int ts_rechercher(const char *nom);
int ts_inserer(const char *nom, TypeVar type, NatureSymb nature, int taille);
void ts_afficher(void);
const char* type_to_str(TypeVar t);
const char* nature_to_str(NatureSymb n);

#endif
