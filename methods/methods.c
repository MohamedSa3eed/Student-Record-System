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
