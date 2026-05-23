/*Implement a program to print nuumber of ways a given word can be scrambled*/
#include<stdio.h>
#include<string.h>

// Creating a factorial function

int factorial(int n)
{
    if(n==0||n==1)
        return 1;
    else
        return n*factorial(n-1);
}

// Main logic

int main()
{ 
    char str[20];
    int len, ways;
    printf("Enter a word: ");
    scanf("%s",str);
    len=strlen(str);
    ways=factorial(len);
    printf("Number of ways the word can be scrambled: %d\n",ways);
    return 0;
}

