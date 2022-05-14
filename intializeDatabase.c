#include <stdio.h>
int main(){
    FILE * pd =fopen("./STUDENTLIST.txt","wb");
    fprintf(pd,"00000000ma%c\n",0);
    // fprintf(pd,"id: 00000001, age: 021, gender: 1, total grade: 100, password: magicpassword%c, name: Mohamed saed%c\n",0,0);
    // fprintf(pd,"id: 00000002, age: 020, gender: 0, total grade: 000, password: magicpass%c, name: asem ashraf%c\n",0,0);
    // fprintf(pd,"id: 00000003, age: 022, gender: 0, total grade: 190, password: magicpass%c, name: alaa mohsen%c\n",0,0);
    // fprintf(pd,"id: 00000004, age: 023, gender: 0, total grade: 180, password: magicpassword%c, name: Mariam awad%c\n",0,0);
    // fprintf(pd,"id: 00000005, age: 024, gender: 1, total grade: 110, password: magicpass%c, name: kareem atef%c\n",0,0);
    // fprintf(pd,"id: 00000006, age: 025, gender: 0, total grade: 030, password: magicpass%c, name: ahmed rezk%c\n",0,0);
    // fprintf(pd,"id: 00000007, age: 026, gender: 1, total grade: 001, password: magicpass%c, name: yasmeen%c\n",0,0);
    fclose(pd);
}