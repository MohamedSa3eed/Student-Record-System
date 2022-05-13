#include <stdio.h>
#include "../user/user.h"
#ifndef ADMIN_H
#define ADMIN_H

//int adminPassword ;

void AddStudentRecord (Student *) ; //done
void RemoveStudentRecord (Student *) ; //done
void ViewStudentRecord (Student *) ; //done
void ViewAllRecords (Student *) ; //done
void EditAdminPassword (char*) ; //done
void EditStudentGrade (Student *) ; //done 

#endif