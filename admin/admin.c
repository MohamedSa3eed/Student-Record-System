#include <stdlib.h>
#include "admin.h"
#include "../user/user.h"

    // please someone do the UI for this :)

    void AddStudentRecord (Student *ps)
{
    while (1)
    {
        StudentNode *p;
        p=(StudentNode*)malloc(sizeof (StudentNode));
        // please someone do the UI for this :)
        printf("Type student ID\n");
        scanf("%d",&(p->id));
        printf("Type student name\n");
        scanf("%s",(p->name));
        printf("Type student age\n");
        scanf("%s",&(p->age));
        printf("Type student gender\n");
        scanf("%s",(p->gender));
        printf("Type student password\n");
        scanf("%s",(p->password));
        printf("Type student score\n");
        scanf("%d",&(p->score));
        p->next = NULL ;
        if (! ps-> numberOfStudents )
         { 
            ps->top=p;
            ps->end=p;
         }
         else
         {
             ps->end->next=p ;
             
         }
        ps->numberOfStudents ++;
        printf("press 0 to go back\npress 1 to continue adding students \n");
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
        printf("enter the student ID that you want to show\n");
        scanf("%d",&id);
        StudentNode *p = ps->top ;
        for (int i = 0 ; i < ps->numberOfStudents;i++ )
        {
            if (id == p->id )
            {
                flag =1;
                printf("%d\n",p->score);
            }
            p = p ->next ;
        }
        if(flag == 0)
        {
            printf("there is no such ID\nplease enter a valid one\n");
            continue;
        }
        printf("press 0 to go back\npress 1 to continue viewing students \n");
        int choice = 0;
        scanf("%d",&choice);
        if(choice !=0) choice =1;
        if(!choice)break;

    }
}
void ViewAllRecords(Student *ps)
{
    StudentNode *p = ps->top ;
    for (int i = 0 ; i < ps->numberOfStudents;i++ )
    {
        printf("%s : ",p->name);
        printf("%d\n",p->score);
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
        printf("enter the student ID that you want to edit\n");
        scanf("%d",&id);
        StudentNode *p = ps->top ;
        for (int i = 0 ; i < ps->numberOfStudents;i++ )
        {
            if (id == p->id )
            {
                flag = 1;
                printf("the new score is : \n");
                scanf("%d",&(p->score));
            }
            p = p ->next ;
        }
        if(flag == 0)
        {
            printf("there is no such ID\nplease enter a valid one\n");
            continue;
        }
        printf("press 0 to go back\npress 1 to continue editing student records \n");
        int choice = 0;
        scanf("%d",&choice);
        if(choice !=0) choice =1;
        if(!choice)break;
    }
}

void RemoveStudentRecord (Student *ps) 
{
    // please handel wrong id

    while(1)
    {
        int flag =0;
        printf("enter the student ID that you want to remove\n");
        int id ;
        scanf("%d",&id);
        StudentNode *p = ps->top ;
        StudentNode *x = NULL ;
        int wanted ;
        for (int i = 0 ; i < ps->numberOfStudents;i++ )
        {
            if (id == p->id )
            {
                flag =1;
                x = p ;
                wanted = i ;
            }
        
            p = p ->next ;
        }
        if(flag == 0)
        {
            printf("there is no such ID\nplease enter a valid one\n");
            continue;
        }
        p = ps->top ;
        for (int i = 0 ; i < wanted ;i++ )
        {
            if(i== wanted-1)
            {
                p->next = x->next ;
                free(x);
                ps->numberOfStudents -- ;
            }
            p = p ->next ;
        }
        printf("press 0 to go back\npress 1 to continue removing students \n");
        int choice = 0;
        scanf("%d",&choice);
        if(choice !=0) choice =1;
        if(!choice)break;
    }

}
void EditAdminPassword(char * password)
{
    printf ("enter the new password : \n ");
    scanf("%s",password);

}
