#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "tp3.h"

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



