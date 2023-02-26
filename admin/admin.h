#include <stdio.h>
#include "../user/user.h"
#ifndef ADMIN_H
#define ADMIN_H

void AddStudentRecord     (Student *,int);
void RemoveStudentRecord  (Student *);
void ViewStudentRecord    (StudentNode *);
void ViewAllRecords       (Student *);
void EditAdminPassword    (char*);
void EditStudentGrade     (StudentNode *);

#endif
