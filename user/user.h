#include <stdio.h>
#ifndef USER_H
#define USER_H

#pragma pack(1)
typedef struct StudentNode
{
   int id ;
   char name [50] ;
   int age ;
   char gender [10];
   char password [20];
   int score ;
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
