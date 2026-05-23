/*Write a Program to insert an new element at given location in array.*/

#include<stdio.h>
int main()
{
    // Intialising an array
    int puru[]={1,2,3,4,5,6,7,8,9,10,11};
    int n = sizeof(puru)/sizeof(puru[0]);

// Inserting value between array

    for(int i=n; i>=0;i--)
    {
      puru[i]=puru[i-1];
      if(puru[i]==puru[2])
    {
        puru[2]=66;
        break;
    }
    }
    printf("Updated value\n");
    // Printing value of array
    for(int j=0;j<n+1;j++)
    {
     printf("Updated arrays element are: %d\n",puru[j]);
    }
    return 0;
}
