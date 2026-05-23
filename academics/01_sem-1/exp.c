// Create a function too find square.
#include <stdio.h>
float square(float);
int main()
{
    float a, b;
    printf("Enter any number: ");
    scanf("%f", &a);
    b = square(a);
    printf("square of number is %f", b);
}
float square(float x)
{
    float y;
    y = x * x;
    return (y);
}
