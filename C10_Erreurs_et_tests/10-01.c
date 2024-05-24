/**
===============================================================================
Exercice:               10-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      24.05.2024
Version:                1.0
===============================================================================
*/

#include <math.h>

int calculer(int nombre1, int nombre2, char operateur) {

   switch (operateur) {
      case '+':
         return nombre1 + nombre2;

      case '-':
         return nombre1 - nombre2;

      case '*':
         return nombre1 * nombre2;

      case '/':
         if (nombre2 == 0) {
            // Gérer l'erreur de division par zéro
            return -1;
         } else {
            return nombre1 / nombre2;
         }

      case '^':
         // Puissance non implémentée avec des entiers
         return (int) pow((double) nombre1, (double) nombre2);

      default:
         // Gérer l'opérateur invalide
         return -1;
   }
}