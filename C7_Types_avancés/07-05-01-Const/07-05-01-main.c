/**
===============================================================================
Exercice:               07-05-01-Const
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      21.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPattern(const char *str1, const char *str2){
   return strstr(str1, str2) != NULL;
}

int main(int argc, char *argv[]) {
   const char *chaine[] = {
       "commande1 subcmd",
       "autre commande",
       "encore subcmd ici",
       "dernière chaîne"
   };

   const char *pattern = "subcmd";

   for(size_t i = 0; i < sizeof(chaine) / sizeof(*chaine); i++){ // Pas sûre de pk ce calcul
      if(checkPattern(*(chaine + i), pattern)) {
         printf("La chaîne \"%s\" contient le pattern \"%s\".\n", *(chaine + i), pattern);
      }
   }

   return EXIT_SUCCESS;
}

/*
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LIST_SIZE 4

bool isPresent(const char* const world, const char* const motif){
    return strstr(world, motif) != NULL;
}

int main()
{
    const char motif[] = "subcmd";

    const char* list[LIST_SIZE] = {"commande1 subcmd", "autre commande", "encore subcmd ici", "dernière chaîne"};

    printf("Le motif, %s, a été trouvé dans les string suivante: \n", motif);
    for(int i = 0; i < LIST_SIZE; i++) {
        if (isPresent(list[i], motif)) printf("- %s\n", list[i]);
    }

    return 0;
}

 */