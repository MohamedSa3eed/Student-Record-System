#include <stdlib.h>
#include "admin.h"
#include "../user/user.h"

// please someone do the UI for this :)

void AddStudentRecord(Student *ps)
{
    while (1)
    {
        StudentNode *p;
        p = (StudentNode *)malloc(sizeof(StudentNode));
        // please someone do the UI for this :)
        printf("Type student ID\n");
        scanf("%d", &(p->id));
        printf("Type student name\n");
        scanf("%s", (p->name));
        printf("Type student age\n");
        scanf("%d", &(p->age));
        printf("Type student gender\n");
        scanf("%s", (p->gender));
        printf("Type student password\n");
        scanf("%s", (p->password));
        printf("Type student score\n");
        scanf("%d", &(p->score));
        p->next = NULL;
        if (!ps->numberOfStudents)
        {
            ps->top = p;
            ps->end = p;
        }
        else
        {
            ps->end->next = p;
            ps->end = p;
        }
        ps->numberOfStudents++;
        printf("press 0 to go back\npress 1 to continue adding students \n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice != 0)
            choice = 1;
        if (!choice)
            break;
    }
}

void ViewStudentRecord(Student *ps)
{
    // please handel wrong id // I think its now handeled
    while (1)
    {
        int flag = 0;
        int id;
        printf("enter the student ID that you want to show\n");
        scanf("%d", &id);
        StudentNode *p = ps->top;
        for (int i = 0; i < ps->numberOfStudents; i++)
        {
            if (id == p->id)
            {
                flag = 1;
                printf("name: %s\n", p->name);
                printf("ID: %d\n", p->id);
                printf("age: %d\n", p->age);
                printf("score: %d\n", p->score);
                printf("gender: %s\n", p->gender);
            }
            p = p->next;
        }
        if (flag == 0)
        {
            printf("there is no such ID\nplease enter a valid one\n");
            continue;
        }
        printf("press 0 to go back\npress 1 to continue viewing students \n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice != 0)
            choice = 1;
        if (!choice)
            break;
    }
}
void ViewAllRecords(Student *ps)
{
    StudentNode *p = ps->top;
    for (int i = 0; i < ps->numberOfStudents; i++)
    {
        printf("name: %s\n", p->name);
        printf("ID: %d\n", p->id);
        printf("age: %d\n", p->age);
        printf("score: %d\n", p->score);
        printf("gender: %s\n", p->gender);
        printf("-------------------\n");
        p = p->next;
    }
}
void EditStudentGrade(Student *ps)
{
    // please handel wrong id // I think its now handeled
    while (1)
    {
        int flag = 0;
        int id;
        printf("enter the student ID that you want to edit\n");
        scanf("%d", &id);
        StudentNode *p = ps->top;
        for (int i = 0; i < ps->numberOfStudents; i++)
        {
            if (id == p->id)
            {
                flag = 1;
                printf("the new score is : \n");
                scanf("%d", &(p->score));
            }
            p = p->next;
        }
        if (flag == 0)
        {
            printf("there is no such ID\nplease enter a valid one\n");
            continue;
        }
        printf("press 0 to go back\npress 1 to continue editing student records \n");
        int choice = 0;
        scanf("%d", &choice);
        if (choice != 0)
            choice = 1;
        if (!choice)
            break;
    }
}

void RemoveStudentRecord(Student *ps)
{
    // please handel wrong id
    printf("Enter the ID of the student you want to remove: ");
    int id;
    scanf("%d", &id);
    if (ps->numberOfStudents == 0) // code to handle the case where there is 0 nodes in the list
    {
        printf("There isn't students in the list.\n");
    }
    else if (ps->numberOfStudents == 1) // code to handle the case where there is only one node in the list which is the head and tail of the list
    {
        if (id==ps->top->id)
        {
            free(ps->top);
            ps->top = NULL;
            ps->end = NULL;
            ps->numberOfStudents--;
            printf("Student deleted successfully.\n");
            printf("The student list is now empty.\n");
            printf("-----------------------------\n");
        }
        else{
            printf("Student not found.\n");
            printf("------------------\n");
        }
    }
    else
    { // code to handle if there is more than 1 node in the list
        StudentNode *p = ps->top;
        for (int i = 0; i < (ps->numberOfStudents) - 1; i++)
        {
            if ((i == 0) && (p->id == id)) // if we want to delete the haed node
            {
                free(ps->top);     // free the space of the unwanted node
                ps->top = p->next; // the current node will point to the node after the node wanted to be deleted
                ps->numberOfStudents--;
                printf("Student deleted successfully.\n");
                printf("-----------------------------\n");
                break;
            }
            if (id == (p->next)->id) // if the next node is the node to be deleted
            {
                if (i == (ps->numberOfStudents) - 2)
                {
                    ps->end = p;    // the current node will point to the node after the node wanted to be deleted
                    free(p->next);  // free the space of the unwanted node
                    p->next = NULL; // assgin the deleted node pointer to null
                    ps->numberOfStudents--;
                    printf("Student deleted successfully.\n");
                    printf("-----------------------------\n");
                    break;
                }
                StudentNode *ptemp = p->next->next;
                free(p->next);
                p->next = (ptemp); // the current node will point to the node after the node wanted to be deleted
                                   // free the space of the unwanted node
                // p->next=NULL;   // assgin the deleted node pointer to null
                ps->numberOfStudents--;
                printf("Student deleted successfully.\n");
                printf("-----------------------------\n");
                break;
            }
            else
                p = p->next;

            if (i == (ps->numberOfStudents) - 2)
            {
                printf("Student not found.\n");
                printf("------------------\n");
            }
        }
    }
}

//     while(1)
//     {
//         int flag =0;
//         printf("enter the student ID that you want to remove\n");
//         int id ;
//         scanf("%d",&id);
//         StudentNode *p = ps->top ;
//         StudentNode *x = NULL ;
//         int wanted ;
//         for (int i = 0 ; i < ps->numberOfStudents;i++ )
//         {
//             if (id == p->id )
//             {
//                 flag =1;
//                 x = p ;
//                 wanted = i+1 ;
//             }

//             p = p ->next ;
//         }
//         if(flag == 0)
//         {
//             printf("there is no such ID\nplease enter a valid one\n");
//             continue;
//         }
//         p = ps->top ;
//         for (int i = 0 ; i < wanted  ;i++ )
//         {
//             if(i== wanted-1)
//             {
//                 if(ps->numberOfStudents == 1)
//                 {
//                     ps ->top = NULL;
//                     ps ->end = NULL;
//                     free(x);
//                     break;
//                 }
//                 if(i == 0)
//                 {
//                     ps->top = x->next;
//                 } else
//                 { p->next = x->next ;}
//                     free(x);
//                     ps->numberOfStudents -- ;
//                     break;
//             }
//             p = p ->next ;
//         }
//         printf("press 0 to go back\npress 1 to continue removing students \n");
//         int choice = 0;
//         scanf("%d",&choice);
//         if(choice !=0) choice =1;
//         if(!choice)break;
//     }
//
//}
void EditAdminPassword(char *password)
{
    printf("enter the new password : \n ");
    scanf("%s", password);
}
