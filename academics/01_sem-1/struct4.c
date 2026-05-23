//Creating a structure//
#include<stdio.h>
int main()
{
//This is format of structure that i have created//
//<----------------------->//
struct strawhats{
  char mem[40];
};
//<-------Reference One piece------------>//
struct attack{
    char a1[60];
};


    //<---------------characters------------------>//
 struct strawhats m1[10];
 struct sttack po[10];
 for(int i=0;i<11;i++)
 {
  printf("Enter strawhat members name\n");
  scanf("%s",&m1[i].mem);
  //<------------------attacks---------------------->//

  printf("Enter ther crossponding attack name\n");
  scanf("%s",&at[i].al);
 }
 //[--------------output-----------]//
 printf("Strawhats and their respective attack\n");
 for(int j=0;j<11;j++)
 {
  printf("Member Name:%s\n",m[j].mem);
  printf("Attack name:%s\n",at[j].a1);

 }
 printf("Data finished\n");
return 0;
}
