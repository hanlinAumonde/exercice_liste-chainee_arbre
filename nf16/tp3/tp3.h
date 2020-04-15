#ifndef TP3_H
#define TP3_H
#endif //TP3_H
typedef struct element{
    int col;
    int val;
    struct element *next;
} element;

typedef element *liste_ligne;

typedef struct matrice_creuse {
    liste_ligne *lignes;
    int Nlignes;
    int Ncolonnes;
};

void remplirMat(matrice_creuse *m, int N, int M);

void afficherMat(matrice_creuse m);

int getValue(matrice_creuse m, int i, int j);

