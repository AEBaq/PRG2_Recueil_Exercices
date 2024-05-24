/**
===============================================================================
Exercice:               09-04-01
Course:                 PRG2
Year:                   2024
Modification Author:    Emily Baquerizo
Modification Date:      24.05.2024
Version:                1.0
===============================================================================
*/

// this program demonstrates the need for flushing buffer when stdout is in full buffer mode (no care for '\n')
// call it like this: bufferedPrint <nb chars in buffer for display> <when fflush should be invoked>
// fflush to be invoked
// - 0 => never
// - 1 => only after all inputs were requested
// - >1 => everytime

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

   if (argc != 3) {
      printf("Usage: bufferedPrint <buffer size = nb chars> <nb flushes = 0 (never), 1 (at end) or more (always)>\n");
      return EXIT_FAILURE;
   }

   int bufsiz = atoi(argv[1]), nflush = atoi(argv[2]);
   printf("buffer size = %d characters\n", bufsiz);
   printf("flush %s\n", (nflush > 1) ? "always" : (nflush > 0) ? "at the end" : "never");

   // according to https://en.cppreference.com/w/c/io/setvbuf
   // set FULL BUFFERING mode with fixed length
   setvbuf(stdout, (char *)NULL, _IOFBF, bufsiz);

   float number1, number2, number3;
   float average;

   printf("Enter the first number: ");
   if (nflush > 1) fflush(stdout);
   scanf("%f", &number1);
   printf("Enter the second number: ");
   if (nflush > 1) fflush(stdout);
   scanf("%f", &number2);
   printf("Enter the third number: ");
   if (nflush > 0) fflush(stdout);
   scanf("%f", &number3);

   average = (number1 + number2 + number3) / 3;

   printf("\nAverage is : %f\n", average);

   return 0;
}