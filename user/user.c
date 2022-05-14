#include <stdio.h>
#include "user.h"
//not tested yet
void ViewRecord(Student * ps,int *pid)
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
                printf("name: %s\n",p->name);
                printf("ID: %d\n",p->id);
                printf("age: %d\n",p->age);
                printf("score: %d\n",p->score);
                printf("gender: %s\n",p->gender);


            }
            p=p->next ;
        }


}
void EditPassword (Student* ps,int *pid)
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
                printf("enter the new password for ID %d:\n",id);
                scanf("%s",p->password);
            }
            p=p->next ;
        }



}

void EditName(Student* ps,int * pid)
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
                printf("enter new name: \n");
                scanf("%s",p->name);
            }
            p=p->next ;
        }

}
