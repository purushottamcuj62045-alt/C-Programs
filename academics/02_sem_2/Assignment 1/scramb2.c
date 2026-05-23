#include <stdio.h>
#include <string.h>

long long factorial(int n)
{
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    char str[20];
    int freq[100] = {0};
    int len;
    long long ways;

    printf("Enter a word: ");
    scanf("%s", str);

    len = strlen(str);

    for (int i = 0; i < len; i++)
        freq[(int)str[i]]++;

    ways = factorial(len);

    for (int i = 0;i < 100; i++)
        if (freq[i] > 1)
            ways /= factorial(freq[i]);

    printf("Number of ways the word can be scrambled: %lld\n", ways);

    return 0;
}
