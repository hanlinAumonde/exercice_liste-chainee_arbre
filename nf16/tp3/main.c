#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp3.h"
#include "tp3.c"
#define NMAX 100
int main() {
   int nb_m=0;
   matrice_creuse tab_m[NMAX];
   int a=1;
   int choix,c2,c3,c4,v,ligne,col,reste;
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
           printf("Attention:Vous pouvez entrer totalement 100 matrices");
           reste=100-nb_m;
           printf("Et maintenant,il reste %d matrices que vous pouvez entrer",reste);
           printf("Pour la %d eme matrice,entrez sa nb_ligne:\n",nb_m+1);
           scanf("%d",&ligne);
           printf("Puis sa nb_col:\n");
           scanf("%d",&col);
           remplirMat(&tab_m[nb_m],ligne,col);
           nb_m++;
           break;
         case 2:
            printf("Votre choix de l'affichage:\n");
            scanf("%d",&c2);
            afficherMat(tab_m[c2]);
            break;
         case 3:
            printf("Votre choix de la matrice:\n");
            scanf("%d",&c3);
            printf("NB_ligne:\n");
            scanf("%d",&ligne);
            printf("NB_colonne:\n");
            scanf("%d",&col);
            if(ligne>tab_m[c3].Nlignes || col>tab_m[c3].Ncolonnes || ligne<0 || col<0){
                printf("Erreur!");
                break;
            }
            printf("La valeur est %d\n",getValue(tab_m[c3]),ligne,col);
            break;
         case 4:
            printf("Votre choix de la matrice:\n");
            scanf("%d",&c4);
            printf("NB_ligne:\n");
            scanf("%d",&ligne);
            printf("NB_colonne:\n");
            scanf("%d",&col);
            if(ligne>tab_m[c4].Nlignes || col>tab_m[c4].Ncolonnes || ligne<0 || col<0){
                printf("Erreur!");
                break;
            printf("Saisir la nouvelle valeur:\n")
            scanf("%d",&v);
            putValue(tab_m[c4],ligne,col,v);
            break;
         case 5:
            break;
         case 6:
            break;
         case 7:
            a=0;
            printf("\nTerminer");
            break;
         default:
            printf("Veuillez ressaisir votre choix svp\n");
            break;
      }
      printf("\n\n");
   }while(a!=0);
}
