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

#include <CUnit/CUCurses.h>
#include <CUnit/CUnit.h>

// #include <CUnit/Console.h>

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
      return (int)pow((double)nombre1, (double)nombre2);

   default:
      // Gérer l'opérateur invalide
      return -1;
   }
}

// Addition
void test_addition(void) {
   CU_ASSERT_EQUAL(calculer(2, -10, '+'), -8);
   CU_ASSERT_EQUAL(calculer(2, 10, '+'), 12);
}

// Soustraction
void test_soustraction(void) {
   CU_ASSERT_EQUAL(calculer(2, -10, '-'), 12);
   CU_ASSERT_EQUAL(calculer(10, 2, '-'), 8);
}

// Multiplication
void test_multiplication(void) {
   CU_ASSERT_EQUAL(calculer(2, -10, '*'), -20);
   CU_ASSERT_EQUAL(calculer(0, 10, '*'), 0);
   CU_ASSERT_EQUAL(calculer(10, 10, '*'), 100);
}

// Division
void test_division(void) {
   CU_ASSERT_EQUAL(calculer(343, 7, '/'), 49);
   CU_ASSERT_EQUAL(calculer(343, -7, '/'), -49);
   CU_ASSERT_EQUAL(calculer(10, 0, '/'), -1);
}

// Power
void test_power(void) {
   CU_ASSERT_EQUAL(calculer(49, 7, '^'), 343);
   CU_ASSERT_EQUAL(calculer(2, -2, '^'), 0);
}

// Other
void test_default(void) {
   CU_ASSERT_EQUAL(calculer(10, 2, '%'), -1);
}

int main() {
   CU_pSuite pSuite = NULL;

   if (CU_initialize_registry() != CUE_SUCCESS) return CU_get_error();

   pSuite = CU_add_suite("Test calculcatrice", NULL, NULL);
   // ou init_suite, clean_suite, fct qui doivent être créer et effectuer à l'init et clean

   if (!pSuite) goto out;

   if ((!CU_add_test(pSuite, "Test addition", test_addition)) ||
      (!CU_add_test(pSuite, "Test soustraction", test_soustraction)) ||
      (!CU_add_test(pSuite, "Test multiplication", test_multiplication)) ||
      (!CU_add_test(pSuite, "Test division", test_division)) ||
      (!CU_add_test(pSuite, "Test power", test_power)) ||
      (!CU_add_test(pSuite, "Test default", test_default))) {
      goto out;
   }

   CU_curses_run_tests();

out:
   CU_cleanup_registry();
   return CU_get_error();

}
