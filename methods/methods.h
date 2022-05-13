
#include "../admin/admin.h"
#include "../user/user.h"
#ifndef METHODS_H
#define METHODS_H

int  Mode();
int  AdminLogin(int tries_,char *);
int  UserLogin(int tries_);
void DisplayUserOptions(Student*);
void DisplayAdminOptions(Student*,char *);
void CreateStudentList (Student *);
#endif
