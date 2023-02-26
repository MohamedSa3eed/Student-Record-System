#include <stdio.h>
#include "user.h"

#include "../admin/admin.h"

void ViewRecord(StudentNode * p) {
    ViewStudentRecord(p);
}
void EditPassword (StudentNode* p) {
    printf("enter the new password for ID %d:\n",p->id);
    scanf("%s",p->password);
}

void EditName(StudentNode* p) {
    printf("enter new name: \n");
    scanf("%s",p->name);

}
