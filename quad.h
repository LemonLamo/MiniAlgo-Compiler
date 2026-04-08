#ifndef QUAD_H
#define QUAD_H

#include <stdio.h>
#include <string.h>

#define MAX_QUADS 500
#define MAX_TEMP 100

/* un quadruplet : (op, arg1, arg2, res) */
typedef struct {
    char op[10];
    char arg1[20];
    char arg2[20];
    char res[20];
} Quadruplet;

extern Quadruplet quads[MAX_QUADS];
extern int qc;          /* compteur de quadruplets */
extern int temp_count;   /* compteur de temporaires */

void quad_init(void);
void generer(const char *op, const char *arg1, const char *arg2, const char *res);
char* temp_nouveau(void);
char* int_to_str(int v);
void quad_afficher(void);

#endif
