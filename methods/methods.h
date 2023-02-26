#include "../admin/admin.h"
#include "../user/user.h"
#ifndef METHODS_H
#define METHODS_H

StudentNode*  studentFound        (Student *,int *,int*);
int           AsInt               (char*,int ,int);
void          appendNode          (Student *,StudentNode*);
void          intiatlist          (Student*,char*,char*);
int           storeList           (Student*,char*,char*);
int           askID               ();
int           Mode                (Student*,char*);
int           AdminLogin          (int ,char *);
int           UserLogin           (int , int*,Student *);
void          DisplayUserOptions  (Student*,int*,char*);
void          DisplayAdminOptions (Student*,char *);
void          CreateStudentList   (Student *);
int           user_found          (Student *,int *,char *);
#endif
