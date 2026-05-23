#include<stdio.h>
int main()
/*
{
    int i=456;
    int* p=&i;
    printf("%d\n",i);
    printf("%p",p);
    return 0;
}*/
{
int luffy[]={45,48,49,46,66};
int i=0;
for(i=0;i<=4;i++)
{
  /*  printf("%d \n",luffy[i]);*/
  printf("%d\n", *(luffy+ i));
}
printf("%d",sizeof(luffy));
printf("%d",*luffy);
return 0;

}