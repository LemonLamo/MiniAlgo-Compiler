%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"
#include "parser.tab.h"

int nb_ligne = 1;
int nb_col = 1;
%}

%option noyywrap noinput nounput

%%

"//"[^\n]*              { /* commentaire une ligne */ }
"/*"([^*]|\*+[^*/])*\*+"/"  {
    /* commentaire multi-lignes : on compte les \n dedans */
    int i;
    for (i = 0; i < yyleng; i++) {
        if (yytext[i] == '\n') { nb_ligne++; nb_col = 1; }
        else nb_col++;
    }
}

"PROGRAM"   { nb_col += yyleng; return MC_PROGRAM; }
"DECL"      { nb_col += yyleng; return MC_DECL; }
"ENDDECL"   { nb_col += yyleng; return MC_ENDDECL; }
"BEGIN"     { nb_col += yyleng; return MC_BEGIN; }
"END"       { nb_col += yyleng; return MC_END; }
"INTEGER"   { nb_col += yyleng; return MC_INTEGER; }
"FLOAT"     { nb_col += yyleng; return MC_FLOAT; }
"CONST"     { nb_col += yyleng; return MC_CONST; }
"IF"        { nb_col += yyleng; return MC_IF; }
"ELSE"      { nb_col += yyleng; return MC_ELSE; }
"FOR"       { nb_col += yyleng; return MC_FOR; }
"WHILE"     { nb_col += yyleng; return MC_WHILE; }
"READ"      { nb_col += yyleng; return MC_READ; }
"WRITE"     { nb_col += yyleng; return MC_WRITE; }

"&&"    { nb_col += yyleng; return OP_AND; }
"||"    { nb_col += yyleng; return OP_OR; }
"!"     { nb_col += yyleng; return OP_NOT; }

"=="    { nb_col += yyleng; return OP_EQ; }
"!="    { nb_col += yyleng; return OP_NEQ; }
">="    { nb_col += yyleng; return OP_GE; }
"<="    { nb_col += yyleng; return OP_LE; }
">"     { nb_col += yyleng; return OP_GT; }
"<"     { nb_col += yyleng; return OP_LT; }

"+"     { nb_col += yyleng; return '+'; }
"-"     { nb_col += yyleng; return '-'; }
"*"     { nb_col += yyleng; return '*'; }
"/"     { nb_col += yyleng; return '/'; }
"="     { nb_col += yyleng; return '='; }

";"     { nb_col += yyleng; return ';'; }
","     { nb_col += yyleng; return ','; }
":"     { nb_col += yyleng; return ':'; }
"("     { nb_col += yyleng; return '('; }
")"     { nb_col += yyleng; return ')'; }
"{"     { nb_col += yyleng; return '{'; }
"}"     { nb_col += yyleng; return '}'; }
"["     { nb_col += yyleng; return '['; }
"]"     { nb_col += yyleng; return ']'; }

[0-9]+\.[0-9]+  {
    nb_col += yyleng;
    yylval.reel = atof(yytext);
    return CST_FLOAT;
}

[0-9]+  {
    nb_col += yyleng;
    yylval.entier = atoi(yytext);
    if (yylval.entier > 32767) {
        printf("Erreur Lexicale : ligne %d, colonne %d, entier hors plage : %s\n",
            nb_ligne, nb_col - yyleng, yytext);
    }
    return CST_INT;
}

[a-zA-Z][a-zA-Z0-9_]*  {
    nb_col += yyleng;
    if (yyleng > MAX_IDF) {
        printf("Erreur Lexicale : ligne %d, colonne %d, identificateur trop long : %s\n",
            nb_ligne, nb_col - yyleng, yytext);
    }
    strncpy(yylval.str, yytext, MAX_IDF);
    yylval.str[MAX_IDF] = '\0';
    return IDF;
}

\n          { nb_ligne++; nb_col = 1; }
[ \t\r]+    { nb_col += yyleng; }

.   {
    printf("Erreur Lexicale : ligne %d, colonne %d, caractere inattendu : '%s'\n",
        nb_ligne, nb_col, yytext);
    nb_col++;
}

%%
