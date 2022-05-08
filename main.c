#include <stdio.h>
#include "./admin/admin.h"
#include "./user/user.h"
int main ()
{
  int mode ;
  mode = Mode();
  if (mode)
  { 
    UserLogin();
    DisplayUserOptions();
  }
  else
  { 
    AdminLogin();
    DisplayAdminOptions();
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