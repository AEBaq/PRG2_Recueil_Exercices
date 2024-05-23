/**
===============================================================================
Exercice:               09-02
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      23.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include <ctype.h> // isblank
#include <stdbool.h> // bool

// *** TODO: counting functions

/**************
 * Exercice 1 *
 **************/
int countc(FILE *file) {
   int nb = 0;

   while (fgetc(file) != EOF) nb++;

   return nb;
}

/**************
 * Exercice 2 *
 **************/
int countm(FILE *file) {
   int cpt = 0;
   int c;
   bool cpt_en = true;

   while ((c = fgetc(file)) != EOF) {
      if (isblank(c) || c == '\n') { // ou c == ' '
         cpt_en = false;
      } else if (!cpt_en) {
         cpt_en = true;
         cpt++;
      }

   }
   return cpt;
}

/**************
 * Exercice 3 *
 **************/
int countl(FILE *file) {
   int cpt = 0;
   int c;

   while((c = fgetc(file)) != EOF){
      if(c == '\n') cpt++;
   }

   return cpt;
}


int main(int argc, char **argv) {
   if (argc != 2) {
      printf("Usage: %s file\n", argv[0]);
      return 1;
   }

   FILE *fin;

   // *** TODO: open file

   /**************
    * Exercice 1 *
    **************/

   fin = fopen(argv[1], "r");
   if (!fin) {
      printf("[e] could not be open %s\n", argv[1]);
      return EXIT_FAILURE;
   }

   // count characters in file

   printf("%s contains %d characters\n", argv[1], countc(fin));

   fclose(fin);


   /**************
    * Exercice 2 *
    **************/

   // freopen permet de rouvrir un flux anciennement utilisé
   // tout en ignorant les potentielles erreurs précédentes
   fin = freopen(argv[1], "r", fin);
   if (!fin) {
      printf("[e] could not open %s\n", argv[1]);
   }

   printf("%s file contains %d word(s)\n", argv[1], countm(fin));

   fclose(fin);

   return EXIT_SUCCESS;
}