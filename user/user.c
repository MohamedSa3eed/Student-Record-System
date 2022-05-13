#include <stdio.h>
#include "user.h"
//not tested yet
void ViewRecord(Student * ps,int *pid)
{
    while(1)
    {
     int id=*pid,i,state=0;
    // printf("enter your id\n");
    // scanf("%d",&id);
     StudentNode * p = ps->top ;
     for (i=0;i<ps->numberOfStudents;i++)
        {
            if (id == p->id )
            {
                state =1;
                printf("%s",p->name);
                printf("%d",p->id);
                printf("%d",p->score);
            }
            p=p->next ;
        }
        if(state== 0)
        {
            printf("enter a valid id\n");
            continue;
        }
        break;
    }
}
void EditPassword (Student* ps,int *pid)
{
     while (1)
    {
        int id=*pid,i,state = 0;
        // printf("enter your id\n");
        //scanf("%d",&id);
        StudentNode *p = ps->top ;
        for (i=0;i<ps->numberOfStudents;i++)
        {
            if (id == p->id )
            {
                state= 1;
                scanf("%s",p->password);
            }
            p=p->next ;
        }
        if(state == 0)
        {
            printf("enter a valid id\n");
            continue;
        }
        break;
    }
}

void EditName(Student* ps,int * pid)
{
     while (1)
    {
        int id=*pid,i,state = 0;
       // printf("enter your id\n");
        //scanf("%d",&id);
        StudentNode *p = ps->top ;
        for (i=0;i<ps->numberOfStudents;i++)
        {
            if (id == p->id )
            {
                state= 1;
                scanf("%s",p->name);
            }
            p=p->next ;
        }
        if(state == 0)
        {
            printf("enter a valid id\n");
            continue;
        }
        break;
    }
}
