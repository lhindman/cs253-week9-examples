/*
 * File: Employee.c
 * Author:  Luke Hindman
 * Date: Wed 14 Oct 2020 03:38:29 PM PDT
 * Description: Employee example using dynamic memory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee *CreateEmployee(const char name[], const char role[], const int id ) {
    /* Validate parameters */
    if (name == NULL || role == NULL) {
        return NULL;
    }

    /* Allocate space in the heap to store the Employee object
     *   and check the return value to confirm successful allocation */
    Employee * newEmployee = (Employee *) malloc (sizeof(Employee));
    if(newEmployee == NULL) {
        return NULL;
    }

    /* Allocate memory for the employee name and verify */
    newEmployee->name = (char *) malloc(sizeof(char) * (strlen(name) + 1) );
    if (newEmployee->name == NULL) {
        return NULL;
    }
    strcpy(newEmployee->name, name);

    /* Allocate memory for the employee role and verify */
    newEmployee->role = (char *) malloc(sizeof(char) * (strlen(role) + 1) );
    if (newEmployee->role == NULL) {
        return NULL;
    }
    strcpy(newEmployee->role, role);

    /* Set the ID value */
    newEmployee->id = id;

    return newEmployee;
}

void DestroyEmployee(Employee * e) {
    /* Validate parameter */
    if (e == NULL) {
        return;
    }

    /* Free the individual fields that were allocated
     *   with malloc in CreateEmployee() */
    free(e->name);
    e->name = NULL;

    free(e->role);
    e->role = NULL;

    /* Once the internal fields have been freed,
     *   free the struct itself.   There is no 
     *   point in setting e = NULL because e is 
     *   local to this function and we're not
     *   returning it. */
    free(e);
}

void PrintEmployee(Employee * e) {
    /* Validate parameter */
    if (e == NULL) {
        return;
    }

    printf("------------------------------\n");

    printf("Name: %s\n", e->name);
    printf("Role: %s\n", e->role);
    printf("ID: %d\n", e->id);

    printf("------------------------------\n");
}