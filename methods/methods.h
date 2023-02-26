#include "../admin/admin.h"
#include "../user/user.h"
#ifndef METHODS_H
#define METHODS_H

int  Mode();
int  AdminLogin(int ,char *);
int  UserLogin(int , int*,Student *);
void DisplayUserOptions(Student*,int*);
void DisplayAdminOptions(Student*,char *);
void CreateStudentList (Student *);
int user_found(Student *,int *,char *);
#endif
