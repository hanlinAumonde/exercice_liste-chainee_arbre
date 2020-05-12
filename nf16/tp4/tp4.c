#include "tp4.h"

//Q1
T_Arbre initABR() {
    T_Arbre abr = malloc(sizeof(T_Noeud));
    return abr;
}

//Q2
T_Noeud *creerNoeud(int cle, int occ) {
    T_Noeud *noeud = malloc(sizeof(T_Noeud));
    noeud->cle = cle;
    noeud->nb_o = occ;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    return noeud;
}

//Q3
void ajoutElement(T_Arbre abr , int cle, int occ){
    if(abr == NULL){//si il n'y a pas encore d'arbre
        abr = initABR();
        abr->Racine = creerNoeud(cle,occ);
    }
    T_Noeud *node = creerNoeud(cle,occ);
    if(cle < abr->Racine->cle){  //partie gauche de l'arbre
        T_Noeud *it1 = abr->Racine->gauche;
        while(it1 != NULL){   //trouver la position pour ajout un nouveau noeud
            if(cle < it1->cle){
              if(it1->gauche == NULL){it1->gauche = node;}
              else{it1 = it1->gauche;}
            }
            else{
              if(it1->droite == NULL){it1->droite = node;}
              else{it1 = it1->droite;}
              }
        }
    }
    else if(cle > abr->Racine->cle){ //partie droite,similaire au cas precedent
        T_Noeud *it2 = abr->Racine->droite;
        while(it2 != NULL){
            if(cle < it2->cle){
              if(it2->gauche == NULL){it2->gauche = node;}
              else{it2 = it2->gauche;}
            }
            else{
              if(it2->droite == NULL){it2->droite = node;}
              else{it2 = it2->droite;}
              }
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
T_Noeud *rechercherElement(T_Arbre abr , int val){
    if(abr->Racine->cle == val){return abr->Racine;}
    else{return NULL;}
    if(val < abr->Racine->cle){
        abr->Racine = abr->Racine->gauche;
        return rechercherElement(abr,val);
    }
    if(val > abr->Racine->cle){
        abr->Racine = abr->Racine->droite;
        return rechercherElement(abr,val);
    }
}
