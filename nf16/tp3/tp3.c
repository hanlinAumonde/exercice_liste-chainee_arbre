#include "tp3.h"



//Q1

static liste_ligne creerNode(int val, int col) {
    liste_ligne node = malloc(sizeof(struct element));
    node->col = col;
    node->val = val;
    node->next = NULL;
    return node;
}

static void creerLigne(liste_ligne *firstLigne , int line, int  NbCol) {
    liste_ligne it; // = *firstLigne; //premier node de la ligne
    for (int i = 0 ; i < NbCol; i++) {
        int val;
        printf("M[%d][%d]\t", line, i);
        printf("rentrez un entier : ");
        scanf(" %d", &val);
        if (val == 0)
            continue;
        liste_ligne node = creerNode(val, i);
        if (*firstLigne == NULL) {
            *firstLigne = node;
            it=*firstLigne;
        } else {
            while(it->next!=NULL){
                it = it->next;
            }
            it->next = node;
        }
    }
}

void remplirMat(struct matrice_creuse *m, int N, int M) {
    printf("========= Remplissage de la matrice =========\n");

    m->Nlignes = N;
    m->Ncolonnes = M;
    m->lignes = malloc(N*sizeof(liste_ligne));
    memset(m->lignes, 0, N*sizeof(liste_ligne));
    for(int i = 0; i < N; i++) {
        creerLigne(&(m->lignes[i]),i, M);
    }

}


//Question 2

void afficherMat(struct matrice_creuse m) {
    printf("========= Affichage de la matrice =========\n");
    for (int i = 0; i < m.Nlignes; i++) {
        if (m.lignes[i] == NULL) {      //si le premier est nulle, afficher une ligne de 0, comme ça pas besoin de refaire les tests à chaque itération
            for (int i = 0; i < m.Ncolonnes; i++)
                printf("0\t");
        } else {
            liste_ligne it = m.lignes[i]; //premier node de la ligne
            for (int j = 0; j < m.Ncolonnes; j++) {
                if (it != NULL) {
                    if(it->col != j) {
                        printf("0\t");
                    } else {
                        printf("%d\t", it->val);
                        it = it->next;
                    }
                } else
                    printf("0\t");
            }
        }
        printf("\n");
    }
}




//Q3
int getValue(struct matrice_creuse m,int i,int j){
    if(i>m.Nlignes-1 || j>m.Ncolonnes-1 || i<0 || j<0){
                printf("Erreur!");
                exit(-1);
            }
    else{
            liste_ligne it=m.lignes[i];
            if(it == NULL){
               return 0;
            }else{
               while(it!=NULL){
                   if(it->col==j){return it->val;}
                   else {it=it->next;}
               }
            }
     }
     return 0;
}




//Q4
static liste_ligne pred(liste_ligne *tab,liste_ligne it){
     liste_ligne e;
     if(it==*tab){return NULL;}
     else{
        e=*tab;
        while(e->next!=it){e=e->next;}
        return e;
     }
}

void putValue(struct matrice_creuse m,int i,int j,int val){
      if(i>m.Nlignes-1 || j>m.Ncolonnes-1 || i<0 || j<0){
                printf("Erreur!");
                exit(-1);
            }
      liste_ligne e;
      liste_ligne it=m.lignes[i];
      while((it!=NULL) && (it->col!=j)){it=it->next;}
      if(val==getValue(m,i,j)){printf("Erreur!La valeur n'a pas change!");}
      else if(val==0){               //val=0,m[i,j]≠0,c-a-d le suppression d'un node
          if(pred(&(m.lignes[i]),it)!=NULL){     //supprimer un node entre deux autres nodes
              pred(&(m.lignes[i]),it)->next=it->next;
              free(it);
          }else{               //supprimer un node en tete de liste
              e=m.lignes[i];
              m.lignes[i]=m.lignes[i]->next;
              free(e);
          }
      }else if(val!=0){
          if(getValue(m,i,j)!=0){    //val≠0,m[i,j]≠0
              it->val=val;
          }else{        //val≠0,m[i,j]=0,c-a-d l'insertion d'un node
              liste_ligne it1=m.lignes[i];
              e=malloc(sizeof(struct element));
              e->val=val;
              e->col=j;
              if(m.lignes[i]==NULL){m.lignes[i]=e;}  //si la liste est vide
              while(it1!=NULL){
                    if(it1->col>j){
                        e->next=m.lignes[i];
                        m.lignes[i]=e;
                        break;
                    }
                    if((it1->col<j) && (it1->next->col>j)){  //(il y a qlq erreur,je sais pas pq QAQ)
                        e->next=it1->next;
                        it1->next=e;
                        break;
                    }
                    if((it1->col<j) && (it1->next==NULL)){   //(il y a qlq erreur,je sais pas pq QAQ)
                        it1->next=e;
                        e->next=NULL;
                        break;
                    }
                    it1=it1->next;
                }

          }
       }
       printf("La nouvelle matrice:\n");
       afficherMat(m);
}




//Q6
int nombreOctetsGagnes(struct matrice_creuse m){
    int res=0;
    for(int i=0;i<m.Nlignes;i++){
        liste_ligne it=m.lignes[i];
        while(it!=NULL){
            res+=2*sizeof(int)+sizeof(int*);
            it=it->next;
        }
    }
    int nb=(m.Nlignes*m.Ncolonnes)*sizeof(int);
    return nb-res;
}

