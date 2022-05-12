#include "methods.h"
#include "../admin/admin.h"
#include "../user/user.h"
#include"stdio.h"
#include <string.h>
int Mode()
{
    while (1)
    {
        printf("Welcome to SCS \n
                --------------------------------------\n
                Enter 0 for admin mode \n
                Enter 1 for user mode \n"
              );
        int x ;
        scanf("%d",&x);
        if(x == 0 || x== 1)
        {
            return x ;

        } else printf("please enter a valid number\n");

    }
}
int AdminLogin(int tries_)
{
    int tries = tries_;

    while(1)
    {
        const char *correct_admin_password = "magicpassword"; //temp save
        char admin_password[20];
        printf("Enter admin password: ");
        scanf("%s",entered_admin_password);

        int compare_password = strcmp(correct_admin_password,entered_admin_password);

        if( compare_password == 0)
            break ;
        else
        {
            printf("Invalid password.\n
                    Try again.");
            tries-- ;
        }

        if (!tries)
        {
            printf("\nyou ran out of tries. Login failed.");
            return 0 ;
        }
    }
    return 1;
}



int UserLogin(int tries_)
{
    int tries = tries_;
    while(1)
    {

        const char *saved_user_ID = "123"; //temp save
        const char *saved_user_password = "magicpassword"; //temp save
        char ID[20] ;
        char user_password[20];
        printf("Enter you ID\n");
        scanf("%s",ID);
        printf("Enter your password\n");
        scanf("%s",user_password);

        int compare_ID = strcmp(saved_user_ID,saved_user_ID);
        int compare_password = strcmp(saved_user_password,user_password);

        if( compare_password == 0 && compare_ID == 0)
            break ;
        else
        {
            printf("The ID or the password is incorrect\n");
            tries-- ;
        }
        if (!tries)
        {
            printf("You ran out of tries. Login failed.");
            return 0 ;
        }
            }



    return 1;
        }


void DisplayAdminOptions()
{
    while (1)
    {
        int choice = 0;
        int flag = 0;
        printf("\npress 0 to go back\n
                 1 to add student record\n
                 2 Remove student record\n
                 3 view student record\n
                 4 view all records\n
                 5 Edit admin password\n
                 6 edit student grade\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                flag =1 ;
                break;
            case 1:
                printf("stuff\n"); //waiting for admin methods to be implemented
                break;
            case 2:
                printf("stuff\n"); //waiting for admin methods to be implemented
                break;
            case 3:
                printf("stuff\n"); //waiting for admin methods to be implemented
                break;
            case 4:
                printf("stuff\n"); //waiting for admin methods to be implemented
                break;
            case 5:
                printf("stuff\n"); //waiting for admin methods to be implemented
                break;
            case 6:
                printf("stuff\n"); //waiting for admin methods to be implemented
                break;
            default:
                printf("Please enter a valid number\n");

                break;
        }
        if (flag == 1 )
        {
            break;
        }

    }
}

void DisplayUserOptions()
{

    while (1)
    {
        int choice = 0;
        int flag = 0;
        printf("\npress 0 to go back\n 1 to view your record \n 2 Edit your password \n 3 Edit your name\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 0:
                flag =1;
                break;
            case 1:
                printf("stuff\n"); //waiting for user methods to be implemented
                break;
            case 2:
                printf("stuff\n"); //waiting for user methods to be implemented
                break;
            case 3:
                printf("stuff\n"); //waiting for user methods to be implemented
                break;
            default:
                printf("Please enter a valid number\n");


        }
        if (flag ==1)
        {
            break;
        }

    }
}

void CreateStudentList (Student *ps)
{
   ps->top=NULL ;
}
