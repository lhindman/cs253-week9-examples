#include <stdio.h>
#include <stdlib.h>

int main(void) {

   /* Dynamically allocate an array of 10 ints in the heap */

   int elementCount = 10;
   int * numbers = (int *) malloc (sizeof(int) * elementCount);

   printf("Size of numbers: %ld bytes\n", sizeof(numbers));
   printf("Actual size of numbers array: %ld bytes\n", sizeof(int) * elementCount);

   /* If malloc runs into an issue allocating the requested amount of memory,
    *   it will return NULL;  It is good to check for that, otherwise your
    *   program will segfault the first time you try to access the array */
   if (numbers == NULL) {
      printf("Error: Unable to allocate memory for numbers array!\n");
      exit(1);
   }

   /* We can use the numbers array just like a normal array,
    *  except that we must keep track of the length of the
    *  array ourselves. */
   for (int i = 0; i < elementCount; i++) {
      numbers[i] = i * 100;
   }

   printf("Array Contents: ");
   for (int i = 0; i < elementCount; i++) {
      printf("%d ", numbers[i]);
   }
   printf("\n");

   /* Recall from CS121 how we can "grow" an array? 
    *   1. Create a new array that is twice the size of the original
    *   2. Copy the contents from the first array into the second
    *   3. Update the reference variable
    * Let's try that same process here */
   int * newNumbers = (int *) malloc(sizeof(int) * 2 * elementCount);
   
   /* Again, there might not be enough memory to double the size of the array,
    *   better check. */
   if (newNumbers == NULL) {
      printf("Error: Unable to allocate memory when growning array!\n");
      exit(1);
   }
   
   /* Copy old array into new array */
   for (int i = 0; i < elementCount; i++) {
      newNumbers[i] = numbers[i];
   }

   /* Release unused memory and reset pointer to NULL to 
    *   prevent accidental use of freed memory */
   // free(numbers);
   // numbers = NULL;

   /* Update numbers pointer and elementCount */
   numbers = newNumbers;
   elementCount = elementCount * 2;

   /* The code runs fine, but we've created a memory leak.  The valgrind tool
    *   enables us to analyse heap memory allocations.
    * 
    *  valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./myprog
    */
   // free(numbers);
   // numbers = NULL;

   return 0;
}
