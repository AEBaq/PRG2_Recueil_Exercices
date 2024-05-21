/**
===============================================================================
Exercice:               07-02-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      21.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum{
   EN_LIGNE,
   HORS_LIGNE,
   EN_JEU,
   EN_PAUSE
}StatutJoueur;

void update(StatutJoueur *statut, StatutJoueur new){
   *statut = new;
}

void info(StatutJoueur statut) {
   printf("\nLe joueur est actuellement ");
   switch(statut){
      case EN_LIGNE:
         printf("en ligne.\n");
         break;
      case HORS_LIGNE:
         printf("hors ligne.\n");
         break;
      case EN_JEU:
         printf("en jeu.\n");
         break;
      case EN_PAUSE:
         printf("en pause.\n");
         break;
      default:
         break;
   }
}

int main(int argc, char *argv[]) {
   StatutJoueur player1 = HORS_LIGNE;
   info(player1);

   update(&player1, EN_LIGNE);

   info(player1);

   return EXIT_SUCCESS;
}