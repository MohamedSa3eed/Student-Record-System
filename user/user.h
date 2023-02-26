#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef USER_H
#define USER_H

typedef struct StudentNode{
   unsigned int        age;
   unsigned int        score;
   unsigned int        passSize;
   unsigned int        id;
   char                name[100];
   char                gender[10];
   char                password[100];
   struct StudentNode* next;
}StudentNode;

typedef struct Student{
   unsigned int   numberOfStudents;
   unsigned int   nextID;
   StudentNode*   top;
   StudentNode*   end;
} Student;

void ViewRecord      (StudentNode *);
void EditPassword    (StudentNode *);
void EditName        (StudentNode *);

#endif
