//WAP to find roots of a quadratic equation (for D>=0 case).
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d;
    printf("Enter coeffient of X square");
    scanf("%d",&a);
    printf("Enter coeffient of X ");
    scanf("%d",&b);
    printf("Enter constant term ");
    scanf("%d",&c);
    d=(b*b)-4*a*c;
    d=sqrt(d);
    int root1=-b-d/2*a;
    int root2=-b+d/2*a;
    if (root1=root2)
    {
        printf("Roots are equal:-%d\n",root1);
    }
    else
    printf("Roots are :-",root1,root2);


}