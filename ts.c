#include "ts.h"

TableSymboles ts;

void ts_init(void) {
    ts.nb = 0;
}

/* chercher un symbole par son nom, retourne son index ou -1 */
int ts_rechercher(const char *nom) {
    int i;
    for (i = 0; i < ts.nb; i++) {
        if (strcmp(ts.entries[i].nom, nom) == 0)
            return i;
    }
    return -1;
}

/* ajouter un symbole dans la table, retourne -1 si deja existant */
int ts_inserer(const char *nom, TypeVar type, NatureSymb nature, int taille) {
    if (ts_rechercher(nom) != -1)
        return -1;

    if (ts.nb >= TAILLE_TABLE) {
        printf("Erreur : table des symboles pleine\n");
        return -1;
    }

    strncpy(ts.entries[ts.nb].nom, nom, MAX_IDF);
    ts.entries[ts.nb].nom[MAX_IDF] = '\0';
    ts.entries[ts.nb].type = type;
    ts.entries[ts.nb].nature = nature;
    ts.entries[ts.nb].taille = taille;
    ts.entries[ts.nb].is_init = 0;
    ts.entries[ts.nb].val.val_int = 0;

    ts.nb++;
    return ts.nb - 1;
}

const char* type_to_str(TypeVar t) {
    if (t == TYPE_INTEGER) return "INTEGER";
    if (t == TYPE_FLOAT) return "FLOAT";
    return "?";
}

const char* nature_to_str(NatureSymb n) {
    if (n == NATURE_VAR) return "Variable";
    if (n == NATURE_CONST) return "Constante";
    if (n == NATURE_TAB) return "Tableau";
    return "?";
}

void ts_afficher(void) {
    int i;
    printf("\n========= TABLE DES SYMBOLES =========\n");
    printf("Nom\t\tType\t\tNature\t\tTaille\tInit\n");
    printf("--------------------------------------------------\n");
    for (i = 0; i < ts.nb; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t%s\n",
            ts.entries[i].nom,
            type_to_str(ts.entries[i].type),
            nature_to_str(ts.entries[i].nature),
            ts.entries[i].taille,
            ts.entries[i].is_init ? "oui" : "non");
    }
    printf("==========================================\n\n");
}
