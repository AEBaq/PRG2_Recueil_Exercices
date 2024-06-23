/**
===============================================================================
Exercice:               12-03
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:
Version:                1.0
===============================================================================
*/

#include <stdio.h> // printf()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILED

typedef struct {
   unsigned int sequence : 16;
   unsigned int type : 4;
   unsigned int status : 2;
   unsigned int longueur : 10;
} Packet;

void initPacket(Packet *_paquet, unsigned int _sequence, unsigned int _type, unsigned int _status, unsigned int _longueur){
   _paquet->sequence = _sequence;
   _paquet->type = _type;
   _paquet->status = _status;
   _paquet->longueur = _longueur;
}

void printPacket(Packet *paquet){
   printf("Sequence : %u\n"
          "Type : %u\n"
          "Status : %u\n"
          "Longueur : %u\n",
          paquet->sequence,
          paquet->type,
          paquet->status,
          paquet->longueur);
}

void modifyType(Packet *paquet, unsigned int newType){
   paquet->type = newType;
}

void modifyStatus(Packet *paquet, unsigned int newStatus){
   paquet->status = newStatus;
}

unsigned int getSize(Packet packet){
   return sizeof(packet);
}

int main(int argc, char *argv[]) {

   Packet paquet;

   initPacket(&paquet, 123, 12, 2, 66);

   printf("\nInformation du packet : \n");
   printPacket(&paquet);

   modifyType(&paquet, 8);
   modifyStatus(&paquet, 1);

   printf("\nNouvelle information du packet : \n");
   printPacket(&paquet);

   printf("Voici la taille du paquet : %zu\n", getSize(paquet));


   return EXIT_SUCCESS;
}