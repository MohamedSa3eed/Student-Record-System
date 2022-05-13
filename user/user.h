#include <stdio.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode
{
   int id ;
   char name [50] ;
   char password [10];
   int score ;
   struct StudentNode *next ;

} StudentNode ;

typedef struct Student 
{
   StudentNode *end ;
   int numberOfStudents ;
   StudentNode *top ;
   
} Student ;

void ViewRecord ();
void EditPassword () ;
void EditName() ;

#endif
