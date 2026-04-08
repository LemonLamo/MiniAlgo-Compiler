

## Comment compiler et lancer

```bash
# ajouter flex/bison au PATH (une seule fois par terminal)
export PATH="/c/msys64/usr/bin:$PATH"
export TMPDIR="$PWD" TMP="$PWD" TEMP="$PWD"

# compiler
make clean
make

# lancer sur un fichier
./minialgo tests/test1.algo
```

---

## Scenario de demo devant le prof

### 1. Programme qui marche bien (test1.algo)

```
./minialgo tests/test1.algo
```

Ce qu'il faut montrer :
- "Compilation terminee avec succes" → pas d'erreur
- La table des symboles contient A, B (INTEGER), X (FLOAT), T (Tableau de 10), MAX et PI (Constantes)
- Les quadruplets montrent les affectations, la condition IF/ELSE avec labels, la boucle WHILE avec BR/BZ

### 2. Detection des erreurs semantiques (test_erreurs.algo)

```
./minialgo tests/test_erreurs.algo
```

Ce qu'il faut montrer :
- Double declaration de A → "Erreur Semantique : ligne 4, double declaration de 'A'"
- Variable Z pas declaree → "Erreur Semantique : ligne 8, variable 'Z' non declaree"
- Division par zero → "Erreur Semantique : ligne 9, division par zero"

### 3. Boucle FOR (test_for.algo)

```
./minialgo tests/test_for.algo
```

Ce qu'il faut montrer :
- Le FOR genere : initialisation (i=debut), un LABEL, le corps, l'increment (i=i+pas), la condition (i<=fin), et BNZ pour retourner au label
- C'est la traduction en quadruplets d'une boucle for classique

### 4. Tableaux (test_tab.algo)

```
./minialgo tests/test_tab.algo
```

Ce qu'il faut montrer :
- Les acces tableau sont geres : T[0], T[1], T[2]
- Le compilateur genere des temporaires pour les acces tableau (T[0] → T0)

### 5. Incompatibilite de type (test_types.algo)

```
./minialgo tests/test_types.algo
```

Ce qu'il faut montrer :
- `A = X ;` declenche une erreur car A est INTEGER et X est FLOAT
- Le compilateur detecte l'incompatibilite de type

### 6. Valeurs signees (test_signe.algo)

```
./minialgo tests/test_signe.algo
```

Ce qu'il faut montrer :
- (-5), (+12), (-2.7) sont reconnus correctement
- Les valeurs signees doivent etre entre parentheses comme dit dans le sujet

### 7. Erreur syntaxique (test_syntax_err.algo)

```
./minialgo tests/test_syntax_err.algo
```

Ce qu'il faut montrer :
- Le point-virgule manquant apres `A = 5 + 3` est detecte
- Le message donne la ligne et la colonne

---

## Explication de chaque fichier (pour la soutenance)

### lexer.l (l'analyseur lexical)
- C'est le fichier Flex. Il decoupe le code source en tokens (mots cles, identifiants, nombres, operateurs...)
- Il ignore les commentaires // et /* */
- Il compte les lignes et colonnes pour les messages d'erreur
- Il detecte les erreurs lexicales : identifiant trop long (>8 chars), entier hors plage (>32767), caractere inconnu

### parser.y (l'analyseur syntaxique + semantique)
- C'est le fichier Bison. Il contient la grammaire du langage MiniAlgo
- La grammaire verifie la structure : PROGRAM ... DECL ... ENDDECL ... BEGIN ... END
- Les actions semantiques verifient : variable non declaree, double declaration, type incompatible, division par zero, modification de constante
- Il genere les quadruplets pendant l'analyse (traduction dirigee par la syntaxe)

### ts.h / ts.c (table des symboles)
- Tableau de structures. Chaque entree a : nom, type, nature (var/const/tab), taille, valeur
- `ts_rechercher` : parcourt le tableau pour trouver un nom
- `ts_inserer` : ajoute une entree, retourne -1 si le nom existe deja
- `ts_afficher` : affiche tout le contenu de la table

### quad.h / quad.c (quadruplets)
- Un quadruplet = (operateur, argument1, argument2, resultat)
- `generer` : ajoute un quadruplet dans le tableau
- `temp_nouveau` : cree un temporaire T0, T1, T2... pour stocker les resultats intermediaires
- Les labels (L0, L1...) servent pour les sauts (conditions, boucles)

---

## Questions que le prof peut poser (et les reponses)

### Q: Pourquoi utiliser Flex et Bison et pas tout coder a la main ?
Flex genere automatiquement un automate fini pour reconnaitre les tokens, c'est plus fiable que de coder un lexer a la main. Bison genere un parser LALR(1) a partir de la grammaire, ce qui garantit qu'on gere bien toutes les regles de production sans oublier de cas.

### Q: C'est quoi un quadruplet ?
C'est une instruction a 3 adresses sous la forme (op, arg1, arg2, res). Par exemple `A = B + 5` donne le quadruplet (+, B, 5, T0) puis (=, T0, , A). C'est une representation intermediaire entre le code source et le code machine.

### Q: Pourquoi des temporaires T0, T1, T2... ?
Quand on a une expression comme `A + B * C`, il faut d'abord calculer B*C et stocker le resultat quelque part avant de faire l'addition. Les temporaires servent a ca. C'est comme des registres virtuels.

### Q: Comment tu geres les boucles en quadruplets ?
Avec des labels et des sauts. Pour WHILE : on met un LABEL au debut, on evalue la condition, si faux on saute a la fin (BZ = branch if zero), a la fin du corps on fait un BR (branch) vers le label du debut. Pour FOR c'est pareil mais on ajoute l'initialisation avant et l'increment apres le corps.

### Q: Comment tu detectes la double declaration ?
Dans `ts_inserer`, avant d'ajouter un symbole, on appelle `ts_rechercher` pour verifier si le nom existe deja. Si oui, on retourne -1 et le parser affiche l'erreur.

### Q: Comment tu geres la compatibilite de type ?
Chaque expression a un type (0 = INTEGER, 1 = FLOAT). Quand on fait une operation entre un INTEGER et un FLOAT, le resultat est FLOAT. Lors de l'affectation, si on essaie de mettre un FLOAT dans un INTEGER, on signale l'erreur.

### Q: Quelle est la difference entre BZ et BNZ ?
BZ = "Branch if Zero" : on saute si la condition est fausse (0). C'est utilise pour sortir d'un WHILE quand la condition n'est plus vraie. BNZ = "Branch if Not Zero" : on saute si la condition est vraie. C'est utilise dans le FOR pour retourner au debut tant que i <= fin.

### Q: Comment tu geres les commentaires ?
Dans le lexer (lexer.l), les commentaires sont reconnus par des expressions regulieres mais aucun token n'est retourne. Le lexer les ignore tout simplement. Pour les commentaires multi-lignes, on compte les \n pour garder le bon numero de ligne.

### Q: C'est quoi la difference entre erreur lexicale, syntaxique et semantique ?
- Lexicale : le texte ne forme pas un token valide (ex: caractere @ inconnu, identifiant trop long)
- Syntaxique : les tokens sont valides mais leur enchainement ne respecte pas la grammaire (ex: point-virgule manquant)
- Semantique : la syntaxe est correcte mais le sens est faux (ex: utiliser une variable jamais declaree, diviser par zero)

### Q: Pourquoi la table des symboles est un tableau et pas une table de hachage ?
Pour un petit langage comme MiniAlgo avec peu de variables, un tableau simple suffit. La recherche est en O(n) mais n est toujours petit. Une table de hachage serait plus performante pour un vrai compilateur avec des milliers de symboles.

### Q: Comment tu geres les tableaux dans la table des symboles ?
Un tableau est insere avec nature = NATURE_TAB et sa taille. Lors de l'acces T[i], on verifie que T est bien declare comme tableau. Les acces sont traduits en quadruplets avec la notation T[index].

### Q: Qu'est-ce que %union dans Bison ?
C'est pour definir les differents types de valeurs semantiques. Un token IDF porte une chaine de caracteres (le nom), un CST_INT porte un entier, une expression porte un nom de temporaire et un type. Bison utilise ca pour typer les $1, $2, $3 dans les actions.

### Q: Comment le lexer et le parser communiquent ?
Le parser appelle yylex() a chaque fois qu'il a besoin d'un nouveau token. Le lexer retourne le type du token (MC_IF, IDF, CST_INT...) et met la valeur dans yylval (via %union). Le parser utilise ensuite ces valeurs dans ses actions semantiques.
