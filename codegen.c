#include "codegen.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static FILE *out;

static int est_nombre_asm(const char *s) {
    int i = 0;
    if (s[0] == '\0') return 0;
    if (s[0] == '-' || s[0] == '+') i = 1;
    while (s[i] != '\0') {
        if (!isdigit(s[i]) && s[i] != '.') return 0;
        i++;
    }
    return 1;
}

/* charge une valeur dans AX : soit un immediat soit une variable */
static void charger_ax(const char *arg) {
    if (est_nombre_asm(arg))
        fprintf(out, "    MOV AX, %s\n", arg);
    else
        fprintf(out, "    MOV AX, %s\n", arg);
}

/* generer la section .data avec les variables declarees */
static void generer_data(void) {
    int i;
    fprintf(out, ".DATA\n");
    for (i = 0; i < ts.nb; i++) {
        if (ts.entries[i].nature == NATURE_TAB) {
            fprintf(out, "    %s DW %d DUP(0)\n", ts.entries[i].nom, ts.entries[i].taille);
        } else if (ts.entries[i].nature == NATURE_CONST) {
            if (ts.entries[i].type == TYPE_FLOAT)
                fprintf(out, "    %s DW 0    ; FLOAT = %.2f (pas supporte en 8086 entier)\n",
                    ts.entries[i].nom, ts.entries[i].val.val_float);
            else
                fprintf(out, "    %s DW %d\n", ts.entries[i].nom, ts.entries[i].val.val_int);
        } else {
            fprintf(out, "    %s DW 0\n", ts.entries[i].nom);
        }
    }
    /* variables temporaires */
    for (i = 0; i < temp_count; i++) {
        fprintf(out, "    T%d DW 0\n", i);
    }
    fprintf(out, "\n");
}

/* generer la section .code a partir des quadruplets */
static void generer_code(void) {
    int i;
    fprintf(out, ".CODE\n");
    fprintf(out, "    MOV AX, @DATA\n");
    fprintf(out, "    MOV DS, AX\n\n");

    for (i = 0; i < qc; i++) {
        /* ignorer les NOP (quadruplets supprimes par l'optimisation) */
        if (strcmp(quads[i].op, "NOP") == 0)
            continue;

        /* affectation : res = arg1 */
        if (strcmp(quads[i].op, "=") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    MOV %s, AX\n", quads[i].res);
        }
        /* addition */
        else if (strcmp(quads[i].op, "+") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    ADD AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, AX\n", quads[i].res);
        }
        /* soustraction */
        else if (strcmp(quads[i].op, "-") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    SUB AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, AX\n", quads[i].res);
        }
        /* multiplication */
        else if (strcmp(quads[i].op, "*") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    MOV BX, %s\n", quads[i].arg2);
            fprintf(out, "    MUL BX\n");
            fprintf(out, "    MOV %s, AX\n", quads[i].res);
        }
        /* division */
        else if (strcmp(quads[i].op, "/") == 0) {
            fprintf(out, "    MOV DX, 0\n");
            charger_ax(quads[i].arg1);
            fprintf(out, "    MOV BX, %s\n", quads[i].arg2);
            fprintf(out, "    DIV BX\n");
            fprintf(out, "    MOV %s, AX\n", quads[i].res);
        }
        /* comparaisons : on utilise CMP + les flags */
        else if (strcmp(quads[i].op, ">") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    CMP AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, 0\n", quads[i].res);
            fprintf(out, "    JLE SUITE_%d\n", i);
            fprintf(out, "    MOV %s, 1\n", quads[i].res);
            fprintf(out, "SUITE_%d:\n", i);
        }
        else if (strcmp(quads[i].op, "<") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    CMP AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, 0\n", quads[i].res);
            fprintf(out, "    JGE SUITE_%d\n", i);
            fprintf(out, "    MOV %s, 1\n", quads[i].res);
            fprintf(out, "SUITE_%d:\n", i);
        }
        else if (strcmp(quads[i].op, ">=") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    CMP AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, 0\n", quads[i].res);
            fprintf(out, "    JL SUITE_%d\n", i);
            fprintf(out, "    MOV %s, 1\n", quads[i].res);
            fprintf(out, "SUITE_%d:\n", i);
        }
        else if (strcmp(quads[i].op, "<=") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    CMP AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, 0\n", quads[i].res);
            fprintf(out, "    JG SUITE_%d\n", i);
            fprintf(out, "    MOV %s, 1\n", quads[i].res);
            fprintf(out, "SUITE_%d:\n", i);
        }
        else if (strcmp(quads[i].op, "==") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    CMP AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, 0\n", quads[i].res);
            fprintf(out, "    JNE SUITE_%d\n", i);
            fprintf(out, "    MOV %s, 1\n", quads[i].res);
            fprintf(out, "SUITE_%d:\n", i);
        }
        else if (strcmp(quads[i].op, "!=") == 0) {
            charger_ax(quads[i].arg1);
            fprintf(out, "    CMP AX, %s\n", quads[i].arg2);
            fprintf(out, "    MOV %s, 0\n", quads[i].res);
            fprintf(out, "    JE SUITE_%d\n", i);
            fprintf(out, "    MOV %s, 1\n", quads[i].res);
            fprintf(out, "SUITE_%d:\n", i);
        }
        /* label */
        else if (strcmp(quads[i].op, "LABEL") == 0) {
            fprintf(out, "%s:\n", quads[i].arg1);
        }
        /* saut inconditionnel */
        else if (strcmp(quads[i].op, "BR") == 0) {
            fprintf(out, "    JMP %s\n", quads[i].res);
        }
        /* saut si zero (condition fausse) */
        else if (strcmp(quads[i].op, "BZ") == 0) {
            fprintf(out, "    MOV AX, %s\n", quads[i].arg1);
            fprintf(out, "    CMP AX, 0\n");
            fprintf(out, "    JE %s\n", quads[i].res);
        }
        /* saut si non zero (condition vraie) */
        else if (strcmp(quads[i].op, "BNZ") == 0) {
            fprintf(out, "    MOV AX, %s\n", quads[i].arg1);
            fprintf(out, "    CMP AX, 0\n");
            fprintf(out, "    JNE %s\n", quads[i].res);
        }
        /* WRITE : afficher via interruption DOS */
        else if (strcmp(quads[i].op, "WRITE") == 0) {
            fprintf(out, "    ; WRITE %s\n", quads[i].arg1);
            fprintf(out, "    MOV AX, %s\n", quads[i].arg1);
            fprintf(out, "    ; appel affichage\n");
            fprintf(out, "    CALL AFFICHE\n");
        }
        /* READ : lire via interruption DOS */
        else if (strcmp(quads[i].op, "READ") == 0) {
            fprintf(out, "    ; READ %s\n", quads[i].res);
            fprintf(out, "    CALL LIRE\n");
            fprintf(out, "    MOV %s, AX\n", quads[i].res);
        }
    }

    fprintf(out, "\n    ; fin du programme\n");
    fprintf(out, "    MOV AX, 4C00h\n");
    fprintf(out, "    INT 21h\n");
}

void generer_asm8086(const char *fichier_sortie) {
    out = fopen(fichier_sortie, "w");
    if (!out) {
        printf("Erreur : impossible de creer %s\n", fichier_sortie);
        return;
    }

    fprintf(out, "; Code assembleur 8086 genere par le compilateur MiniAlgo\n");
    fprintf(out, ".MODEL SMALL\n");
    fprintf(out, ".STACK 100h\n\n");

    generer_data();
    generer_code();

    fprintf(out, "\nEND\n");
    fclose(out);

    printf("Code assembleur 8086 genere dans : %s\n", fichier_sortie);
}
