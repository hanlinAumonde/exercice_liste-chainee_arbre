#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "tp3.h"

//Q3
int getValue(struct matrice_creuse m,int i,int j){
    int res;
    ligne_liste first=m.lignes[i];
    int k=0;
    if(m.lignes[i] == NULL){//si le premier est null,toutes les valeurs dans cette ligne sont 0,y compris celui que nous recherchons
        res=0;
    }
       else{
           while(k<=j){
             if(first->col == j){res=first->val;}
             else {first=first->next;}
             k++;
           }
       }
    return res;
}

