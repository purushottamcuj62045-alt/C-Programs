#include<stdio.h>
int main()
{
    int num[5];
    int i;
    for(i=0;i<5;i++)
    {
        printf("\nEnter a number:-");
        scanf("%d",&num[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("arrays are %d\n",num[i]);
    }
    return 0;
}