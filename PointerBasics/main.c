#include <stdio.h>

int main(void) {

   /*
    * Pointer basics
    */

   printf("*\n* Pointer Basics\n*\n");
   /* Start by declaring a variable to hold a int value */
   int roomCapacity = 111000000;

   /* Store the address of that variable in an int * variable (int pointer) */
   int * capacityPtr = &roomCapacity;

   /* Use the dereference operator ( * ) to access the data stored at the pointer address */
   printf("The room capacity is: %d\n", *capacityPtr);


   /*
    * Pointers generally are declared with a type such as int *, long * or char *.  This
    *    allows C to know the proper data type and number of bytes to process when
    *    applying the dereference operator.  However it is possible to have a pointer 
    *    with no assocated data type, void * (void pointer).  Since a void pointer does
    *    not have an associated type, it must be cast to the proper pointer type 
    *    before being deferenced.  It is incorrect to attempt to dereference a void pointer.
    */
   printf("\n*\n* Void Pointers and Casting\n*\n");
   void * data = &roomCapacity;

   char * charDataPtr = (char *) data;

   printf("The data value as a char is: %c\n", *charDataPtr);

   int * intDataPtr = (int * ) data;

   printf("The data value as an int is: %d\n", *intDataPtr);

   double * dblDataPtr = (double *) data;

   printf("The data value as a double is: %lf\n", *dblDataPtr);


   return 0;
}
