#include <stdio.h>
#ifndef USER.H
#define USER.H

typedef struct StudentNode
{
   int id ;
   char[50] name ;
   int password ;
   int score ;
   struct StudentNode *next ;

} StudentNode ;

typedef struct Student 
{
   int numberOfStudents ;
   StudentNode *top ;
   
} Student ;

void ViewRecord ();
void EditPassword () ;
void EditName() ;

#endif
