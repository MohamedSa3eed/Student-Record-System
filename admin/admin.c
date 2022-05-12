#include <stdlib.h>
#include "admin.h"
#include "../user/user.h"

    // please someone do the UI for this :)

    void AddStudent (Student *ps)
{
    while (1)
    {
        StudentNode *p;
        p=(StudentNode*)malloc(sizeof (StudentNode));
        // please someone do the UI for this :)
        printf("Type student ID\n");
        scanf("%d",&(p->id));
        printf("Type student name\n");
        scanf("%s",&(p->name));
        printf("Type student password\n");
        scanf("%s",&(p->password));
        printf("Type student score\n");
        scanf("%d",&(p->score));
        p->next =ps->top ;
        ps->top=p;
        ps->numberOfStudents ++;
        printf("press 0 to go back\n press 1 to continue adding students \n");
        int choice = 0;
        scanf("%d",&choice);
        if(choice !=0) choice =1;
        if(!choice)break;
    }
}

void ViewStudentRecord(Student *ps)
{
    // please handel wrong id // I think its now handeled
    while (1)
    {
        int flag = 0;
        int id ;
        printf(" enter the student ID that you want to show\n");
        scanf("%d",&id);
        StudentNode *p = ps->top ;
        for (int i = 0 ; i < ps->numberOfStudents;i++ )
        {
            if (id == p->id )
            {
                flag =1;
                printf("%d",p->score);
            }
            p = p ->next ;
        }
        if(flag == 0)
        {
            printf("there is no such ID\n please enter a valid one\n");
            continue;
        }
        break;
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
    // please handel wrong id // I think its now handeled
    while (1)
    {
        int flag = 0;
        int id ;
        scanf("%d",&id);
        StudentNode *p = ps->top ;
        for (int i = 0 ; i < ps->numberOfStudents;i++ )
        {
            if (id == p->id )
            {
                flag = 1;
                scanf("%d",p->score);
            }
            p = p ->next ;
        }
        if(flag == 0)
        {
            printf("there is no such ID\n please enter a valid one\n");
            continue;
        }
        break;
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