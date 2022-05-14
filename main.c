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


int AsInt(char buff[],int start,int size){
    int res=0;
    for (int i = start; i <start+size ; i++) {
        res+=(buff[i]-'0')*pow(10,size-(i-start)-1);
    }
    return res;
}

void appendNode(Student* s,StudentNode *stud){
  if (s->numberOfStudents>=1)
  {
      s->end->next=stud;
      s->end=stud;
      s->numberOfStudents++;
      s->end->next=NULL;
  }
  else if (s->numberOfStudents==0)
  {
      s->top=stud;
      s->end=stud;
      s->numberOfStudents++;
      s->end->next=NULL;
  }
}
void intiatlist(Student* s ,char* fileLocation ){
    FILE* pdatabase = fopen(fileLocation,"r");
    while (feof(pdatabase)==1)
    {
      StudentNode stud;
      char buff[MAX_LINE_SIZE];
      fgets(buff,MAX_LINE_SIZE,pdatabase);
      stud.id=AsInt(buff,4,8);
      stud.age= AsInt(buff,19,3);
      stud.gender= AsInt(buff,32,1)? "male": "female";
      stud.score= AsInt(buff,48,3);
      stud.password= &buff[63];
      stud.passSize=strlen(stud.password);
      stud.name= &buff[63+stud.passSize+9];
      appendNode(s,&stud);
    }
    fclose(pdatabase);
    
}
int storeList(Student *s , char* fileLocation){
    FILE *pdatabase;
    pdatabase = fopen(fileLocation,"wb");
    fprintf(pdatabase,"");
    fclose(pdatabase);
    pdatabase = fopen(fileLocation,"ab");
    StudentNode *asem = s->top;
    for (int i = 0; i < s->numberOfStudents; i++)
    {
      fprintf(pdatabase,"id: %.8d, age: %.3d, gender: %.1d, total grade: %.3d, password: %s%c, name: %s%c\n",asem->id,asem->age,(strcmp(asem->gender,"male")?0:1),asem->score,asem->password,0,asem->name,0);
      asem=asem->next;
    }
    fclose(pdatabase);
    return 0;
}

int main ()
{
  // the full students list
  Student s;
  CreateStudentList(&s);
  intiatlist(&s,FILE_LOCATION);
  // the default admin password
  char adminPassword [20] = "magicpassword"; 
  int id ;
  CreateStudentList(&s);
  int mode = Mode();  // asks the program user to choose a mode from either admin mode or user mode
  if (mode==1)
  {
    if( UserLogin(TRIES_USER,&id,&s)==1) // gives the user 3 tries to enter a correct ID and password
        {
          DisplayUserOptions(&s,&id); // displays the option of the user mode
        }
    else // if the user fails to enter a correct ID and password before 3 tries the program will terminate
        {}
  }
  else
  {
      if( AdminLogin(TRIES_ADMIN,adminPassword)==1) // gives the user 3 tries to enter the correct admin password
          {
            DisplayAdminOptions(&s,adminPassword); // displays the options of the admin mode
          }
      else  // if the user fails to enter the correct admin password before 3 tries the program will terminate
          {}
  }

  return storeList(&s,FILE_LOCATION);
}
