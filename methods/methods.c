#include "methods.h"
#include "../admin/admin.h"
#include "../user/user.h"
#include"stdio.h"
#include <string.h>

int Mode()
{
    /* return the program mode 
     * 1 for user mode
     * 0 for admin mode
    */
    while (1)
    {
        printf("Welcome to S.R.S. \n--------------------------------------\nAdmin mode : 0.\nUser mode : 1.\nExit : Ctrl C.");
        int mode ;
        scanf("%d",&mode);
        if(mode == 0 || mode== 1)
        {
            return mode ;

        } else printf("Enter a valid number(1 / 0).\n");

    }
}
int AdminLogin(int tries_,char * password)
{
    /* input : the number of tries allowed before the program terminates
     *         the default password of the admin mode
     * output: returns 1 for successful login
     *              or 0 for failed login
    */
    int tries = tries_;

    while(1)
    {
        const char *saved_admin_password = password; // "magicpassword" is the default password
        char *admin_password;
        printf("Please enter your password\n");
        scanf("%s",admin_password);

        int compare_password = strcmp(saved_admin_password,admin_password);

        if( compare_password==0) // if the entered password and the correct admin password match 
            return 1;            // return 1
        else                     // otherwise,
        {
            printf("The password is wrong\n");  // print a password wrong statment
            tries-- ;                           // reduce the remaining tries
        }

        if (tries==0)  // if the user ran out of tries         
        {
            printf("\nyou ran out of tries");  
            return 0 ; // program terminates
        }
    }
}


int UserLogin(int tries_,int* pid,Student *s)
{
    /* input : the number of tries allowed before the program terminates
     *         a pointer to the student ID to be entered
     *         a pointer to the student list that contains all the students
     * output: returns 1 for successful login
     *              or 0 for failed login
    */
    int tries = tries_;  // number of tries of the user login
    while(tries--)
    {
        char *user_password;
        printf("Please enter you ID\n");
        scanf("%d",pid);
        printf("Please enter your password\n");
        scanf("%s",user_password);
        int found = user_found(s,pid,user_password); // search for a matching ID and password
        if(found==1)
        {
            return 1;
        } else
        {
            printf("invalid password or id.\n");
        }
        if (tries==0)
        {
            printf("\nyou ran out of tries");
            return 0 ;
        }
    }
}
int user_found(Student *ps,int *pid,char *pass)
{
    /* input : the password entered by the user to search for its existence in the student list
     *         a pointer to the student ID entered by the user to search for its existence in the student list
     *         a pointer to the student list that contains all the students
     * output: returns 1 if match found
     *              or 0 if student does not exist
    */
    StudentNode *p = ps->top ;  // a student node pointing to the head of the list
    for (int i = 0 ; i < ps->numberOfStudents;i++ )  // iterating over each node to check for match
    {
        const char *input = pass ; 
        const char *saved = p->password ;
        if (*pid == p->id && !(strcmp(saved,input))) // if the entered ID matches a saved ID and also the passwords match
        {
            return 1 ;
        }else
            p = p ->next ; // check the next student in the list
    } 
    return 0; // if match was not found in the list return 0
}
void DisplayAdminOptions(Student*s,char* password)
{
    while (1)
    {
        int choice = 0; // admin option choice
        int flag = 0;  // admin logout flag
        printf("\npress 0 to logout\n 1 to add student record \n 2 Remove student record \n 3 view student record \n 4 view all records \n 5 Edit admin password \n 6 edit student grade \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                flag =1; 
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
                printf("Invalid number. Enter 0 to exit admin mode\n");
                break;
        }
        if (flag == 1 )
        {
            break;
        }

    }
}

void DisplayUserOptions(Student*s,int* pid)
{
    while (1)
    {
        int choice = 0; // user mode option choice
        int flag = 0;   // user mode logout flag
        
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

        if (flag ==1) break;
    }
}

void CreateStudentList (Student *ps)
{
   ps->top=NULL ;
   ps->end=NULL ;
   ps->numberOfStudents =0 ;
}
