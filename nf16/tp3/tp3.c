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
    int i;
    m->Nlignes = N;
    m->Ncolonnes = M;
    m->lignes = malloc(N*sizeof(liste_ligne));
    for(i=0;i<N;i++){m->lignes[i]=NULL;}
    for(i = 0; i < N; i++) {
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
            liste_ligne it=m.lignes[i];
            if(it == NULL){
               return 0;
            }else{
               while(it!=NULL){
                   if(it->col==j){return it->val;}
                   else {it=it->next;}
               }
            }

     return 0;
}




//Q4
static liste_ligne pred(liste_ligne *tab,liste_ligne it){    //trouver le pred d'un node 'it'
     liste_ligne e;
     if(it==*tab){return NULL;}
     else{
        e=*tab;
        while(e->next!=it){e=e->next;}
        return e;
     }
}

void putValue(struct matrice_creuse m,int i,int j,int val){
      liste_ligne e;
      liste_ligne it=m.lignes[i];
      while((it!=NULL) && (it->col!=j)){it=it->next;}
      if(val==getValue(m,i,j)){
            printf("Erreur!La valeur n'a pas change!");
            return;
      }
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
              liste_ligne it2=m.lignes[i]->next;
              if(m.lignes[i]==NULL){   //si la liste est vide
                    m.lignes[i]=creerNode(val,j);
                    return;
              }
              e=creerNode(val,j);
              while(it1!=NULL){
                    if(it1->col>j){                //j(debut)->node->node->.....
                        e->next=m.lignes[i];
                        m.lignes[i]=e;
                        break;
                    }
                    if((it1->col<j) && (it2->col>j)){   //node->node->j->node.....
                        e->next=it2;
                        it1->next=e;
                        break;
                    }
                    if((it1->col<j) && (it1->next==NULL)){     //node->node->j(fin)
                        it1->next=e;                     //(pour ce cas,je sais pas pq ca marche pas QAQ)
                        break;
                    }
                    it1=it1->next;
                    it2=it2->next;
                }

          }
       }
       printf("\nLa nouvelle matrice:\n\n");
       afficherMat(m);
}

//Q5
void addMat(struct matrice_creuse m1,struct matrice_creuse m2){
    liste_ligne e;
    for(int i=0;i<m1.Nlignes;i++){              //pour chaqur ligne i,c'est la somme de deux liste chain¨¦ it1 et it2
        liste_ligne it1=m1.lignes[i];
        liste_ligne it2=m2.lignes[i];
        if(it2==NULL){continue;}
        for(int j=0;j<m1.Ncolonnes;j++){
            if(it1->col==j && it2->col==j){      // m1[i,j] et m2[i,j] existent,directement faire la somme et mettre la r¨¦sultat en m1[i,j]
                  it1->val=it1->val+it2->val;
                  it2=it2->next;     //c'est obligatoire de d¨¦placer le pointeur sur le node suivant quand il existe un node en [i,j],donc pour le jeme coloone,le pointeur toujours pointe le node que (col de node) >= j
                  if(it1->val==0){                     //si le nouveau val est 0,on doit supprimer ce node
                      if(pred(&(m1.lignes[i]),it1)!=NULL){     //supprimer un node entre deux autres nodes
                        e=it1->next;
                        pred(&(m1.lignes[i]),it1)->next=it1->next;
                        free(it1);
                        it1=e;
                      }else{               //supprimer un node en tete de liste
                         e=m1.lignes[i];
                         m1.lignes[i]=m1.lignes[i]->next;
                         free(e);
                         it1=m1.lignes[i];
                      }
                  }else{it1=it1->next;}
            }
            else if(it1->col==j && (it2->col>j || it2==NULL)){   //m1[i,j]!=0,m2[i,j]=0,donc m1[i,j] ne pas changer
                    it1=it1->next;
            }
            else if((it1->col>j || it1==NULL) && it2->col==j){                //m1[i,j]=0,m2[i,j]!=0,donc on doit ajouter un nouveau node e en it1,e.val=it2.val
              liste_ligne it3=m1.lignes[i];                         //ce cas est similaire à putValue,on insert les nouveaux nodes dans m1
              liste_ligne it4=m1.lignes[i]->next;
              e=creerNode(it2->val,j);
              if(m1.lignes[i]==NULL){
                    m1.lignes[i]=creerNode(it2->val,j);
              }
              while(it3!=NULL){
                    if(it1->col>j){
                        e->next=m1.lignes[i];
                        m1.lignes[i]=e;
                        break;
                    }
                    if((it3->col<j) && (it4->col>j)){
                        e->next=it4;
                        it1->next=e;
                        break;
                    }
                    if((it3->col<j) && (it3->next==NULL)){
                        it3->next=e;
                        break;
                    }
                    it3=it3->next;
                    it4=it4->next;
                }
                it2=it2->next;
            }
        }
    }
    printf("La nouvelle matrice:\n");
    afficherMat(m1);
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