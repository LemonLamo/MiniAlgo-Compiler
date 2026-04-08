%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "quad.h"

extern int nb_ligne;
extern int nb_col;
extern FILE *yyin;
extern char *yytext;

int yylex(void);
void yyerror(const char *s);

/* type courant pour les declarations */
static TypeVar type_courant;
static int nb_erreurs = 0;

/* pour generer les etiquettes */
static int label_count = 0;
static char* label_nouveau(void) {
    static char buf[20];
    sprintf(buf, "L%d", label_count++);
    return buf;
}
%}

/* types pour les valeurs semantiques */
%union {
    int entier;
    float reel;
    char str[9];   /* MAX_IDF + 1 */
    struct {
        char nom[20];
        int type;   /* 0 = INTEGER, 1 = FLOAT */
    } expr;
}

/* tokens */
%token MC_PROGRAM MC_DECL MC_ENDDECL MC_BEGIN MC_END
%token MC_INTEGER MC_FLOAT MC_CONST
%token MC_IF MC_ELSE MC_FOR MC_WHILE
%token MC_READ MC_WRITE
%token OP_AND OP_OR OP_NOT
%token OP_EQ OP_NEQ OP_GE OP_LE OP_GT OP_LT

%token <entier> CST_INT
%token <reel> CST_FLOAT
%token <str> IDF

%type <expr> expression terme facteur condition

/* priorite des operateurs */
%left OP_OR
%left OP_AND
%left OP_EQ OP_NEQ
%left OP_GT OP_LT OP_GE OP_LE
%left '+' '-'
%left '*' '/'
%right OP_NOT

%%

programme
    : MC_PROGRAM IDF MC_DECL declarations MC_ENDDECL MC_BEGIN instructions MC_END
        {
            if (nb_erreurs == 0)
                printf("Compilation terminee avec succes.\n");
            else
                printf("Compilation terminee avec %d erreur(s).\n", nb_erreurs);
        }
    ;

declarations
    : declarations declaration
    | /* vide */
    ;

declaration
    : type_decl ':' liste_var ';'
    | type_decl ':' IDF '[' CST_INT ']' ';'
        {
            if ($5 <= 0) {
                printf("Erreur Semantique : ligne %d, taille de tableau invalide pour '%s'\n",
                       nb_ligne, $3);
                nb_erreurs++;
            } else {
                int idx = ts_inserer($3, type_courant, NATURE_TAB, $5);
                if (idx == -1) {
                    printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                           nb_ligne, $3);
                    nb_erreurs++;
                }
            }
        }
    | MC_CONST IDF '=' CST_INT ';'
        {
            int idx = ts_inserer($2, TYPE_INTEGER, NATURE_CONST, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                       nb_ligne, $2);
                nb_erreurs++;
            } else {
                ts.entries[idx].val.val_int = $4;
                ts.entries[idx].is_init = 1;
            }
        }
    | MC_CONST IDF '=' CST_FLOAT ';'
        {
            int idx = ts_inserer($2, TYPE_FLOAT, NATURE_CONST, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                       nb_ligne, $2);
                nb_erreurs++;
            } else {
                ts.entries[idx].val.val_float = $4;
                ts.entries[idx].is_init = 1;
            }
        }
    ;

type_decl
    : MC_INTEGER    { type_courant = TYPE_INTEGER; }
    | MC_FLOAT      { type_courant = TYPE_FLOAT; }
    ;

liste_var
    : liste_var ',' IDF
        {
            int idx = ts_inserer($3, type_courant, NATURE_VAR, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                       nb_ligne, $3);
                nb_erreurs++;
            }
        }
    | IDF
        {
            int idx = ts_inserer($1, type_courant, NATURE_VAR, 1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, double declaration de '%s'\n",
                       nb_ligne, $1);
                nb_erreurs++;
            }
        }
    ;

instructions
    : instructions instruction
    | /* vide */
    ;

instruction
    : affectation
    | condition_instr
    | boucle_for
    | boucle_while
    | ecriture
    | lecture
    ;

/* --- Affectation --- */
affectation
    : IDF '=' expression ';'
        {
            int idx = ts_rechercher($1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                       nb_ligne, $1);
                nb_erreurs++;
            } else if (ts.entries[idx].nature == NATURE_CONST) {
                printf("Erreur Semantique : ligne %d, modification de la constante '%s' interdite\n",
                       nb_ligne, $1);
                nb_erreurs++;
            } else {
                /* verif compatibilite de type */
                if (ts.entries[idx].type == TYPE_INTEGER && $3.type == 1) {
                    printf("Erreur Semantique : ligne %d, incompatibilite de type pour '%s' (INTEGER attendu)\n",
                           nb_ligne, $1);
                    nb_erreurs++;
                }
                generer("=", $3.nom, "", $1);
                ts.entries[idx].is_init = 1;
            }
        }
    | IDF '[' expression ']' '=' expression ';'
        {
            int idx = ts_rechercher($1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, tableau '%s' non declare\n",
                       nb_ligne, $1);
                nb_erreurs++;
            } else if (ts.entries[idx].nature != NATURE_TAB) {
                printf("Erreur Semantique : ligne %d, '%s' n'est pas un tableau\n",
                       nb_ligne, $1);
                nb_erreurs++;
            } else {
                /* generer acces tableau */
                char buf[30];
                sprintf(buf, "%s[%s]", $1, $3.nom);
                generer("=", $6.nom, "", buf);
            }
        }
    ;

/* --- Condition IF / ELSE --- */
condition_instr
    : MC_IF '(' condition ')' '{' instructions '}'
        {
            char lbl_fin[20];
            strcpy(lbl_fin, label_nouveau());
            /* on a deja genere le saut conditionnel dans 'condition' */
            /* ici on met le label de fin du if */
            generer("LABEL", lbl_fin, "", "");
        }
    | MC_IF '(' condition ')' '{' instructions '}' MC_ELSE
        {
            /* saut pour eviter le else */
            char *lbl_else_fin = label_nouveau();
            generer("BR", "", "", lbl_else_fin);
            /* label debut else */
            char *lbl_else = label_nouveau();
            generer("LABEL", lbl_else, "", "");
        }
      '{' instructions '}'
        {
            /* label fin else -- on recupere le dernier label genere */
            char lbl[20];
            sprintf(lbl, "L%d", label_count - 2);
            generer("LABEL", lbl, "", "");
        }
    ;

condition
    : expression OP_GT expression
        {
            char *t = temp_nouveau();
            generer(">", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | expression OP_LT expression
        {
            char *t = temp_nouveau();
            generer("<", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | expression OP_GE expression
        {
            char *t = temp_nouveau();
            generer(">=", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | expression OP_LE expression
        {
            char *t = temp_nouveau();
            generer("<=", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | expression OP_EQ expression
        {
            char *t = temp_nouveau();
            generer("==", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | expression OP_NEQ expression
        {
            char *t = temp_nouveau();
            generer("!=", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | condition OP_AND condition
        {
            char *t = temp_nouveau();
            generer("&&", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | condition OP_OR condition
        {
            char *t = temp_nouveau();
            generer("||", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | OP_NOT condition
        {
            char *t = temp_nouveau();
            generer("!", $2.nom, "", t);
            strcpy($$.nom, t);
            $$.type = 0;
        }
    | '(' condition ')'
        {
            strcpy($$.nom, $2.nom);
            $$.type = $2.type;
        }
    ;

/* --- Boucle FOR --- */
boucle_for
    : MC_FOR '(' IDF ':' expression ':' expression ':' expression ')'
        {
            int idx = ts_rechercher($3);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                       nb_ligne, $3);
                nb_erreurs++;
            }
            /* i = debut */
            generer("=", $5.nom, "", $3);
        }
      '{' instructions '}'
        {
            /* i = i + pas */
            char *t = temp_nouveau();
            generer("+", $3, $7.nom, t);
            generer("=", t, "", $3);
            /* condition i <= fin et saut */
            char *cond = temp_nouveau();
            generer("<=", $3, $9.nom, cond);
            char lbl[20];
            sprintf(lbl, "L%d", label_count - 1);
            generer("BZ", cond, "", lbl);
        }
    ;

/* --- Boucle WHILE --- */
boucle_while
    : MC_WHILE
        {
            char *lbl_debut = label_nouveau();
            generer("LABEL", lbl_debut, "", "");
        }
      '(' condition ')'
        {
            char *lbl_fin = label_nouveau();
            generer("BZ", $4.nom, "", lbl_fin);
        }
      '{' instructions '}'
        {
            /* saut retour au debut */
            char lbl_deb[20];
            sprintf(lbl_deb, "L%d", label_count - 2);
            generer("BR", "", "", lbl_deb);
            /* label fin */
            char lbl_fin[20];
            sprintf(lbl_fin, "L%d", label_count - 1);
            generer("LABEL", lbl_fin, "", "");
        }
    ;

/* --- WRITE / READ --- */
ecriture
    : MC_WRITE '(' expression ')' ';'
        {
            generer("WRITE", $3.nom, "", "");
        }
    ;

lecture
    : MC_READ '(' IDF ')' ';'
        {
            int idx = ts_rechercher($3);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                       nb_ligne, $3);
                nb_erreurs++;
            } else {
                generer("READ", "", "", $3);
                ts.entries[idx].is_init = 1;
            }
        }
    ;

/* --- Expressions arithmetiques --- */
expression
    : expression '+' terme
        {
            char *t = temp_nouveau();
            generer("+", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = ($1.type == 1 || $3.type == 1) ? 1 : 0;
        }
    | expression '-' terme
        {
            char *t = temp_nouveau();
            generer("-", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = ($1.type == 1 || $3.type == 1) ? 1 : 0;
        }
    | terme
        {
            strcpy($$.nom, $1.nom);
            $$.type = $1.type;
        }
    ;

terme
    : terme '*' facteur
        {
            char *t = temp_nouveau();
            generer("*", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = ($1.type == 1 || $3.type == 1) ? 1 : 0;
        }
    | terme '/' facteur
        {
            /* detection division par zero si c'est une constante */
            if (strcmp($3.nom, "0") == 0) {
                printf("Erreur Semantique : ligne %d, division par zero\n", nb_ligne);
                nb_erreurs++;
            }
            char *t = temp_nouveau();
            generer("/", $1.nom, $3.nom, t);
            strcpy($$.nom, t);
            $$.type = ($1.type == 1 || $3.type == 1) ? 1 : 0;
        }
    | facteur
        {
            strcpy($$.nom, $1.nom);
            $$.type = $1.type;
        }
    ;

facteur
    : IDF
        {
            int idx = ts_rechercher($1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, variable '%s' non declaree\n",
                       nb_ligne, $1);
                nb_erreurs++;
                strcpy($$.nom, $1);
                $$.type = 0;
            } else {
                strcpy($$.nom, $1);
                $$.type = (ts.entries[idx].type == TYPE_FLOAT) ? 1 : 0;
            }
        }
    | IDF '[' expression ']'
        {
            int idx = ts_rechercher($1);
            if (idx == -1) {
                printf("Erreur Semantique : ligne %d, tableau '%s' non declare\n",
                       nb_ligne, $1);
                nb_erreurs++;
            } else if (ts.entries[idx].nature != NATURE_TAB) {
                printf("Erreur Semantique : ligne %d, '%s' n'est pas un tableau\n",
                       nb_ligne, $1);
                nb_erreurs++;
            }
            char *t = temp_nouveau();
            char buf[30];
            sprintf(buf, "%s[%s]", $1, $3.nom);
            generer("=", buf, "", t);
            strcpy($$.nom, t);
            $$.type = (idx != -1) ? ((ts.entries[idx].type == TYPE_FLOAT) ? 1 : 0) : 0;
        }
    | CST_INT
        {
            sprintf($$.nom, "%d", $1);
            $$.type = 0;
        }
    | CST_FLOAT
        {
            sprintf($$.nom, "%.2f", $1);
            $$.type = 1;
        }
    | '(' expression ')'
        {
            strcpy($$.nom, $2.nom);
            $$.type = $2.type;
        }
    | '(' '+' CST_INT ')'
        {
            sprintf($$.nom, "%d", $3);
            $$.type = 0;
        }
    | '(' '-' CST_INT ')'
        {
            sprintf($$.nom, "%d", -$3);
            $$.type = 0;
        }
    | '(' '+' CST_FLOAT ')'
        {
            sprintf($$.nom, "%.2f", $3);
            $$.type = 1;
        }
    | '(' '-' CST_FLOAT ')'
        {
            sprintf($$.nom, "%.2f", -$3);
            $$.type = 1;
        }
    ;

%%

void yyerror(const char *s) {
    printf("Erreur Syntaxique : ligne %d, colonne %d, %s (pres de '%s')\n",
           nb_ligne, nb_col, s, yytext);
    nb_erreurs++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <fichier_source.algo>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Impossible d'ouvrir le fichier");
        return 1;
    }

    printf("=== Compilation de %s ===\n\n", argv[1]);

    ts_init();
    quad_init();

    yyparse();

    fclose(yyin);

    ts_afficher();
    quad_afficher();

    return nb_erreurs > 0 ? 1 : 0;
}
