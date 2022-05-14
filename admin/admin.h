#include <stdio.h>
#include "../user/user.h"
#ifndef ADMIN_H
#define ADMIN_H

//int adminPassword ;
void AddStudentRecord (Student *,int) ; //done
void RemoveStudentRecord (Student *) ; //done
void ViewStudentRecord (StudentNode *) ; //done
void ViewAllRecords (Student *) ; //done
void EditAdminPassword (char*) ; //done
void EditStudentGrade (StudentNode *) ; //done 

#endif