/**
===============================================================================
Exercice:               11-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      23.06.24
Version:                1.0
===============================================================================
*/

#ifndef PRG2_RECUEIL_EXERCICES_QUEUE_H
#define PRG2_RECUEIL_EXERCICES_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{
   struct Node *nxt;
   int data;
};

typedef struct {
   struct Node *first;
   struct Node *last;
} Stack;

void* new_queue();
void free_queue(void*);

void push_in_queue(void*, int i);
void pop_from_queue(void*);
int front_of_queue(void*);
int back_of_queue(void*);
int size_of_queue(void*);


#endif //PRG2_RECUEIL_EXERCICES_QUEUE_H
