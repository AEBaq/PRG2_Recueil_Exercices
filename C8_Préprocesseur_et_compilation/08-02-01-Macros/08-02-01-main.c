/**
===============================================================================
Exercice:               08-02-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      22.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Définition des macros */
/* A compléter */
#define CHIFFRE(c) (isdigit((unsigned char)(c)) != 0)
#define MINUSCULE(c) (islower((unsigned char)(c)) != 0)
#define MAJUSCULE(c) (isupper((unsigned char)(c)) != 0)
#define MIN_MAJ(c) (MINUSCULE(c)? toupper(c) : (c))
#define MAJ_MIN(c) (MAJUSCULE(c)? tolower(c) : (c))
#define PERMUTE(a, b) \
   do{                \
      int temp = (int) (a); \
      (a) = (int) (b);   \
      (b) = temp;        \
   }while (0)


#define COPIE(s, t) \
   do{              \
      strcpy((t), (s));\
   }while(0)

int main() {

   char test_char = '5';
   char test_min_char = 'a';
   char test_maj_char = 'Z';
   int a = 10, b = 20;
   char lower_char = 't';
   char upper_char = 'K';
   char source[] = "Hello, world!";
   char destination[50];

   /* Teste si <test_char> est un chiffre */
   printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));

   /* Teste si <test_min_char> est une minuscule */
   printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));

   /* Teste si <test_maj_char> est une majuscule */
   printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));

   /* Converti <lower_char> en majuscule SI minuscule */
   printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));

   /* Converti <upper_char> en minuscule SI majuscule */
   printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

   printf("Avant permutation : a = %d, b = %d\n", a, b);

   PERMUTE(a, b);

   printf("Après permutation : a = %d, b = %d\n", a, b);

   /* Effectue une copie de destination dans source avec la macro COPIE */
   COPIE(source, destination);
   /* A compléter */

   printf("Chaîne copiée : %s\n", destination);

   return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Définition des macros

#define CHIFFRE(c) (isdigit(c) != 0)
#define MINUSCULE(c) (islower(c) != 0)
#define MAJUSCULE(c) (isupper(c) != 0)
#define MIN_MAJ(c) (MINUSCULE(c) ? toupper(c) : c)
#define MAJ_MIN(c) (MAJUSCULE(c) ? tolower(c) : c)
#define PERMUTE(a, b)   \
        ({int temp = a;   \
        a = b;          \
        b = temp;})       \

#define COPIE(s, t) strcpy(t, s)



int main() {

   char test_char = 'a';
   char test_min_char = 'a';
   char test_maj_char = 'Z';
   int a = 10, b = 20;
   char lower_char = 't';
   char upper_char = 'K';
   char source[] = "Hello, world!";
   char destination[50];

   //Teste si <test_char> est un chiffre
   printf("Est-ce un chiffre ? %d\n", CHIFFRE(test_char));

   //Teste si <test_min_char> est une minuscule
   printf("Est-ce une minuscule ? %d\n", MINUSCULE(test_min_char));

   //Teste si <test_maj_char> est une majuscule
   printf("Est-ce une majuscule ? %d\n", MAJUSCULE(test_maj_char));

   //Converti <lower_char> en majuscule SI minuscule
   printf("En majuscule si minuscule : %c\n", MIN_MAJ(lower_char));

   //Converti <upper_char> en minuscule SI majuscule
   printf("En minuscule si majuscule : %c\n", MAJ_MIN(upper_char));

   printf("Avant permutation : a = %d, b = %d\n", a, b);
   PERMUTE(a, b);
   printf("Après permutation : a = %d, b = %d\n", a, b);

   //Effectue une copie de destination dans source avec la macro COPIE

   //A compléter
   COPIE(source, destination);

   printf("Chaîne copiée : %s\n", destination);

   return 0;
}
 */