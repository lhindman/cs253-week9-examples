#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Employee struct */
struct employee {
   char * name;
   char * role;
   int * id;
   struct employee * coworker;
};
typedef struct employee Employee;

/* Declare functions */
void PrintEmployee(Employee * e);

/* Declare and initialize a few global variables */ 
char globalName[80];
char globalRole[80];
int globalID;

int main(void) {

   Employee worker;

   strcpy(globalName,"Ted Mosby");
   strcpy(globalRole,"Architect");
   globalID = 11160726;
   
   /* This works because globalName and globalRole
    *   are allocated in the data segment and have
    *   a data lifetime for the life of the process */
   worker.name = globalName;
   worker.role = globalRole;
   worker.id = &globalID;

   PrintEmployee(&worker);

   strcpy(globalName, "Marshall Eriksen");
   strcpy(globalRole, "Environmental Lawyer");
   globalID = 11160727;

   PrintEmployee(&worker);

   return 0;
}

 
void PrintEmployee(Employee * e) {
   printf("------------------------------\n");

   printf("Name: %s\n", e->name);
   printf("Role: %s\n", e->role);
   printf("ID: %d\n", *e->id);

   printf("------------------------------\n");
}
