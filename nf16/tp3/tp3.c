#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
            it = *firstLigne;
        } else {
            it->next = node;
            it = it->next;
        }
    }
    return;
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


//Q2

void afficherMat(struct matrice_creuse m) {
    printf("========= Affichage de la matrice =========\n");
    int col = 1;
    for (int i = 0; i < m.Nlignes; i++) {
        if (m.lignes[i] == NULL) {      //si le premier est nulle, afficher une ligne de 0, comme ça pas besoin de refaire les tests à chaque itération
            for (int i = 0; i < m.Ncolonnes; i++)
                printf("0\t");
        } else {
            int col = 0; //init
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
    int res;
    ligne_liste it=m.lignes[i];
    if(m.lignes[i] == NULL){//si le premier node est null,toutes les valeurs dans cette ligne sont 0,y compris celui que nous recherchons
        res=0;
    }
       else{
           while(it!=NULL && it->col<=j){        //1er cas: le résultat est 0,et j est avant le premier node du m.ligne[i]
             if(it->col == j){res=it->val;}      //2eme cas:le résultat est "it->val",et itt->col=j
             else {it=it->next;}                 //3eme cas:le résultat est 0,et j compris entre deux node du m.ligne[i] 
           }                                           //4eme cas:le résultat est 0,et j est apres le dernier node du m.ligne[i]
           if(it->col<>j || it=NULL) {res=0;}
       }                                               //*on a le 2eme cas dans le boucle while,
    return res;                                        //*pour le 1er cas,puisque la condition 'it->col<=j' est faux au début,le boucle ne s'exécutera pas,pcq it->col<>j,on a res=0
}                                                      //*si le boucle peut s'exécuter,apres le boucle,'it->col<>j' correspond au 3eme cas,'it=NULL' correspond au 4eme cas



//Q4
void putValue(struct matrice_creuse m,int i,int j,int val){
    ligne_liste e;
    ligne_liste it=m.lignes[i];
    if(getValue(m,i,j)==val){printf("Erreur!La valeur du m[%d,%d] n'a pas changé!",i,j);}  //ne pas entrer le meme valeur
    else{
        if(val=0){
           if(getValue(m,i,j)!=0){       //val=0,m[i,j]!=0,c'est a dire qu'on doit supprimer la node[i,j] dans la liste
              while(it->col<=j){
                  if(it->col == j){
                    e=it;
                    it=it->next;
                    free(e);
                  }
              }
           }
        }
        else {
           if(getValue(m,i,j)!=0){      //val!=0,m[i,j]!=0,on peut changer la valeur "it->val" de la node[i,j] directement avec "val"
              while(it->col<=j){
                if(it->col==j){it->val=val;}
              }
           }
           else {
              if(it->col>j){                         //val!=0,m[i,j]=0,c'est a dire qu'on doit faire une insertion dans la liste
                 e=malloc(sizeof(struct element));   //il existe deux cas,le premier cas est l'insertion tête de liste
                 e->val=val;
                 e->col=j;
                 e->next=it;
              }
              else{                                  //le 2eme cas est l'insertion entre deux node de la liste
                while(it->next->col<j){it=it->next;}
                 e=malloc(sizeof(struct element));
                 e->val=val;
                 e->col=j;
                 e->next=it->next;
                 it->next=e;
              }
           }

        }
    }
}