/*Write a program to find sum of array elements.*/

#include<stdio.h>
int main()
{
    int i=0 ;
    int sum=0;
    int puru[10]= { 1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<11;i++)
    {
    sum = sum + puru[i];
    }
    printf("Sum of elements of array: %d",sum);
}