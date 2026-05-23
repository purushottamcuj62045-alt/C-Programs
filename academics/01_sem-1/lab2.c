#include <stdio.h>
int main()
 {
int num, originalNum, remainder, result;
printf("Armstrong numbers between 1 and 1000 are:\n");
for(num = 1; num <= 1000; num++)
 {
originalNum = num;
result = 0;
while(originalNum != 0) 
{
remainder = originalNum % 10;
result += remainder * remainder * remainder;
originalNum /= 10;
}
if(result == num)
 {
if (num%2==0)
{
    printf("\n%d=even", num);
}
else
{
    printf("\n%d=odd", num);
}
}
}
return 0;
}