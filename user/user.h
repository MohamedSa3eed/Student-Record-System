#include <stdio.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode
{
   int id ;
   char name [50] ;
   int age ;
   char gender [10];
   char password [10];
   int score ;
   struct StudentNode *next ;

} StudentNode ;

typedef struct Student 
{
   int numberOfStudents ;
   StudentNode *top ;
   StudentNode *end ;
   
} Student ;

void ViewRecord (Student *);
void EditPassword (Student *) ;
void EditName(Student *) ;

#endif
