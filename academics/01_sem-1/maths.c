/*WAP to practice math functions such as sin(), cos(), log(), pow(), sqrt() etc.
by including <math.h> header file.8*/
#include<stdio.h>
#include<math.h>
int main()
{
   float deg,rad,num,num2;
    printf("Enter the degree: \n");
    scanf("%f",&deg);
    printf("Enter any number: \n");
    scanf("%f",&num);
    printf("Enter number for power\n");
    scanf("%f",&num2);
    rad=0.01745*deg;
    float sin_value = sin(rad);
    float cos_value = cos(rad);
    float log_value = log(num);
    float pow_value = pow(num, num2);
    float sqrt_value = sqrt(num);

    printf("Sin value =%f\n",sin_value);
    printf("cos value = %f\n",cos_value);
    printf("Log_value = %f\n",log_value);
    printf("Power vale/ exponential value = %f\n",pow_value);
    printf("Power value = %f\n",pow_value);
    return 0;
    
}