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

/* 2e fois
#include <stdio.h>

typedef enum {ONLINE, OFFLINE, IN_GAME, IN_PAUSE} PlayerState;

void updateState(PlayerState* old, PlayerState new){
    *old = new;
}

void info(PlayerState state){
    printf("The player is currently ");
    switch(state) {
        case ONLINE:
        printf("ONLINE\n");
        break;
        case OFFLINE:
        printf("OFFLINE\n");
        break;
        case IN_GAME:
        printf("in game\n");
        break;
        case IN_PAUSE:
        printf("in pause\n");
        break;
        default:
        printf("in the matrix... F\n");
        break;
    printf("\n");
    }
}

int main()
{
    PlayerState player1 = ONLINE;

    info(player1);

    updateState(&player1, OFFLINE);

    info(player1);

    return 0;
}
 */