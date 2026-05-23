#include <stdio.h>

void lent(char arr[]) 
{
    int count = 0, i = 0;

    while (arr[i] != '\0') 
    {
        count++;
        i++;
    }

    printf("The length of the string is %d\n", count);
}

int main() {
    char arr[100]; 

    printf("Enter a string:\n");
    scanf("%s", arr);

    lent(arr);

    return 0;
}
