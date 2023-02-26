#include <stdio.h>
#include "./admin/admin.h"
#include "./user/user.h"
#include "./methods/methods.h"
#define TRIES_ADMIN 3
#define TRIES_USER 3


int main ()
{
    Student s ;
    char adminPassword [20] = "magicpassword";
    int id ;
    CreateStudentList(&s);
    while (1) {
        int mode = Mode();
        if (mode) {
            if( UserLogin(TRIES_USER,&id,&s)){ //returns 0 to terminate if user fails to log in too many times
                DisplayUserOptions(&s,&id);
            }
            else return 0;
        }
        else {
            if( AdminLogin(TRIES_ADMIN,adminPassword)){ //returns 0 to terminate if admin fails to log in too many times
                DisplayAdminOptions(&s,adminPassword);
            }
            else return 0;
        }
    }
    return 0;
}
