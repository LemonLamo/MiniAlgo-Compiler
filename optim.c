#include "optim.h"
#include <string.h>
#include <stdio.h>

/* verifie si une chaine est un nombre (entier ou reel) */
static int est_nombre(const char *s) {
    int i = 0;
    if (s[0] == '\0') return 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    if (s[i] == '\0') return 0;
    while (s[i] != '\0') {
        if (s[i] != '.' && !isdigit(s[i])) return 0;
        i++;
    }
    return 1;
}

/* verifie si un quadruplet est un label utilise par un saut */
static int label_utilise(const char *label) {
    int i;
    for (i = 0; i < qc; i++) {
        if (strcmp(quads[i].op, "BR") == 0 || strcmp(quads[i].op, "BZ") == 0 ||
            strcmp(quads[i].op, "BNZ") == 0) {
            if (strcmp(quads[i].res, label) == 0)
                return 1;
        }
    }
    return 0;
}

void optimiser(void) {
    int i;
    int changement = 1;

    /* on repete tant qu'il y a des changements */
    while (changement) {
        changement = 0;

        for (i = 0; i < qc; i++) {
            /* 1) Simplification des expressions constantes (constant folding)
               si les deux arguments sont des nombres, on calcule directement */
            if ((strcmp(quads[i].op, "+") == 0 || strcmp(quads[i].op, "-") == 0 ||
                 strcmp(quads[i].op, "*") == 0 || strcmp(quads[i].op, "/") == 0) &&
                est_nombre(quads[i].arg1) && est_nombre(quads[i].arg2)) {

                double a = atof(quads[i].arg1);
                double b = atof(quads[i].arg2);
                double resultat = 0;

                if (strcmp(quads[i].op, "+") == 0) resultat = a + b;
                else if (strcmp(quads[i].op, "-") == 0) resultat = a - b;
                else if (strcmp(quads[i].op, "*") == 0) resultat = a * b;
                else if (strcmp(quads[i].op, "/") == 0 && b != 0) resultat = a / b;
                else continue;

                /* remplacer par une affectation directe */
                strcpy(quads[i].op, "=");
                if (resultat == (int)resultat)
                    sprintf(quads[i].arg1, "%d", (int)resultat);
                else
                    sprintf(quads[i].arg1, "%.2f", resultat);
                strcpy(quads[i].arg2, "");
                changement = 1;
            }

            /* 2) Simplification : x + 0 = x, x - 0 = x, x * 1 = x, x / 1 = x */
            if (strcmp(quads[i].op, "+") == 0 && strcmp(quads[i].arg2, "0") == 0) {
                strcpy(quads[i].op, "=");
                strcpy(quads[i].arg2, "");
                changement = 1;
            }
            if (strcmp(quads[i].op, "-") == 0 && strcmp(quads[i].arg2, "0") == 0) {
                strcpy(quads[i].op, "=");
                strcpy(quads[i].arg2, "");
                changement = 1;
            }
            if (strcmp(quads[i].op, "*") == 0 && strcmp(quads[i].arg2, "1") == 0) {
                strcpy(quads[i].op, "=");
                strcpy(quads[i].arg2, "");
                changement = 1;
            }
            if (strcmp(quads[i].op, "/") == 0 && strcmp(quads[i].arg2, "1") == 0) {
                strcpy(quads[i].op, "=");
                strcpy(quads[i].arg2, "");
                changement = 1;
            }

            /* 3) x * 0 = 0 */
            if (strcmp(quads[i].op, "*") == 0 && strcmp(quads[i].arg2, "0") == 0) {
                strcpy(quads[i].op, "=");
                strcpy(quads[i].arg1, "0");
                strcpy(quads[i].arg2, "");
                changement = 1;
            }
        }

        /* 4) Elimination des labels inutilises */
        for (i = 0; i < qc; i++) {
            if (strcmp(quads[i].op, "LABEL") == 0) {
                if (!label_utilise(quads[i].arg1)) {
                    /* marquer comme supprime */
                    strcpy(quads[i].op, "NOP");
                    strcpy(quads[i].arg1, "");
                    strcpy(quads[i].arg2, "");
                    strcpy(quads[i].res, "");
                    changement = 1;
                }
            }
        }
    }
}

void quad_afficher_optimise(void) {
    int i;
    int num = 0;
    printf("\n========= QUADRUPLETS OPTIMISES =========\n");
    printf("N\tOP\tARG1\tARG2\tRES\n");
    printf("---------------------------------------\n");
    for (i = 0; i < qc; i++) {
        if (strcmp(quads[i].op, "NOP") != 0) {
            printf("%d\t%s\t%s\t%s\t%s\n",
                num, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
            num++;
        }
    }
    printf("==========================================\n\n");
}
