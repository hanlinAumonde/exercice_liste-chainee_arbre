#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp3.h"

#define NMAX 100
int main() {
   int nb_m=0;
   struct matrice_creuse tab_m[NMAX];
   int a=1;
   int i,j,val,choix,c,v,ligne,col,reste;
   do{
      printf("Veuillez saisir votre choix de l'operation\n");
      printf("1. Remplir une matrice creuse\n");
      printf("2. Afficher une matrice creuse\n");
      printf("3. Donner la valeur dun lment dune matrice creuse\n");
      printf("4. Affecter une valeur  un lment dune matrice creuse\n");
      printf("5. Additionner deux matrices creuses\n");
      printf("6. Calculer le gain en espace en utilisant cette reprsentation pour une matrice donne\n");
      printf("7. Quitter\n");
      scanf("%d",&choix);
      switch(choix){
         case 1:
           printf("Attention:Vous pouvez entrer totalement 100 matrices\n");
           reste=100-nb_m;
           printf("Et maintenant,il reste %d matrices que vous pouvez entrer\n",reste);
           printf("Pour la %d eme matrice,entrez sa nb_ligne:\n",nb_m+1);
           scanf("%d",&ligne);
           printf("Puis sa nb_col:\n");
           scanf("%d",&col);
           remplirMat(&tab_m[nb_m],ligne,col);
           nb_m++;
           printf("La matrice est bien saisie\n");
           break;
         case 2:
            printf("Votre choix de l'affichage:\n");
            scanf("%d",&c);
            afficherMat(tab_m[c]);
            break;
         case 3:
            printf("Votre choix de la matrice:\n");
            scanf("%d",&c);
            printf("NB_ligne:\n");
            scanf("%d",&ligne);
            printf("NB_colonne:\n");
            scanf("%d",&col);
            val=getValue(tab_m[c],ligne,col);
            printf("la valeur est %d",val);
            break;
         case 4:
            printf("Votre choix de la matrice:\n");
            scanf("%d",&c);
            printf("NB_ligne:\n");
            scanf("%d",&ligne);
            printf("NB_colonne:\n");
            scanf("%d",&col);
            printf("Saisir la nouvelle valeur:\n");
            scanf("%d",&v);
            putValue(tab_m[c],ligne,col,v);
            break;
         case 5:
            printf("Saisir le numero de matrice m1:\n");
            scanf("%d",&i);
            printf("Saisir le numero de matrice m2:\n");
            scanf("%d",&j);
            break;
         case 6:
            printf("Saisir le numero de matrice m:\n");
            scanf("%d",&c);
            printf("les octets gagne: %d\n",nombreOctetsGagnes(tab_m[c]));
            break;
         case 7:
            a=0;
            printf("\nTerminer");
            break;
         default:
            printf("Erreur!Veuillez ressaisir votre choix svp\n");
            break;
      }
      printf("\n\n");
   }while(a!=0);

}
