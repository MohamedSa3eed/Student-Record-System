#include <stdio.h>
#include <stdlib.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode
{
   char *gender;
   char *password;
   char *name;
   int age ;
   int score ;
   int passSize;
   int id ;
   struct StudentNode *next ;

} StudentNode ;

typedef struct Student 
{
   int numberOfStudents ;
   StudentNode *top ;
   StudentNode *end ;
   
} Student ;

void ViewRecord (Student *,int*);
void EditPassword (Student *,int * ) ;
void EditName(Student *,int *) ;

#endif
