#include<stdio.h>
#include<string.h>
int main()
{
    char source[]="Folks!";
    char target[50]="heloo";
    strcat(target,source);
    printf("\n Source string=%s",target);
    printf("\nTarget string=%s",source);
    return 0;

}