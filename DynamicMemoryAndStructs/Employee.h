/*
 * File: Employee.h
 * Author:  Luke Hindman
 * Date: Wed 14 Oct 2020 03:38:29 PM PDT
 * Description: Employee example using dynamic memory
 */
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

/* Define the Employee struct */
struct employee {
   char * name;
   char * role;
   int    id;
};
typedef struct employee Employee;

/* CreateEmployee: Allocate a new Employee object in the heap using malloc()
 *    with the specified name, role and id.  All Employee
 *    objects allocated using this function MUST be deallocated
 *    by calling the DestroyEmployee() function.
 * name - Null terminated string of chars representing employee name
 * role - Null terminated string of chars representing employee role
 * id - integer value representing employee id number
 * returns - pointer to heap allocated Employee object, NULL on error
 */
Employee *CreateEmployee(const char name[], const char role[], const int id );

/* DestroyEmployee: Deallocate memory allocated by CreateEmployee function. 
 *    This will encapsulate the freeing of Employee object memory to 
 *    prevent memory leaks
 * e - pointer to Employee object to be freed
 */
void DestroyEmployee(Employee * e);

/* PrintEmployee: Display the Employee object to stdout in console
 * e - pointer to Employee object to be displayed
 */
void PrintEmployee(Employee * e);

#endif /* __EMPLOYEE_H */