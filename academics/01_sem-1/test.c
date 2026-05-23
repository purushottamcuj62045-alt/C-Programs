#include <stdio.h>
void num(int a)
{
    if (a == 50)
    {
        return;
    }
    printf("%d", a);
    num(a + 1);
}
int main()
{
    int n = 1;
    num(n);
}