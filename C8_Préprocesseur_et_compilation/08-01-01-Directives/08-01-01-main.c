/**
===============================================================================
Exercice:               08-01-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      22.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Une certaine configuration

#define CONFIG_VERSION 23

#define CONFIG_STACK_PROTECTION

#define CONFIG_OS_WIN
//#define CONFIG_OS_LINUX

// La structure doit avoir tous les membres alignés sur 16 octets
#pragma pack(push,16)

typedef struct {

   // Le champ suivant, uniquement pour une config WIN avec la version étant égale à 23
   // Les conditions doivent être exprimées en une seule ligne
#if defined(CONFIG_OS_WIN) && (CONFIG_VERSION == 23)
   unsigned int addr;

   // Et celui-ci, uniquement pour une config Linux
#elif defined(CONFIG_OS_LINUX)
   unsigned long addrl;

   // Si ni Linux, ni WIN, afficher une erreur de compilation.
   // Autres champs présents dans tous les cas
#else
#error OS not selected correctly
#endif
   unsigned long size;
   bool valid;
} mem_desc_t;

#pragma pack(pop)

// Uniquement si CONFIG_STACK_PROTECTION
#ifdef CONFIG_STACK_PROTECTION
void stack_validate(void) {
   printf("Stack validation\n");
}
#endif

int main(int argc, char *argv[]) {

   /* ... */
   printf("Size of mem_desc: %lu\n", sizeof(mem_desc_t));

#ifdef CONFIG_STACK_PROTECTION
   stack_validate();
#endif

   /* ... */

   return EXIT_SUCCESS;
}