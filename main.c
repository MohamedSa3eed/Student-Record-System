#include <stdio.h>
#include "./admin/admin.h"
#include "./user/user.h"
#include "./methods/methods.h"
int main ()
{

while (1)
{
    int mode = Mode();
    if (mode)
    {
//        UserLogin();
//        DisplayUserOptions();
        if( UserLogin()) //returns 0 to terminate if user fails to log in too many times
            {
            DisplayUserOptions();
            }
        else return 0;

    }
    else
    {
//        AdminLogin();
//        DisplayAdminOptions();
        if( AdminLogin()) //returns 0 to terminate if admin fails to log in too many times
            {

            DisplayAdminOptions();
            }
        else return 0;

    }
}




  /*
  ask user for user_name and password (3 tries) see help function :
  */

  /*
   int tries =3 ;
   whiel(1)
   {
       if(Login())
         break ;
       else
         tries-- ;
      if (!tries)
      {
        printf("you ran out of tries");
        return 0 ;
      } 
   }
   */
    return 0;
}
