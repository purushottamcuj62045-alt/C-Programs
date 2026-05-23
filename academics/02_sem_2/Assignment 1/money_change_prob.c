#include <stdio.h>

int main()
{
    int amount;
    int coins5, coins2, coins1;
    int remaining;

    printf("Enter amount to be changed: ");

    // Validate input FIRST
    if (scanf("%d", &amount) != 1)
    {
        printf("Invalid input! Please enter an integer value.\n");
        return 0;
    }

    // Validate amount
    if (amount <= 0)
    {
        printf("Invalid amount\n");
        return 0;
    }

    // Main logic
    coins5 = amount / 5;
    remaining = amount % 5;

    coins2 = remaining / 2;
    remaining = remaining % 2;

    coins1 = remaining;

    printf("Rs 5 coins : %d\n", coins5);
    printf("Rs 2 coins : %d\n", coins2);
    printf("Rs 1 coins : %d\n", coins1);

    printf("Minimum number of coins = %d\n",
           coins5 + coins2 + coins1);

    return 0;
}
