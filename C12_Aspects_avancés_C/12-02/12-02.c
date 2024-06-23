/**
===============================================================================
Exercice:               12-02
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      23.06.24
Version:                1.0
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef void (*func_t)(void *data);

typedef struct task_collection{
   func_t fn;
   void *args;
   struct task_collection *next;
}task_collection_t;

//task_collection_t  *task_collection = NULL;

void task_A(void *args){
   printf("Execution of task A\n");
}

void task_B(void* args){
   printf("Execution of task B with args: %s\n", (char*) args);
}

void func_register(task_collection_t **task_collection, func_t fn, void *args){
   task_collection_t *prev, *new;
   new = calloc(1, sizeof(task_collection_t));
   assert(new != NULL);

   new->fn = fn;
   new->args = args;

   if(*task_collection){
      prev = *task_collection;
      while(prev->next){
         prev = prev->next;
      }
      prev->next = new;
   }else{
      *task_collection = new;
   }
}

void do_work(task_collection_t *task_collection) {
   while(task_collection != NULL) {
      task_collection->fn(task_collection->args);
      task_collection = task_collection->next;
   }
}

int main(){
   task_collection_t  *task_collection = NULL;

   func_register(&task_collection, task_A, NULL);
   func_register(&task_collection, task_B, "Hello");

   do_work(task_collection);

   free(task_collection);

   return EXIT_SUCCESS;
}

