# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Projet

Compilateur pour le langage MiniAlgo (projet universitaire L3 IL, USTHB). Utilise Flex pour l'analyse lexicale et Bison pour l'analyse syntaxique/sémantique, avec génération de code intermédiaire sous forme de quadruplets.

## Build

Prérequis : gcc, flex, bison, make (tous dispo via MSYS2 sur Windows).

Sur cette machine, flex/bison/make sont dans `/c/msys64/usr/bin/` — il faut les ajouter au PATH :
```
export PATH="/c/msys64/usr/bin:$PATH"
```

Compilation (nécessite override du TMPDIR à cause de permissions Windows) :
```
export TMPDIR="$PWD" TMP="$PWD" TEMP="$PWD"
make
```

Exécution :
```
./minialgo tests/test1.algo
```

Nettoyage : `make clean`

## Architecture

```
lexer.l         → analyseur lexical (Flex), produit les tokens
parser.y        → grammaire + actions sémantiques + main() (Bison)
ts.h / ts.c     → table des symboles (tableau linéaire, recherche/insertion)
quad.h / quad.c → génération et affichage des quadruplets
tests/          → programmes .algo de test
```

**Flux de compilation** : `fichier.algo` → lexer (tokens) → parser (arbre syntaxique + vérifications sémantiques) → quadruplets.

Le parser (`parser.y`) contient le `main()`. Il appelle `ts_init()` et `quad_init()`, lance `yyparse()`, puis affiche la table des symboles et les quadruplets.

## Langage MiniAlgo — points clés

- Structure : `PROGRAM nom DECL ... ENDDECL BEGIN ... END`
- Types : `INTEGER` (plage -32768..32767), `FLOAT`
- Identificateurs : max 8 caractères, commence par une lettre
- Valeurs signées entre parenthèses : `(-5)`, `(+3.14)`
- Boucle FOR spéciale : `FOR (i : debut : pas : fin) { ... }`
- Commentaires : `//` et `/* ... */`

## Erreurs détectées

- Lexicales : caractère invalide, identifiant trop long, entier hors plage
- Syntaxiques : format `Erreur Syntaxique : ligne X, colonne Y, ...`
- Sémantiques : variable non déclarée, double déclaration, incompatibilité de type, division par zéro, modification de constante, accès tableau invalide
