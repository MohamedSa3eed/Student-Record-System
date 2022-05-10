
#include "../admin/admin.h"
#include "../user/user.h"
#ifndef METHODS_H
#define METHODS_H

int  Mode();
int  AdminLogin(int tries_);
int  UserLogin(int tries_);
void DisplayUserOptions();
void DisplayAdminOptions();
void CreateStudentList (Student *);
#endif
