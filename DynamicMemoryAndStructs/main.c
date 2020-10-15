/*
 * Author: Luke Hindman
 * Date: Wed 14 Oct 2020 04:16:30 PM PDT
 * Description: Employee example using dynamic memory
 * 
 * valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./myprog
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


int main(void) {
   Employee * worker1;
   Employee * worker2; 

   worker1 = CreateEmployee("Ted Mosby", "Architect", 11160726);
   PrintEmployee(worker1);

   worker2 = CreateEmployee("Marshall Eriksen", "Environmental Lawyer", 11160727);
   PrintEmployee(worker2);

   DestroyEmployee(worker1);
   DestroyEmployee(worker2);

   return 0;
}

 

