/**
===============================================================================
Exercice:               12-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      23.06.24
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int addition(int a, int b) {
   return a + b;
}

int soustraction(int a, int b) {
   return a - b;
}

int multiplication(int a, int b) {
   return a * b;
}

int division(int a, int b) {
   if (b != 0) {
      return a / b;
   } else {
      printf("Erreur : division par zéro\n");
      return 0;
   }
}

int (*operateur[4])(int, int) = {addition, soustraction, multiplication, division};

int main(){

   int choix = 0, a = 0, b = 0;
   printf("Veuillez choisir l'operation a effectuer (O: Add, 1 : Sous, 2 : Mult, 3 : Div) : \n");
   scanf("%d", &choix);

   while(choix < 0 || choix >= 4){
      printf("Veuillez entrer une opération connue : \n");
      scanf("%d", &choix);
   }

   printf("Entrez deux nombres : \n");
   scanf("%d %d", &a, &b);

   printf("Le résultat de votre opération est : %d\n", operateur[choix](a, b));

   return EXIT_SUCCESS;
}

