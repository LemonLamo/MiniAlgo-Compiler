%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "parser.tab.h"

int nb_ligne = 1;
int nb_col = 1;

/* mise a jour de la colonne apres chaque token */
#define MAJ_COL nb_col += yyleng;
%}

%option noyywrap

%%

 /* ---- commentaires ---- */
"//"[^\n]*          { /* commentaire une ligne, on ignore */ MAJ_COL; }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* commentaire multi-lignes */
    int i;
    for (i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') { nb_ligne++; nb_col = 1; }
        else nb_col++;
    }
}

 /* ---- mots cles ---- */
"PROGRAM"       { MAJ_COL; return MC_PROGRAM; }
"DECL"          { MAJ_COL; return MC_DECL; }
"ENDDECL"       { MAJ_COL; return MC_ENDDECL; }
"BEGIN"         { MAJ_COL; return MC_BEGIN; }
"END"           { MAJ_COL; return MC_END; }
"INTEGER"       { MAJ_COL; return MC_INTEGER; }
"FLOAT"         { MAJ_COL; return MC_FLOAT; }
"CONST"         { MAJ_COL; return MC_CONST; }
"IF"            { MAJ_COL; return MC_IF; }
"ELSE"          { MAJ_COL; return MC_ELSE; }
"FOR"           { MAJ_COL; return MC_FOR; }
"WHILE"         { MAJ_COL; return MC_WHILE; }
"READ"          { MAJ_COL; return MC_READ; }
"WRITE"         { MAJ_COL; return MC_WRITE; }

 /* ---- operateurs logiques ---- */
"&&"            { MAJ_COL; return OP_AND; }
"||"            { MAJ_COL; return OP_OR; }
"!"             { MAJ_COL; return OP_NOT; }

 /* ---- operateurs de comparaison ---- */
"=="            { MAJ_COL; return OP_EQ; }
"!="            { MAJ_COL; return OP_NEQ; }
">="            { MAJ_COL; return OP_GE; }
"<="            { MAJ_COL; return OP_LE; }
">"             { MAJ_COL; return OP_GT; }
"<"             { MAJ_COL; return OP_LT; }

 /* ---- operateurs arithmetiques ---- */
"+"             { MAJ_COL; return '+'; }
"-"             { MAJ_COL; return '-'; }
"*"             { MAJ_COL; return '*'; }
"/"             { MAJ_COL; return '/'; }

 /* ---- affectation ---- */
"="             { MAJ_COL; return '='; }

 /* ---- delimiteurs ---- */
";"             { MAJ_COL; return ';'; }
","             { MAJ_COL; return ','; }
":"             { MAJ_COL; return ':'; }
"("             { MAJ_COL; return '('; }
")"             { MAJ_COL; return ')'; }
"{"             { MAJ_COL; return '{'; }
"}"             { MAJ_COL; return '}'; }
"["             { MAJ_COL; return '['; }
"]"             { MAJ_COL; return ']'; }

 /* ---- constantes reelles (avant entiers pour eviter conflit) ---- */
[0-9]+\.[0-9]+  {
    MAJ_COL;
    yylval.reel = atof(yytext);
    return CST_FLOAT;
}

 /* ---- constantes entieres ---- */
[0-9]+          {
    MAJ_COL;
    yylval.entier = atoi(yytext);
    /* verification de la plage INTEGER */
    if (yylval.entier > 32767) {
        printf("Erreur Lexicale : ligne %d, colonne %d, entier hors plage : %s\n",
               nb_ligne, nb_col - yyleng, yytext);
    }
    return CST_INT;
}

 /* ---- identificateurs ---- */
[a-zA-Z][a-zA-Z0-9_]* {
    MAJ_COL;
    if (yyleng > MAX_IDF) {
        printf("Erreur Lexicale : ligne %d, colonne %d, identificateur trop long : %s\n",
               nb_ligne, nb_col - yyleng, yytext);
    }
    strncpy(yylval.str, yytext, MAX_IDF);
    yylval.str[MAX_IDF] = '\0';
    return IDF;
}

 /* ---- espaces et retours a la ligne ---- */
\n              { nb_ligne++; nb_col = 1; }
[ \t\r]+        { MAJ_COL; }

 /* ---- caractere non reconnu = erreur lexicale ---- */
.               {
    printf("Erreur Lexicale : ligne %d, colonne %d, caractere inattendu : '%s'\n",
           nb_ligne, nb_col, yytext);
    MAJ_COL;
}

%%
