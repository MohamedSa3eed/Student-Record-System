#include <stdlib.h>
#include "admin.h"
#include "../user/user.h"

    // please someone do the UI for this :)

void AddStudent (Student *ps)
{
    StudentNode *p;
    p=(StudentNode*)malloc(sizeof (StudentNode));
    // please someone do the UI for this :) 
    scanf("%d",&(p->id)); 
    scanf("%s",&(p->name));
    scanf("%s",&(p->password));
    scanf("%d",&(p->score));
    p->next =ps->top ;
    ps->top=p;
    ps->numberOfStudents ++;
}

void ViewStudentRecord(Student *ps)
{
    // please handel wrong id 
    int id ; 
    scanf("%d",id);
    StudentNode *p = ps->top ;
    for (int i = 0 ; i < ps->numberOfStudents;i++ )
    {
        if (id == p->id )
        {
            printf("%d",p->score);
        }
        p = p ->next ;
    }
}
void ViewAllRecords(Student *ps)
{
    StudentNode *p = ps->top ;
    for (int i = 0 ; i < ps->numberOfStudents;i++ )
    {
        printf("%d : ",p->name);
        printf("%d",p->score);
        p = p ->next ;
    }
}
void EditStudentGrade(Student *ps)
{
    // please handel wrong id 
    int id ; 
    scanf("%d",id);
    StudentNode *p = ps->top ;
    for (int i = 0 ; i < ps->numberOfStudents;i++ )
    {
        if (id == p->id )
        {
            scanf("%d",p->score);
        }
        p = p ->next ;
    }
}
/*
void RemoveStudentRecord (Student *ps) 
{
    // please handel wrong id 
    int id ; 
    scanf("%d",id);
    StudentNode *p = ps->top ;
    int wanted ;
   for (int i = 0 ; i < ps->numberOfStudents;i++ )
    {
       if (id == p->id )
        {
           wanted = i ;
        }
        
        p = p ->next ;
    }

}
*/