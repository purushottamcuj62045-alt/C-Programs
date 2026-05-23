//sum of diagonal element in an array
#include<stdio.h>
int main()
{
    int arr[3][3], i, j, row, col, sum = 0;;
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == j)
            {
                sum = sum + arr[i][j];
                printf("Sum of diagonal elements is %d\n", sum);
            }
        }
    }
}
/*//sum of diagonal element in an array
#include<stdio.h>
int main()
{
    int arr[3][3],i,j,sum;
    printf("enter any 9 number\n");
    for(i=0;i<=3;i++)
    {
        for(j=0;j<4;j++)
        scanf("%d",&arr[i][j]);
        if (i==j)
        {
         sum=sum+arr[i][j];
        }
    }
    printf("Sum of arr : %d\n",sum);
    
}*/