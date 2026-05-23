/* Write a program to calculate the maximum subarray sum i.e, 
the largest possible sum of sequence of consect values of an array*/
#include<stdio.h>
int main()
{
int luffy[10]={-3,-6,-7,8,-13,-9};
// storing maximum values
    int max_far=luffy[0];
    int curr_max=luffy[0];
    int i;
// initiating a for loop for maximum sum
    for(i=1;i<10;i++)
    {
        curr_max=curr_max+luffy[i];
        if(luffy[i]>curr_max)
        {
            curr_max=luffy[i];
        }
        if(max_far<curr_max)
        {
            max_far=curr_max;
        }
    }
    printf("Maximum subarray sum is: %d",max_far);
    return 0;
  
}

