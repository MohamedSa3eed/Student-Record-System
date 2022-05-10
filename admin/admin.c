#include <stdlib.h>
#include "admin.h"
#include "../user/user.h"

void AddStudent (int id ,int password,int score, Student *ps)
{
    StudentNode *p;
    p=(StudentNode*)malloc(sizeof (StudentNode));
    p->id=id;
   // p->name = name ;
    p->password = password ;
    p->score =score ;
    p->next =ps->top ;
    ps->top=p;
    ps->numberOfStudents ++;
}