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

/*
#include <stdio.h>
#include <time.h>

typedef union {
    float temperature;
    float humidity;
    int occupation;
} CaptorData;

typedef enum {TEMPERATURE, HUMIDITY, OCCUPATION} CaptorType;

typedef struct {
    CaptorType type;
    CaptorData data;
    time_t timestamp;
} Captor;

void info(Captor* captor){
    printf("Timestamp: %ld\n", captor->timestamp);
    switch(captor->type){
        case TEMPERATURE :
            printf("Temperature : %f\n", captor->data.temperature);
            break;
        case HUMIDITY :
            printf("Humidity : %f\n", captor->data.humidity);
            break;
        case OCCUPATION :
            printf("Occupation : %d\n", captor->data.occupation);
            break;
        default:
            printf("Honestly, i don't know how you got here...\n");
            break;
    }
    printf("\n");
}


int main()
{
    Captor captor = {TEMPERATURE, 12.5, time(NULL)};

    info(&captor);


    return 0;
}
 */