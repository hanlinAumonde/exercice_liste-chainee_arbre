#ifndef TP4_H
#define TP4_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Noeud{
    int cle;
    int nb_o;
    struct Noeud *gauche;
    struct Noeud *droite;
}T_Noeud;

typedef struct arbre{
    T_Noeud *Racine;
}*T_Arbre;
#endif
