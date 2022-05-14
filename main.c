#include <stdio.h>
#include <string.h>
#include <math.h>
#include "./admin/admin.h"
#include "./user/user.h"
#include "./methods/methods.h"
#define TRIES_ADMIN 3
#define TRIES_USER 3
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

void appendNode(Student *s,StudentNode *stud){////////////// BUGGY FIX THIS GUYS<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  /* input : takes in a pointer to list of student and a pointer to a node
   *         append the node to the list like in normal list operation
  */
  if (s->numberOfStudents>=1)
  {
      (s->end)->next=stud;
  }
  else if (s->numberOfStudents==0)
  {
      s->top=stud;
  }
  s->end=stud;
  s->numberOfStudents++;
  //ViewRecord(stud);
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
    for (int i =0 ;!feof(pdatabase);i++)
    {
      if (i==0)
      {
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
    for (int i = 0; i < s->numberOfStudents; i++)
    {
      fprintf(pdatabase,"id: %8.8d, age: %3.3d, gender: %1.1d, total grade: %3.3d, password: %s%c, name: %s%c\n",asem->id,asem->age,(strcmp(asem->gender,"male")?0:1),asem->score,asem->password,0,asem->name,0);
      asem=asem->next;
    }
    fclose(pdatabase);
    return 0;
}

int main ()
{
  // the full students list
  Student s={0,NULL,NULL,0};
  char adminPassword [50];
  intiatlist(&s,FILE_LOCATION,adminPassword);
  //ViewAllRecords(&s);
  // the default admin password
  printf("%s\n",adminPassword);
   
  int id ;
  while(1){
      int mode = Mode();  // asks the program user to choose a mode from either admin mode or user mode
      if (mode==1)
      {
        if( UserLogin(TRIES_USER,&id,&s)==1) // gives the user 3 tries to enter a correct ID and password
            {
              DisplayUserOptions(&s,&id); // displays the option of the user mode
            }
      }
      else
      {
          if( AdminLogin(TRIES_ADMIN,adminPassword)==1) // gives the user 3 tries to enter the correct admin password
              {
                DisplayAdminOptions(&s,adminPassword); // displays the options of the admin mode
              }
      }
  storeList(&s,FILE_LOCATION,adminPassword);
  }
  return 0;
}
