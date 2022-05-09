#include <stdio.h>
#include "./admin/admin.h"
#include "./user/user.h"
#include "./methods/methods.h"
int main ()
{

     int mode = Mode();
    if (mode)
    {
        UserLogin();
        DisplayUserOptions();
        if( UserLogin())
        {
            DisplayUserOptions();
        }
        else return 0;

    }
    else
    {
        AdminLogin();
        DisplayAdminOptions();
        if( AdminLogin())
        {

            DisplayAdminOptions();
        }
        else return 0;

    }


  }