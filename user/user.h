#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode
{
   
   int age ;
   int score ;
   int passSize;
   int id ;
   char gender[10];
   char password[100];
   char name[100];
   struct StudentNode *next ;

} StudentNode ;

typedef struct Student 
{
   int numberOfStudents ;
   StudentNode *top ;
   StudentNode *end ;
   int nextID;
   
} Student ;

void ViewRecord (StudentNode *);
void EditPassword (StudentNode *) ;
void EditName(StudentNode *) ;

#endif
