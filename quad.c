#include "quad.h"

Quadruplet quads[MAX_QUADS];
int qc = 0;
int temp_count = 0;

/* buffer pour les temporaires et conversions */
static char temp_buf[MAX_TEMP][20];
static char conv_buf[20];

void quad_init(void) {
    qc = 0;
    temp_count = 0;
}

void generer(const char *op, const char *arg1, const char *arg2, const char *res) {
    if (qc >= MAX_QUADS) {
        fprintf(stderr, "Erreur : depassement du nombre max de quadruplets\n");
        return;
    }
    strncpy(quads[qc].op, op, 9);
    strncpy(quads[qc].arg1, arg1 ? arg1 : "", 19);
    strncpy(quads[qc].arg2, arg2 ? arg2 : "", 19);
    strncpy(quads[qc].res, res ? res : "", 19);
    qc++;
}

/* genere un nouveau nom de temporaire T0, T1, T2... */
char* temp_nouveau(void) {
    if (temp_count >= MAX_TEMP) {
        fprintf(stderr, "Erreur : trop de temporaires\n");
        return "T???";
    }
    sprintf(temp_buf[temp_count], "T%d", temp_count);
    return temp_buf[temp_count++];
}

/* convertir un entier en chaine (pour passer aux quadruplets) */
char* int_to_str(int v) {
    sprintf(conv_buf, "%d", v);
    return conv_buf;
}

void quad_afficher(void) {
    int i;
    printf("\n====== QUADRUPLETS ======\n");
    printf("%-6s %-8s %-10s %-10s %-10s\n", "N", "OP", "ARG1", "ARG2", "RES");
    printf("----------------------------------------------\n");
    for (i = 0; i < qc; i++) {
        printf("%-6d %-8s %-10s %-10s %-10s\n",
               i, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
    }
    printf("=========================\n\n");
}
