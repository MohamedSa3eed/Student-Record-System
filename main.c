#include <stdio.h>
#include <string.h>
#include <math.h>
#include "admin/admin.h"
#include "user/user.h"
#include "methods/methods.h"

#define TRIES_ADMIN 3
#define TRIES_USER 3
#define FILE_LOCATION_IN_STRING_FORMAT  "./STUDENTLIST"
#define FILE_LOCATION FILE_LOCATION_IN_STRING_FORMAT
#define MAX_LINE_SIZE 250

int main () {
  // the full students list
  Student s;
  CreateStudentList(&s);
  char adminPassword [50];
  intiatlist(&s,FILE_LOCATION,adminPassword);
  //ViewAllRecords(&s);
  // the default admin password
  printf("The admin password : %s\n",adminPassword);

  int id ;
  while(1){ int mode = Mode(&s,adminPassword);  // asks the program user to choose a mode from either admin mode or user mode
    // CreateStudentList(&s);
    // intiatlist(&s,FILE_LOCATION,adminPassword);
    if (mode==1) {
      if( UserLogin(TRIES_USER,&id,&s)==1){ // gives the user 3 tries to enter a correct ID and password 
        DisplayUserOptions(&s,&id,adminPassword); // displays the option of the user mode
      }
    }
    else {
      if( AdminLogin(TRIES_ADMIN,adminPassword)==1){ // gives the user 3 tries to enter the correct admin password
        DisplayAdminOptions(&s,adminPassword); // displays the options of the admin mode
      }
    }
  }
  return 0;

}
