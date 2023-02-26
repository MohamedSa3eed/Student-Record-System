#include <stdio.h>
#include <string.h>
#include <math.h>
#include "methods.h"
#include "../admin/admin.h"
#include "../user/user.h"

#define FILE_LOCATION_IN_STRING_FORMAT  "./STUDENTLIST"
#define FILE_LOCATION FILE_LOCATION_IN_STRING_FORMAT
#define MAX_LINE_SIZE 250


int AsInt(char buff[],int start,int size){ // formating function
    int res=0;
    for (int i = start; i <start+size ; i++) {
        res+=(buff[i]-'0')*pow(10,size-(i-start)-1);
    }
    return res;
}

void appendNode(Student *s,StudentNode *stud){
    /* input : takes in a pointer to list of student and a pointer to a node
   *         append the node to the list like in normal list operation
   */
    if (s->numberOfStudents>=1) {
        (s->end)->next=stud;
    }
    else if (s->numberOfStudents==0) {
        s->top=stud;
    }
    s->end=stud;
    s->numberOfStudents++;
}
void intiatlist(Student* s ,char* fileLocation ,char* password){
    /*  Input : takes in a student list and a location of a file(in the form of a string)
   *          opens the file and takes a line by line and format it into a student node
   *
   *  the file is arranged in a special format where the information of each student is on one line
   *  and the first line in the file is an ID that has not been used before
   *  the code takes the first line and puts it in the list variable nextID
   *  As in the recommended next ID
   */
    FILE* pdatabase = fopen(fileLocation,"r");
    char buff[MAX_LINE_SIZE];
    fgets(buff,MAX_LINE_SIZE,pdatabase);
    for (int i =0 ;!feof(pdatabase);i++) {
        if (i==0) {
            s->nextID=AsInt(buff,0,8);                // code to handle the first line of the file
            strcpy(password,&buff[8]);
            fgets(buff,MAX_LINE_SIZE,pdatabase);      // code to handle the first line of the file
            continue;
        }
        StudentNode *stud=(StudentNode*)malloc(sizeof(StudentNode));
        stud->id=AsInt(buff,4,8);                          // code to foramt the info from file
        stud->age= AsInt(buff,19,3);                       // code to foramt the info from file
        if (AsInt(buff,32,1))strcpy(stud->gender,"male");
        else strcpy(stud->gender,"female");
        stud->score= AsInt(buff,48,3);                     // code to foramt the info from file
        strcpy(stud->password,&buff[63]);
        stud->passSize=strlen(stud->password);              // code to foramt the info from file
        strcpy(stud->name,&buff[63+stud->passSize+9]);
        stud->next=NULL;
        appendNode(s,stud);                              // code to foramt the info from file
        fgets(buff,MAX_LINE_SIZE,pdatabase);              // code to foramt the info from file
    }
    fclose(pdatabase);
    printf("List intialized.\n------------------\n");
}
int storeList(Student *s , char* fileLocation,char* password){
    /*
     * Input : student list and a file location
     * the function resets the content of the file by writing the first line as the recommended next ID
     * the reopens the file in append binary mode. the nodes are then added one by one into the folder 
     * with the specific format
     */
    FILE *pdatabase;
    pdatabase = fopen(fileLocation,"w");
    fprintf(pdatabase,"%8.8d%s%c\n",s->nextID,password,0);
    fclose(pdatabase);
    pdatabase = fopen(fileLocation,"a");
    StudentNode *asem = s->top;
    for (int i = 0; i < s->numberOfStudents; i++) {
        fprintf(pdatabase,"id: %8.8d, age: %3.3d, gender: %1.1d, total grade: %3.3d, password: %s%c, name: %s%c\n",asem->id,asem->age,(strcmp(asem->gender,"male")?0:1),asem->score,asem->password,0,asem->name,0);
        asem=asem->next;
    }
    fclose(pdatabase);
    printf("List file updated.\n-----------------------\n");
    return 0;
}



////////////////////////////////////////////////////
StudentNode* studentFound(Student *ps,int *pid,int* pfoundcheck)
{
    /* input : a pointer to the student ID entered by the user to search for its existence in the student list
     *         a pointer to the student list that contains all the students
     * output: returns the student node and checks pfoundcheck if match found
     *              or the end node and unchecks pfoundcheck if student does not exist
    */

    StudentNode *p = ps->top ;  // a student node pointing to the head of the list
    for (int i = 0 ; i < ps->numberOfStudents;i++ ){  // iterating over each node to check for match
        //ViewStudentRecord(p);
        if (*pid == p->id){ // if the entered ID matches a saved ID and also the passwords match
            *pfoundcheck = 1;
            return p ;
        }
        else p = p ->next ; // check the next student in the list
    }
    *pfoundcheck=0;
    return p; // if match was not found in the list return 0
}
int askID(){
    int id;
    char* tmp;
    printf("  Enter student ID:");
    scanf("%d",&id);
    return id;
}
void AddStudentRecordV2(Student*s){
    printf("note: ID %d has not been used before.\n",s->nextID);
    int id =askID();
    StudentNode* pstudent;
    int foundcheck=0;
    if (id < s->nextID) {
        pstudent = studentFound(s,&id,&foundcheck); // if the id already exists
        if (foundcheck) {
            printf("ID exist. Try again with a new ID.\n-------------\n");
        }
        else{
            AddStudentRecord(s,id);
        }
    }
    else{
        s->nextID=id+1;
        AddStudentRecord(s,id);
    }
}
int Mode(Student*s,char*password) {
    /* return the program mode 
     * 1 for user mode
     * 0 for admin mode
    */
    while (1) {
        printf("-----------------\nWelcome to S.R.S. \n-----------------\nAdmin mode : 0.\nUser mode  : 1.\nExit : 2.\n");
        int mode ;
        printf("Mode: ");
        scanf("%d",&mode);
        if(mode == 0 || mode== 1) {
            printf("-----------------\n");
            return mode ;
        }
        else if (mode==2) {
            storeList(s,FILE_LOCATION,password);
            exit(0);    
        }
        else printf("Enter a valid number(0 / 1 / 2).\n");
    }
}
int AdminLogin(int tries_,char * password) {
    /* input : the number of tries allowed before the program terminates
     *         the default password of the admin mode
     * output: returns 1 for successful login
     *              or 0 for failed login
    */
    int tries = tries_;
    while(1) {
        const char *saved_admin_password = password; // "magicpassword" is the default password
        char admin_password[20];
        printf("Enter Admin password\n");
        scanf("%s",admin_password);
        int compare_password = strcmp(saved_admin_password,admin_password);
        if( compare_password==0) {   // if the entered password and the correct admin password match
            printf("Admin login successful.\n-----------------\n");
            return 1;  // return 1
        }           
        else {
            printf("Wrong Admin password.\n\n");  // print a password wrong statment
            tries-- ;                           // reduce the remaining tries
        }
        if (tries==0) { // if the user ran out of tries         
            printf("\nyou ran out of tries\n");  
            return 0 ; // program terminates
        }
    }
}


int UserLogin(int tries_,int* pid,Student *s) {
    /* input : the number of tries allowed before the program terminates
     *         a pointer to the student ID to be entered
     *         a pointer to the student list that contains all the students
     * output: returns 1 for successful login
     *              or 0 for failed login
    */
    int tries = tries_;  // number of tries of the user login
    while(tries--) {
        if (s->numberOfStudents==0) {
            printf("The list is empty. Add students in admin mode.\n");
            break;
        }
        char *user_password;
        printf("Please enter you ID\n");
        scanf("%d",pid);
        printf("Please enter your password\n");
        scanf("%s",user_password);
        int found = user_found(s,pid,user_password); // search for a matching ID and password
        if(found==1) {
            return 1;
        } 
        else {
            printf("invalid password or id.\n");
        }
    }
    printf("\nyou ran out of tries\n");
    return 0 ;
}
int user_found(Student *ps,int *pid,char *pass) {
    /* input : the password entered by the user to search for its existence in the student list
     *         a pointer to the student ID entered by the user to search for its existence in the student list
     *         a pointer to the student list that contains all the students
     * output: returns 1 if match found
     *              or 0 if student does not exist
    */
    StudentNode *p = ps->top ;  // a student node pointing to the head of the list
    for (int i = 0 ; i < ps->numberOfStudents;i++ ){ // iterating over each node to check for match
        const char *input = pass ; 
        const char *saved = p->password ;
        if (*pid == p->id && !(strcmp(saved,input))){ // if the entered ID matches a saved ID and also the passwords match
            return 1 ;
        }
        else p = p ->next ; // check the next student in the list
    } 
    return 0; // if match was not found in the list return 0
}
void DisplayAdminOptions(Student*s,char* password) {
    while (1) {
        int choice = 0; // admin option choice
        int flag = 0;  // admin logout flag
        int id;
        int foundcheck;
        StudentNode * pstudent;
        printf("0 to logout\n 1 to add student record \n 2 Remove student record \n 3 view student record \n 4 view all records \n 5 Edit admin password \n 6 edit student grade\n7 Exit program.\n");
        printf("Command no. : ");
        scanf("%d",&choice);
        printf("-----------------\n");
        switch (choice) {
            case 0:
                flag =1; 
                break;
            case 1: // on adding a student, the id is required to check for duplicated before adding
                AddStudentRecordV2(s);
                //AddStudentRecord(id);
                storeList(s,FILE_LOCATION,password);
                break;
            case 2:
                RemoveStudentRecord(s);
                storeList(s,FILE_LOCATION,password);
                break;
            case 3:
                id = askID();
                foundcheck=0;
                pstudent = studentFound(s,&id,&foundcheck);
                if (foundcheck) {
                    ViewStudentRecord(pstudent);
                }
                else{
                    printf("Student not found.\n----------------\n");
                }
                break;
            case 4:
                ViewAllRecords(s);
                break;
            case 5:
                EditAdminPassword(password);
                storeList(s,FILE_LOCATION,password);
                break;
            case 6:
                id = askID();
                foundcheck=0;
                pstudent = studentFound(s,&id,&foundcheck);
                if (foundcheck) {
                    EditStudentGrade(pstudent);
                    storeList(s,FILE_LOCATION,password);
                }
                else{
                    printf("Student not found.\n----------------\n");
                }
                break;
            case 7:
                storeList(s,FILE_LOCATION,password);
                exit(0);
                break;
            default:
                printf("Invalid number. Enter 0 to exit admin mode.\n");
                break;
        }
        if (flag == 1 ) break;
    }
}

void DisplayUserOptions(Student*s,int* pid,char* password) {
    while (1) {
        int choice = 0; // user mode option choice
        int flag = 0;   // user mode logout flag
        int id;
        int foundcheck;
        StudentNode * pstudent;
        printf("\npress 0 to logout\n 1 to view your record \n 2 Edit your password \n 3 Edit your name\n4 Exit program.\n");
        scanf("%d",&choice);
        switch (choice) {
            case 0:
                flag =1;
                break;
            case 1:
                id = *pid;
                foundcheck=0;
                pstudent = studentFound(s,&id,&foundcheck);
                if (foundcheck) {
                    ViewRecord(pstudent);
                }
                else{
                    printf("Student not found.\n----------------\n");
                }
                break;
            case 2:
                id = *pid;
                foundcheck=0;
                pstudent = studentFound(s,&id,&foundcheck);
                if (foundcheck) {
                    EditPassword(pstudent);
                    storeList(s,FILE_LOCATION,password);
                }
                else{
                    printf("Student not found.\n----------------\n");
                }
                break;
            case 3:
                id = *pid;
                foundcheck=0;
                pstudent = studentFound(s,&id,&foundcheck);
                if (foundcheck) {
                    EditName(pstudent);
                    storeList(s,FILE_LOCATION,password);
                }
                else{
                    printf("Student not found.\n----------------\n");
                }
                break;
            case 4:
                storeList(s,FILE_LOCATION,password);
                exit(0);
                break;
            default:
                printf("Please enter a valid number\n");
        }
        if (flag ==1) break;
    }
}

void CreateStudentList (Student *ps) {
    ps->top=NULL ;
    ps->end=NULL ;
    ps->numberOfStudents =0 ;
}
