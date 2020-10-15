#include <stdio.h>
#include <stdlib.h>

int CompareTo(const void * num1Ptr, const void * num2Ptr);
void PrintArray(int * array, size_t numElements);

int main(void) {

   /* Dynamically allocate array */
   int elementCount = 64;
   int * numbers = (int *) malloc(sizeof(int) * elementCount);

   /* Load random numbers into array */
   for (int i = 0; i < elementCount; i++) {
      numbers[i] = rand() % 512;
   }
   printf("**********************\n");
   printf("*  Unsorted Numbers  *\n");
   printf("**********************\n");
   PrintArray(numbers,elementCount);

   /* Sort the array in-place */
   qsort(numbers,elementCount,sizeof(int),CompareTo);
   
   printf("**********************\n");
   printf("*   Sorted Numbers   *\n");
   printf("**********************\n");
   PrintArray(numbers,elementCount);
   
   return 0;
}


int CompareTo(const void * num1Ptr, const void * num2Ptr) {

   return  *(int *)num1Ptr - *(int *)num2Ptr;

}

void PrintArray(int * array, size_t numElements) {
   for (size_t i = 0; i < numElements;) {
      for (size_t j = 0; i < numElements && j < 16; i++, j++) {
         printf("%3d ", array[i]);
      }
      printf("\n");
   }
}