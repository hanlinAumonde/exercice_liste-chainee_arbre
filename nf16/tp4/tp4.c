#include "tp4.h"

//Q1
T_Arbre* initABR() {
    T_Arbre* abr = malloc(sizeof(T_Arbre));
    abr->Racine = NULL;
    return abr;
}

//Q2
T_Noeud* creerNoeud(int cle) {
    T_Noeud* noeud = malloc(sizeof(T_Noeud));
    noeud->cle = cle;
    noeud->nb_occ = 1;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    return noeud;
}

//Q3
void ajoutElement(T_Arbre* abr , int cle){
    T_Noeud* temp;
    T_Noeud* it = abr->Racine;
    T_Noeud* e = creerNoeud(cle);
    if(it != NULL)
    {
        while(it != NULL){   //trouver la position pour ajout un nouveau noeud
            temp = it;
            if(cle < it->cle){
              it = it->gauche;
              if(it == NULL){temp->gauche = e;}
            }
            else if(cle > it->cle){
              it = it->droite;
              if(it == NULL){temp->droite = e;}
              }
        }
    }
    else{abr->Racine = e;}
}

//Q4
void afficherArbre(T_Noeud* n){ //parcour infixe pour avoir les nbs dans l'ordre croissant
    T_Noeud* it = n;
    if(it != NULL){
        afficherArbre(it->gauche);
        printf("val:%d / occurrence:%d\t",it->cle,it->nb_occ);
        printf("|\t");
        afficherArbre(it->droite);
    }
}

//Q5
T_Noeud* rechercherElement(T_Arbre* abr,int val){
    T_Noeud* temp;
    T_Noeud* it = abr->Racine;
    while(it != NULL){
        temp = it;
        if(val == it->cle){return temp;}
        if(val > it->cle){it = it->droite;}
        if(val < it->cle){it = it->gauche;}
    }
    return NULL;
}

//Q6
void decrementerElement(T_Arbre* abr,int cle){
   T_Noeud* pere = NULL;
   T_Noeud* it = abr->Racine;
   while(it != NULL && it->cle != cle){
      pere = it;
      if(cle > it->cle) it = it->droite;
      if(cle < it->cle) it = it->gauche;
   }
   it->nb_occ--;
   if(it->nb_occ == 0){
      T_Noeud* tmpG = it->gauche;
      T_Noeud* tmpD = it->droite;
      if(tmpG == NULL && tmpD == NULL){  //pas de fils
         if(pere->gauche == it) pere->gauche = NULL;
         if(pere->droite == it) pere->droite = NULL;
         if(pere == NULL) abr->Racine = NULL;
      }
      if(tmpG != NULL && tmpD == NULL){  //un seul fil(gauche)
         if(pere->gauche == it) pere->gauche = it->gauche;
         if(pere->droite == it) pere->droite = it->gauche;
         if(pere == NULL) abr->Racine = it->gauche;
      }
      if(tmpG == NULL && tmpD != NULL){  //un seul fil(droite)
         if(pere->gauche == it) pere->gauche = it->droite;
         if(pere->droite == it) pere->droite = it->droite;
         if(pere == NULL) abr->Racine = it->droite;
      }
      if(tmpG != NULL && tmpD != NULL){

      }
      free(it);
   }
}