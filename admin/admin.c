#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "../user/user.h"


void AddStudentRecord(Student *ps,int id_) {
    StudentNode *p;
    char* tmp;
    p=(StudentNode*)malloc(sizeof(StudentNode));
    printf("Adding new student. ID : %d\n",id_);
    p->id=id_;
    gets(tmp);
    printf("  Enter student name:");
    gets(p->name);
    printf("  Enter student password:");
    gets(p->password);
    printf("  Enter student gender:");
    gets(p->gender);
    printf("  Enter student age: ");
    scanf("%d", &(p->age));
xxx:
    printf("  Enter student score(0/100): ");
    scanf("%d", &(p->score));
    if (p->score<0||p->score>100) {
        goto xxx;
    }
    p->next = NULL;
    if (ps->numberOfStudents==0) {
        ps->top = p;
        ps->end = p;
    }
    else {
        ps->end->next = p;
        ps->end = p;
    }
    ps->numberOfStudents++;
    printf("Student added.\n");
    printf("---------------------------\n");
}

void ViewStudentRecord(StudentNode *p) {
    printf("  ID: %d\n", p->id);
    printf("  name: %s\n", p->name);
    printf("  age: %d\n", p->age);
    printf("  score: %d\n", p->score);
    printf("  gender: %s\n", p->gender);
    printf("-------------------\n");
}
void ViewAllRecords(Student *ps) {
    StudentNode *p = ps->top;
    for (int i = 0; i < ps->numberOfStudents; i++) {
        ViewStudentRecord(p);
        p = p->next;
    }
}
void EditStudentGrade(StudentNode *p) {
    printf("the new score is : \n");
    scanf("%d", &(p->score));
}

void RemoveStudentRecord(Student *ps) {
    printf("Enter the ID of the student you want to remove: ");
    int id;
    scanf("%d", &id);
    if (ps->numberOfStudents == 0){ // code to handle the case where there is 0 nodes in the list 
        printf("There isn't students in the list.\n");
        printf("-----------------------------\n");
    }
    else if (ps->numberOfStudents == 1){ // code to handle the case where there is only one node in the list which is the head and tail of the list
        if (id==ps->top->id) {
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
    else { // code to handle if there is more than 1 node in the list
        StudentNode *p = ps->top;
        for (int i = 0; i < (ps->numberOfStudents) - 1; i++) {
            if ((i == 0) && (p->id == id)) {// if we want to delete the haed node
                free(ps->top);     // free the space of the unwanted node
                ps->top = p->next; // the current node will point to the node after the node wanted to be deleted
                ps->numberOfStudents--;
                printf("Student deleted successfully.\n");
                printf("-----------------------------\n");
                break;
            }
            if (id == (p->next)->id) {// if the next node is the node to be deleted
                if (i == (ps->numberOfStudents) - 2) {
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
            else p = p->next;

            if (i == (ps->numberOfStudents) - 2) {
                printf("Student not found.\n");
                printf("------------------\n");
            }
        }
    }
}

void EditAdminPassword(char *password) {
    printf("enter the new password : ");
    scanf("%s", password);
}
