#include <stdio.h>
#include <stdlib.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode
{
   
   int age ;
   int score ;
   int passSize;
   int id ;
   char *gender;
   char *password;
   char *name;
   struct StudentNode *next ;

} StudentNode ;

typedef struct Student 
{
   int numberOfStudents ;
   StudentNode *top ;
   StudentNode *end ;
   int nextID;
   
} Student ;

void ViewRecord (StudentNode*);
void EditPassword (StudentNode *) ;
void EditName(StudentNode *) ;

#endif
