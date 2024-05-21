/**
===============================================================================
Exercice:               07-01-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      21.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>   //printf
#include <stdlib.h>  //scanf
#include <string.h>  //strcpy

#define EMPRUNT 0
#define RENDU 1

typedef struct{
   char titre[100];
   char auteur[100];
   int annee;
   int nb_copie;
} Livre;

Livre add(char *titre, char *auteur, int annee, int nb_copie ){
   Livre new;

   strcpy(new.titre, titre);
   strcpy(new.auteur, auteur);
   new.annee = annee;
   new.nb_copie = nb_copie;

   return new;
}

void update(Livre *livre, int etat){
   switch (etat){
      case EMPRUNT:
         livre->nb_copie--;
         break;
      case RENDU:
         livre->nb_copie++;
         break;
      default:
         printf("Etat du libre non-reconnu\n");
         break;
   }
}

void info(Livre livre){
   printf("Titre: %s\n", livre.titre);
   printf("Auteur: %s\n", livre.auteur);
   printf("Annee de publication: %d\n", livre.annee);
   printf("Nombre de copie: %d\n\n", livre.nb_copie);
}

int main(int argc, char *argv[]) {
   Livre livre = add("Oui-oui", "Tchoupi", 2000, 4);
   info(livre);
   update(&livre, EMPRUNT);
   info(livre);

   return 0;
}
