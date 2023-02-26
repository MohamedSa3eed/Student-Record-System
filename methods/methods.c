#include "methods.h"
#include "../admin/admin.h"
#include "../user/user.h"
#include"stdio.h"
#include <string.h>

int Mode() {
    while (1) {
        printf("Welcome to SCS \n--------------------------------------\n 0 for admin mode \n 1 for user mode \n");
        int x ;
        scanf("%d",&x);
        if(x == 0 || x== 1) {
            return x ;
        } 
        else printf("please enter a valid number\n");
    }
}
int AdminLogin(int tries_,char * password) {
    int tries = tries_;
    while(1) {
        const char *saved_admin_password = password;//"magicpassword"; //temp save
        char admin_password[20];
        printf("Please enter your password\n");
        scanf("%s",admin_password);
        int compare_password = strcmp(saved_admin_password,admin_password);
        if( !compare_password)
            return 1;

        else {
            printf("The password is wrong\n");
            tries-- ;
        }

        if (!tries) {
            printf("\nyou ran out of tries");
            return 0 ;
        }
    }
}


int UserLogin(int tries_,int* pid,Student *s) {
    int tries = tries_;
    while(tries--) {
        char user_password[20];
        printf("Please enter you ID\n");
        scanf("%d",pid);
        printf("Please enter your password\n");
        scanf("%s",user_password);
        int found = user_found(s,pid,user_password);
        if(found) {
            return 1;
        } 
        else {
            printf("invalid password or id.\n");
        }
    }
    printf("\nyou ran out of tries");
    return 0 ;
}
void DisplayAdminOptions(Student*s,char* password) {
    while (1) {
        int choice = 0;
        int flag = 0;
        printf("\npress 0 to logout\n 1 to add student record \n 2 Remove student record \n 3 view student record \n 4 view all records \n 5 Edit admin password \n 6 edit student grade \n");
        scanf("%d",&choice);
        switch (choice) {
            case 0:
                flag =1 ;
                break;
            case 1:
                AddStudentRecord(s);
                break;
            case 2:
                RemoveStudentRecord(s);
                break;
            case 3:
                ViewStudentRecord(s);
                break;
            case 4:
                ViewAllRecords(s);
                break;
            case 5:
                EditAdminPassword(password);
                break;
            case 6:
                EditStudentGrade(s);
                break;
            default:
                printf("Please enter a valid number\n");
                break;
        }
        if (flag == 1 ) {
            break;
        }
    }
}

void DisplayUserOptions(Student*s,int* pid) {
    while (1) {
        int choice = 0;
        int flag = 0;
        printf("\npress 0 to logout\n 1 to view your record \n 2 Edit your password \n 3 Edit your name\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                flag =1;
                break;
            case 1:
                ViewRecord(s,pid);
                break;
            case 2:
                EditPassword(s,pid);
                break;
            case 3:
                EditName(s,pid);
                break;
            default:
                printf("Please enter a valid number\n");
        }
        if (flag ==1) {
            break;
        }
    }
}

void CreateStudentList (Student *ps)
{
   ps->top=NULL ;
   ps->end=NULL ;
   ps->numberOfStudents =0 ;
}
int user_found(Student *ps,int *pid,char *pass)
{
    StudentNode *p = ps->top ;
    for (int i = 0 ; i < ps->numberOfStudents;i++ )
    {
        const char *input = pass ;
        const char *saved = p->password ;
        if (*pid == p->id && !(strcmp(saved,input)))
        {
         return 1 ;
        }
        p = p ->next ;
    } 
    return 0; 
}
