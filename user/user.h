#include <stdio.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode {
   int                  id;
   int                  age;
   int                  score;
   char                 name[50];
   char                 gender[10];
   char                 password[20];
   struct StudentNode*  next ;
} StudentNode ;

typedef struct Student {
   int            numberOfStudents ;
   StudentNode*   top ;
   StudentNode*   end ;
} Student;

void ViewRecord (Student *,int*);
void EditPassword (Student *,int * ) ;
void EditName(Student *,int *) ;

#endif
