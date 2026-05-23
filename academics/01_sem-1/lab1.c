#include<stdio.h>
int main()
{
    int x;
    int c =0; 
    printf("Initial value is : ");
    scanf("%d",&x);
    if(x<0){
        printf("ERROR");
        return 0;
        }
    while(x!=1)
     {
        if(x%2==0){
            x = x/2;
            c++;
            printf("\nNext value is : %d",x);
        }
        else{
            x = 3*x+1;
            c++;
            printf("\nNext value is : %d",x);
        }
    }
  

printf("\n\nNumber of steps : %d",c);
printf("\nFinal value : %d",x);
}
