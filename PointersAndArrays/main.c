#include <stdio.h>

int main(void) {

   /* Lets start with an array of chars, also known as a string */
   char phrase[] = "Life is like a box of chocolates";

   // printf("char using array syntax:  %c\n", phrase[6]);
   // printf("char using pointer syntax:  %c\n", *(phrase + 6));

   char * myFirstCharPtr = phrase + 0;
   char * mySecondCharPtr = phrase + 2;

   printf("First Char: %c\n", *myFirstCharPtr);
   printf("Second Char: %c\n", *mySecondCharPtr);

   printf("Address of First Char: %p\n", myFirstCharPtr);
   printf("Address of Second Char: %p\n", mySecondCharPtr);
   

   /* Let's look at the same thing again, but with an array of ints instead of chars */ 
   int numbers[10];
   for (int i = 0; i < 10; i++) {
      numbers[i] = i;
   }

   int * myFirstIntPtr = numbers;
   int * mySecondIntPtr = numbers + 2;

   printf("First Int:  %d\n", *myFirstIntPtr);
   printf("Second Int:  %d\n", *mySecondIntPtr);

   printf("Address of First Int: %p\n", myFirstIntPtr);
   printf("Address of Second Int: %p\n", mySecondIntPtr);

   /* We can also use the ++/-- operators as a shorthand for walking through
    * the elements of an array using pointers */
   char * index = phrase;
   printf("forward using ++: ");
   while (*index != '\0') {
      printf("%c", *index++);
   }
   printf("\n");

   printf("reverse using --: ");
   while (index >= phrase) {
      printf("%c", *index--);
   }
   printf("\n");

   return 0;
}
