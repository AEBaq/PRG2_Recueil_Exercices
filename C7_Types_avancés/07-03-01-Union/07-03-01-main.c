/**
===============================================================================
Exercice:               07-03−01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      21.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef union{
   float temperature;
   float humidity;
   int occupation;
} DonneesCapteur;

typedef enum{
   TEMPERATURE,
   HUMITIDTE,
   OCCUPATION
} TypeDeCapteur;

typedef struct{
   TypeDeCapteur type;
   DonneesCapteur donnes;
   time_t timestap;
} Capteur;

void info(Capteur capteur){

   printf("Timestamp: %lld\n", capteur.timestap);
   printf("\nCaptor type: ");
   switch(capteur.type){
      case TEMPERATURE:
         printf("TEMPERATURE\n");
         printf("Temperature: %.2f\n", capteur.donnes.temperature);
         break;
      case HUMITIDTE:
         printf("HUMIDITY\n");
         printf("Humidite: %.2f\n", capteur.donnes.humidity);
         break;
      case OCCUPATION:
         printf("OCCUPATION\n");
         printf("Occupation: %d\n", capteur.donnes.occupation);
         break;
      default:
         break;
   }
}

int main(int argc, char *argv[]) {
   Capteur capteur;
   capteur.type = TEMPERATURE;
   capteur.donnes.temperature = 25.753;
   capteur.timestap = time(NULL);

   info(capteur);

   return EXIT_SUCCESS;
}