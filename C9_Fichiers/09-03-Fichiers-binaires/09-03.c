/**
===============================================================================
Exercice:               09-03
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      24.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h> // printf()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILED

#define MAX_LEN 256
#define MAX_ELEM 10

#define STR(x) #x
#define PRINT_ERROR(x) printf("%s file could not be opened.\n", STR(x))

// 1st version (not usable for other part)
void printFile(FILE *file) {
   int c;

   // TODO: Amélioration possible pour trouver comment écrire qu'une seule fois importing
   printf("importing ");
   while ((c = fgetc(file)) != EOF) {
      if (c == ' ') {
         printf(",");
      } else {
         printf("%c", (char) c);
         if (c == '\n') {
            printf("importing ");
         }
      }
   }
   printf("\n");
}

/*
 * Exercice 2
 */

struct stockItem {
   char brand[MAX_LEN];
   char model[MAX_LEN];
   int quantity;
   float unit, total;
};

int main(int argc, char *argv[]) {
   FILE *input = fopen("../09-03-Fichiers-binaires/stock.txt", "r");
   if (!input) {
      PRINT_ERROR(input);
      goto liberation;
      return EXIT_FAILURE;
   }

   // Exercice 1: 1st version
   //printFile(input);

   /* Exercice 1: Teacher's solution
   char brand[MAX_LEN], model[MAX_LEN];
   float unit, total;
   int quantity;

   while(fscanf(input, "%s %s %f %d %f", brand, model, &unit, &quantity, &total)!= EOF) {
      printf("importing %s, %s, %.2f, %d, %.2f\n", brand, model, unit, quantity, total);
   }
   */


   /*
    * Exercice 2
    */
   FILE *output = fopen("../09-03-Fichiers-binaires/output.bmp", "w+b");
   if (!output) {
      PRINT_ERROR(output);
      goto liberation;
   }

   struct stockItem stock[MAX_ELEM];
   int i = 0;
   while (fscanf(input, "%s %s %f %d %f", stock[i].brand, stock[i].model, &stock[i].unit, &stock[i].quantity, &stock[i].total) != EOF) {
      printf("importing %s, %s, %.2f, %d, %.2f\n", stock[i].brand, stock[i].model, stock[i].unit, stock[i].quantity, stock[i].total);
      i++;
   }

   // Writing of header in output
   if (fwrite(&i, sizeof(int), 1, output) != 1) {
      printf("Error during writing of header\n");
      goto liberation;
   }

   // Writing of stock in output
   if (fwrite(stock, sizeof(struct stockItem), i, output) != i) {
      printf("Error during writing of struct\n");
      goto liberation;
   }

   /*
    * Exercice 3
    */
   printf("[i] The stock contains %d products: \n", i);
   for (int j = 0; j < i; j++) {
      printf("[i] - row %d: [%s], [%s], [%.2f], [%d], [%.2f]\n", j, stock[j].brand, stock[j].model, stock[j].unit, stock[j].quantity,
             stock[j].total);
   }


   liberation :
   if (input) fclose(input);
   if (output) fclose(output);

   return EXIT_SUCCESS;
}