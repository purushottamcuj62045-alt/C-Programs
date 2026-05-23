#include <stdio.h>
int main()
{
int a, b, gcd, i, Lcm ;
printf(" enter a , b\n");
scanf(" %d %d", &a, &b);
for (i = 1; i <= a && i <= b; i++)
{
if (a % i == 0 && b % i == 0)
{
gcd = i;
}
Lcm = (a * b) / gcd;
}printf(" gcd is : %d\n", gcd);
printf("lcm is :%d\n", Lcm );
return 0;
}