/**
===============================================================================
Exercice:               11-02
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      23.06.24
Version:                1.0
===============================================================================
*/

#include "queue.h"

void* new_queue(){
   //printf("new\n");
   Stack *stack = (Stack *)malloc(sizeof(Stack));
   assert(stack != NULL);

   stack->first = NULL;
   stack->last = NULL;

   return stack;
}

void free_queue(void* stack){
   //printf("free\n");
   assert(stack != NULL);
   while(((Stack *)stack)->first){
      pop_from_queue(stack);
   }
   free(stack);
}

void push_in_queue(void* stack, int i){
   //printf("push\n");
   struct Node *new = (struct Node *)malloc(sizeof(struct Node));
   assert(new != NULL);
   new->data = i;
   new->nxt = NULL;
   if(((Stack *)stack)->first == NULL) ((Stack *)stack)->first = new;
   if(((Stack *)stack)->last != NULL) ((Stack *)stack)->last->nxt = new;
   ((Stack *)stack)->last = new;
}

void pop_from_queue(void* stack){
   //printf("pop\n");
   assert(((Stack *)stack)->first != NULL);
   struct Node *tmp = ((Stack *)stack)->first;
   ((Stack *)stack)->first = tmp->nxt;
   free(tmp);
}

int front_of_queue(void* stack){
   //printf("front\n");
   assert(stack != NULL);
   return (((Stack *)stack)->first->data);
}

int back_of_queue(void* stack){
   //printf("back\n");
   assert(stack != NULL);
   return (((Stack *)stack)->last->data);
}

int size_of_queue(void* stack){
   //printf("size\n");

   if((Stack *)stack == NULL) return 0;
   int n = 0;
   struct Node *ptr = ((Stack *)stack)->first;
   while(ptr){
      n++;
      ptr = ptr->nxt;
   }
   return n;
}

