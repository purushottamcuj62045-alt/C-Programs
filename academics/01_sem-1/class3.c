#include<stdio.h>
#include<string.h>
int main()
{
    char string[50]="Luffy",string2[69]="Zoro";
    int i,j,k;
    i=strcmp(string,string2);
    j=strcmp(string,"killer");
    k=strcmp(string,"Luffy");
    printf("%d %d %d",i,j,k);
    return 0;
}