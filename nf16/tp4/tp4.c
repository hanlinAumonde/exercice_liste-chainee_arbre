#include "tp4.h"

//Q1
T_Arbre* initABR() {
    T_Arbre *abr = malloc(sizeof(T_Noeud));
    abr=NULL;
    return abr;
}

//Q2
T_Noeud *creerNoeud(int cle, int occ) {
    T_Noeud *noeud = malloc(sizeof(T_Noeud));
    noeud->cle = cle;
    noeud->nb_occ = occ;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    return noeud;
}

//Q3
void ajoutElement(T_Arbre *abr , int cle, int occ){
    if(abr == NULL){
        abr->Racine = creerNoeud(cle,occ);
    }
    T_Noeud *it = abr->Racine;
        while(it != NULL){   //trouver la position pour ajout un nouveau noeud
            if(cle < it->cle){
              if(it->gauche == NULL){it->gauche =creerNoeud(cle,occ);}
              else{it = it->gauche;}
            }
            else if(cle > it->cle){
              if(it->droite == NULL){it->droite =creerNoeud(cle,occ);}
              else{it = it->droite;}
              }
        }

}

//Q4
void afficherArbre(T_Noeud *n){ //parcour infixe pour avoir les nbs dans l'ordre croissant
    printf("\nTous les elements dans l'ordre croissant:\n");
    if(n != NULL){
        afficherArbre(n->gauche);
        printf("val:%d / occurrence:%d\n",n->cle,n->nb_occ);
        afficherArbre(n->droite);
    }
}

//Q5
T_Noeud* rechercherElement(T_Arbre *abr , int val){
    T_Arbre *it=abr;
    if(it->Racine->cle == val){return it->Racine;}
    else{return NULL;}
    if(val < it->Racine->cle){
        it->Racine = it->Racine->gauche;
        return rechercherElement(it,val);
    }
    if(val > it->Racine->cle){
        it->Racine = it->Racine->droite;
        return rechercherElement(it,val);
    }
}

//Q6
void decrementerElement(T_Arbre *abr){}
