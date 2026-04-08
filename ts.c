#include "ts.h"

/* table des symboles globale */
TableSymboles ts;

void ts_init(void) {
    ts.nb = 0;
    memset(ts.entries, 0, sizeof(ts.entries));
}

/* retourne l'index si trouve, -1 sinon */
int ts_rechercher(const char *nom) {
    int i;
    for (i = 0; i < ts.nb; i++) {
        if (strcmp(ts.entries[i].nom, nom) == 0)
            return i;
    }
    return -1;
}

/* insere un nouveau symbole, retourne l'index ou -1 si erreur */
int ts_inserer(const char *nom, TypeVar type, NatureSymb nature, int taille) {
    /* verifier double declaration */
    if (ts_rechercher(nom) != -1) {
        return -1;
    }
    /* verifier debordement */
    if (ts.nb >= TAILLE_TABLE) {
        fprintf(stderr, "Erreur : table des symboles pleine\n");
        return -1;
    }

    Symbole *s = &ts.entries[ts.nb];
    strncpy(s->nom, nom, MAX_IDF);
    s->nom[MAX_IDF] = '\0';
    s->type = type;
    s->nature = nature;
    s->taille = taille;
    s->is_init = 0;
    s->val.val_int = 0;

    ts.nb++;
    return ts.nb - 1;
}

const char* type_to_str(TypeVar t) {
    switch (t) {
        case TYPE_INTEGER: return "INTEGER";
        case TYPE_FLOAT:   return "FLOAT";
        default:           return "???";
    }
}

const char* nature_to_str(NatureSymb n) {
    switch (n) {
        case NATURE_VAR:   return "Variable";
        case NATURE_CONST: return "Constante";
        case NATURE_TAB:   return "Tableau";
        default:           return "???";
    }
}

void ts_afficher(void) {
    int i;
    printf("\n====== TABLE DES SYMBOLES ======\n");
    printf("%-10s %-10s %-12s %-8s %-8s\n",
           "Nom", "Type", "Nature", "Taille", "Init");
    printf("------------------------------------------------------\n");
    for (i = 0; i < ts.nb; i++) {
        Symbole *s = &ts.entries[i];
        printf("%-10s %-10s %-12s %-8d %-8s\n",
               s->nom,
               type_to_str(s->type),
               nature_to_str(s->nature),
               s->taille,
               s->is_init ? "oui" : "non");
    }
    printf("================================\n\n");
}
