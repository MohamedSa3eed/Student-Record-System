#include "methods.h"
#include "../admin/admin.h"
#include "../user/user.h"
#include"stdio.h"
int Mode()
{
  printf("Welcome to SCS \n \
--------------------------------------\n \
0 for admin mode \n \
1 for user mode \n");
int x ;
scanf("%d",&x);
return x ;
}
int AdminLogin()
{
    int tries = 5;

    while(1)
    {
        const char *saved_admin_password = "magicpassword"; //temp save
        char admin_password[20];
        printf("\nPlease enter your password\n");
        scanf("%s",admin_password);

        int compare_password = strcmp(saved_admin_password,admin_password);

        if( compare_password == 0)
            break ;
        else
        {
            printf("The password is wrong\n");
            tries-- ;
        }

        if (!tries)
        {
            printf("\nyou ran out of tries");
            return 0 ;
        }
    }
    return 1;
}

int  UserLogin()
{
    int tries = 5;
    while(1)
    {


        const char *saved_user_ID = "123"; //temp save
        const char *saved_user_password = "magicpassword"; //temp save
        char ID[20] ;
        char user_password[20];
        printf("\nPlease enter you ID\n");
        scanf("%s",ID);
        printf("Please enter your password\n");
        scanf("%s",user_password);

        int compare_ID = strcmp(saved_user_ID,saved_user_ID);
        int compare_password = strcmp(saved_user_password,user_password);

        if( compare_password == 0 && compare_ID == 0)
            break ;
        else
        {
            printf("The ID or the password are wrong\n");
            tries-- ;
            }

        if (!tries)
        {
            printf("you ran out of tries");
            return 0 ;
        }
    }
    return 1;
}
void DisplayUserOptions()
{
    printf("stuff");
}

void DisplayAdminOptions()
{
printf("stuff");
}