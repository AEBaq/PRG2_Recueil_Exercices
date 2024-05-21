/**
===============================================================================
Exercice:               07-04-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      21.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
   uint16_t id;   // 2 octets = 2 * 8 = 16 bits
   uint32_t time; // 4 octets = 4 * 8 = 32 bits, Horodatage en seconde (pk 8...?)
   uint8_t type;  // 1 byte = 1 * 8 = 8 bits
   float value;   // 4 octets = 4 * 8 = 32 bits
} Capteur;

void printCapteur(Capteur *capteur){
   printf("\nIdentifiant du capteur: %u\n", capteur->id);
   printf("Horodatage: %u\n", capteur->time);
   printf("Type de capteur: %u\n", capteur->type);
   printf("Valeur du capteur: %f\n", capteur->value);
}

void adrCapteur(Capteur *capteur){
   printf("\nAdresse\n");
   printf("Identifiant du capteur: %u\n", &(capteur->id));
   printf("Horodatage: %u\n", &(capteur->time));
   printf("Type de capteur: %u\n", &(capteur->type));
   printf("Valeur du capteur: %u\n", &(capteur->value));
}

int main(int argc, char *argv[]) {
   Capteur *capteur = (Capteur *)malloc(sizeof(Capteur));
   if(capteur == NULL){
      printf("An error occurred during the allocation.\n");
      return EXIT_FAILURE;
   }

   // Valeur test
   capteur->id = 12345;
   capteur->time = 161803398;
   capteur->type = 2;
   capteur->value = 3.14159;

   printCapteur(capteur);
   //adrCapteur(capteur);

   free(capteur);
   return EXIT_SUCCESS;
}