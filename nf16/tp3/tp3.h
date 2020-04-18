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

void remplirMat(struct matrice_creuse *m, int N, int M);

void afficherMat(struct matrice_creuse m);

int getValue(struct matrice_creuse m, int i, int j);

void putValue(struct matrice_creuse m, int i, int j,int val);

void addMat(struct matrice_creuse m1,struct matrice_creuse m2);

int nombreOctetsGagnes(struct matrice_creuse m);
