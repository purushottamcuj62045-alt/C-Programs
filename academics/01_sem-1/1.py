//creating a function to find factorial.
#include<stdio.h>
int fact(int);
int main()
{
    int shr,puppy;
    printf("Enter the number whose factorial you want: ");
    scanf("%d",&puppy);
    shr= fact(puppy);
    printf("Factorial of number is:%d",shr);

}
int fact(int x)
{
int i,flupp=1;
for (i=1;i<=x;i++)
   flupp=flupp*i;
   return  (flupp);
}
