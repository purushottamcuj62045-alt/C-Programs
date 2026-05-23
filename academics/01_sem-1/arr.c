#include <stdio.h>
int main()
{
    int arr[5], i, sum = 0;
    printf("Enter any 5 number");
    for (i = 1; i <= 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i <= 5; i++)
    {
        sum = sum + arr[i];
    }
    printf("Sum of value of array %d\n", sum);
    return 0;
}
