#include "tp4.h"

//Q1
T_Arbre* initABR() {
    T_Arbre *abr = malloc(sizeof(T_Noeud));
    abr=NULL;
    return abr;
}

//Q2
T_Noeud *creerNoeud(int cle) {
    T_Noeud *noeud = malloc(sizeof(T_Noeud));
    noeud->cle = cle;
    noeud->nb_occ = 1;
    noeud->gauche = NULL;
    noeud->droite = NULL;
    return noeud;
}

//Q3
void ajoutElement(T_Arbre *abr , int cle){
    if(abr == NULL){
        abr->Racine = creerNoeud(cle);
    }
    T_Noeud *it = abr->Racine;
        while(it != NULL){   //trouver la position pour ajout un nouveau noeud
            if(cle < it->cle){
              if(it->gauche == NULL){it->gauche =creerNoeud(cle);}
              else{it = it->gauche;}
            }
            else if(cle > it->cle){
              if(it->droite == NULL){it->droite =creerNoeud(cle);}
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
static T_Noeud *pere(T_Arbre *abr,T_Noeud *n){  //pere d'un noeud
    T_Noeud *it=abr->Racine;
    if(n == it) return NULL;
    while(it!=NULL && n->cle!=it->gauche->cle && n->cle!=it->droite->cle){
        if(it->cle > n->cle){it=it->gauche;}
        else if(it->cle > n->cle){it=it->droite;}
    }
    return it;
}

static T_Noeud *min(T_Arbre *abr,T_Noeud *n){  //ArbreMin pour trouver le successeur
    while(n->gauche!=NULL){n = n->gauche;}
    return n;
}

static T_Noeud *successeur(T_Arbre *abr,T_Noeud *n){ //successeur
    if(n->droite != NULL){
        while(n->droite->gauche != NULL){return min(abr,n->droite);}
    }
    T_Noeud *m=pere(abr,n);
    while((m!=NULL) && (n=m->droite)){
        n = m;
        m = pere(abr,m);
    }
    return m;
}

void decrementerElement(T_Arbre *abr , int cle){
   T_Noeud *n=rechercherElement(abr,cle);
   n->nb_occ--;
   if(n->nb_occ == 0){
      if(n->gauche==NULL && n->droite==NULL){   // pas de fils
         if(pere(abr,n)->gauche == n){pere(abr,n)->gauche=NULL;}
         else if(pere(abr,n)->droite == n){pere(abr,n)->droite=NULL;}
         else if(pere(abr,n) == NULL){abr->Racine=NULL;}
         free(n);
      }
      else if(n->gauche==NULL && n->droite!=NULL){   //un seul fil(droite)
         if(pere(abr,n)->gauche == n){pere(abr,n)->gauche=n->droite;}
         else if(pere(abr,n)->droite == n){pere(abr,n)->droite=n->droite;}
         else if(pere(abr,n) == NULL){abr->Racine=n->droite;}
         free(n);
      }
      else if(n->gauche!=NULL && n->droite==NULL){  //un seul fil(gauche)
         if(pere(abr,n)->gauche == n){pere(abr,n)->gauche=n->gauche;}
         else if(pere(abr,n)->droite == n){pere(abr,n)->droite=n->gauche;}
         else if(pere(abr,n) == NULL){abr->Racine=n->gauche;}
         free(n);
      }
      else if(n->gauche!=NULL && n->droite!=NULL){  //deux fils
         T_Noeud *succ=successeur(abr,n);
         succ->gauche=n->gauche;
         succ->droite=n->droite;
         if(pere(abr,n)->gauche == n){pere(abr,n)->gauche=succ;}
         else if(pere(abr,n)->droite == n){pere(abr,n)->droite=succ;}
         else if(pere(abr,n) == NULL){abr->Racine=succ;}
         if(pere(abr,succ)->gauche==succ){pere(abr,succ)->gauche=NULL;}
         else if(pere(abr,succ)->droite==succ){pere(abr,succ)->droite=NULL;}
         free(n);
      }
   }
}
