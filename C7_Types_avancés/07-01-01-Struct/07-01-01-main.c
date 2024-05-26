/**
===============================================================================
Exercice:               07-01-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      21.05.2024
Version:                1.0
===============================================================================
*/

#include <stdio.h>   //printf
#include <stdlib.h>  //scanf
#include <string.h>  //strcpy

#define EMPRUNT 0
#define RENDU 1

typedef struct{
   char titre[100];
   char auteur[100];
   int annee;
   int nb_copie;
} Livre;

Livre add(char *titre, char *auteur, int annee, int nb_copie ){
   Livre new;

   strcpy(new.titre, titre);
   strcpy(new.auteur, auteur);
   new.annee = annee;
   new.nb_copie = nb_copie;

   return new;
}

void update(Livre *livre, int etat){
   switch (etat){
      case EMPRUNT:
         livre->nb_copie--;
         break;
      case RENDU:
         livre->nb_copie++;
         break;
      default:
         printf("Etat du libre non-reconnu\n");
         break;
   }
}

void info(Livre livre){
   printf("Titre: %s\n", livre.titre);
   printf("Auteur: %s\n", livre.auteur);
   printf("Annee de publication: %d\n", livre.annee);
   printf("Nombre de copie: %d\n\n", livre.nb_copie);
}

int main(int argc, char *argv[]) {
   Livre livre = add("Oui-oui", "Tchoupi", 2000, 4);
   info(livre);
   update(&livre, EMPRUNT);
   info(livre);

   return 0;
}

/* 2e fois
#include <stdio.h>
#include <string.h>

#define MAX_LEN 80
#define MAX_BOOK 10

typedef struct {
   char title[MAX_LEN];
   char autor[MAX_LEN];
   int year;
   int nb_copie;
} Book;

Book newBook(char* title, char* autor, int year, int nb_copie) {
   Book new;
   strcpy(new.title, title);
   strcpy(new.autor, autor);
   new.year = year;
   new.nb_copie = nb_copie;
   return new;
}

typedef enum {RETURNED, BORROWED} State;

void updateCollection(Book* book, State state, int quantity) {
   if(state == RETURNED) {
      book->nb_copie += quantity;
   } else if (state == BORROWED) {
      book->nb_copie -= quantity;
   } else {
      printf("The number of book could not have been updated due to an incorrect State.\n");
   }
}

void bookInfo(const Book* book) {
   printf("Title: %s\nAutor: %s\nYear: %d\nNumber of copies in reserve: %d\n\n", book->title, book->autor, book->year, book->nb_copie);
}


int main()
{
   Book collection[MAX_BOOK];

   char title[MAX_LEN] = "L'histoire de ma vie";
   char autor[MAX_LEN] = "Emily Baquerizo";
   int year = 2024;
   int nb_copie = 42;

   collection[0] = newBook(title, autor, year, nb_copie);
   bookInfo(&collection[0]);

   updateCollection(&collection[0], BORROWED, 10);

   bookInfo(&collection[0]);

   return 0;
}
*/