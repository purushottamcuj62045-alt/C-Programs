#include <stdio.h>

float fact(int n) {
    float f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

float nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    int rows;

    printf("Enter number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) {

        for (int s = 0; s < rows - i - 1; s++)
            printf(" ");

        for (int j = 0; j <= i; j++) {
            printf("%.0f ", nCr(i, j));
        }

        printf("\n");
    }

    return 0;
}