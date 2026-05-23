#include <stdio.h>
void italy();
void brazil();
void argentina();
int main()
{
    printf("I am in main\n");
    italy();
    brazil();
    argentina();
    return 0;
}
void italy()
{
    printf("I am in Italy\n");
}
void brazil()
{
    printf("I am in brazil");
}
void argentina()
{
    printf("I am in Argentina");
}