#include <stdio.h>
#include "./admin/admin.h"
#include "./user/user.h"
#include "./methods/methods.h"
#define TRIES_ADMIN 3
#define TRIES_USER 3


int main ()
{
  // the full students list
  Student s;
  // the default admin password
  char adminPassword [20] = "magicpassword"; 
  int id ;
  CreateStudentList(&s);
  int mode = Mode();  // asks the program user to choose a mode from either admin mode or user mode
  if (mode==1)
  {
    if( UserLogin(TRIES_USER,&id,&s)==1) // gives the user 3 tries to enter a correct ID and password
        {
          DisplayUserOptions(&s,&id); // displays the option of the user mode
        }
    else // if the user fails to enter a correct ID and password before 3 tries the program will terminate
        return 0;
  }
  else
  {
      if( AdminLogin(TRIES_ADMIN,adminPassword)==1) // gives the user 3 tries to enter the correct admin password
          {
            DisplayAdminOptions(&s,adminPassword); // displays the options of the admin mode
          }
      else  // if the user fails to enter the correct admin password before 3 tries the program will terminate
          return 0; 
  }
}
