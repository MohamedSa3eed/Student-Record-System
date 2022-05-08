#include <stdio.h>
#include "./admin/admin.h"
#include "./user/user.h"
int main ()
{
    int tries =3 ;
   whiel(1)
   {
       if(login())
         break ;
       else
         tries-- ;

      if (!tries)
        return 0 ; 

   }
    return 0;
}