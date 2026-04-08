#include "quad.h"

Quadruplet quads[MAX_QUADS];
int qc = 0;
int temp_count = 0;

static char temp_buf[MAX_TEMP][20];
static char conv_buf[20];

void quad_init(void) {
    qc = 0;
    temp_count = 0;
}

void generer(const char *op, const char *arg1, const char *arg2, const char *res) {
    if (qc >= MAX_QUADS) {
        printf("Erreur : trop de quadruplets\n");
        return;
    }

    strcpy(quads[qc].op, op);

    if (arg1 != NULL)
        strcpy(quads[qc].arg1, arg1);
    else
        strcpy(quads[qc].arg1, "");

    if (arg2 != NULL)
        strcpy(quads[qc].arg2, arg2);
    else
        strcpy(quads[qc].arg2, "");

    if (res != NULL)
        strcpy(quads[qc].res, res);
    else
        strcpy(quads[qc].res, "");

    qc++;
}

/* cree un temporaire T0, T1, T2, etc. */
char* temp_nouveau(void) {
    sprintf(temp_buf[temp_count], "T%d", temp_count);
    temp_count++;
    return temp_buf[temp_count - 1];
}

char* int_to_str(int v) {
    sprintf(conv_buf, "%d", v);
    return conv_buf;
}

void quad_afficher(void) {
    int i;
    printf("\n========= QUADRUPLETS =========\n");
    printf("N\tOP\tARG1\tARG2\tRES\n");
    printf("---------------------------------------\n");
    for (i = 0; i < qc; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n",
            i, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
    }
    printf("================================\n\n");
}
