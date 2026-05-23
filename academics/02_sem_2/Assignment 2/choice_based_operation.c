#include <stdio.h>
int main()
{
    char add;
    int choice;
    int sum=0;

    // iniating of do-while loop

    do
    {
        printf("\n--- MENU ---");
        printf("\n1. Factorial");
        printf("\n2. Fibonacci");
        printf("\n3. Sum of Fibonacci");
        printf("\n4. Last digit of last Fibonacci ");
        printf("\n5. Square of last digit of numbers of Fibonacci");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

// Using switch for option locking

        switch (choice)
        {

        // Finding Factorial

            case 1:
            {
                int fact = 1, num;
                printf("Enter a number to find factorial: ");
                scanf("%d", &num);
                if(num<=0)
                {
                    printf("Factorial is Not possible\n");
                }
                else

                for (int i = 1; i <= num; i++)
                {
                    fact = fact * i;
                }
                printf("Factorial = %d\n", fact);
                break;
            }

        // Finding Fibonacci

            case 2:
            {
                int a = 0, b = 1, c, n;
                printf("Enter number of terms: ");
                scanf("%d", &n);

                 if(n<=0)
                {
                    printf("Fibonacci is Not possible\n");
                }
                else

                printf("Fibonacci Series: ");
                for (int i = 1; i <= n; i++)
                {
                    printf("%d ", a);
                    c = a + b;
                    a = b;
                    b = c;
                }
                printf("\n");
                break;
            }

// Sum of Fibonacci series

            case 3:
            {
                  int a = 0, b = 1, c, n;
                printf("Enter number of terms: ");
                scanf("%d", &n);
             if(n<=0)
                {
                    printf("Fibonacci is Not possible");
                }
                else
            {
                
                for (int i = 1; i <= n; i++)
                {
                    c = a + b;
                    a = b;
                    b = c;
                    sum = sum+a;
                }
                
                printf("Sum of Fibonacci Series: %d\n",sum);
                break;
            }
            }

            // Finding last digit of Fibonacci

            case 4:
            {
                 int n, a = 0, b = 1, c;
                printf("Enter number of terms: ");
                scanf("%d", &n);

              if (n < 0)
              {
              printf("Fibonacci not Found\n");
             }
            else
             {
            for (int i = 1; i <= n; i++)
            {
            c = (a + b) % 10;
             a = b;
            b = c;
             }

        printf("Last digit of Fibonacci is: %d\n", a);
        }
        break;
        }

        // Finding Square of last Digit of Fibonacci
        
        case 5:
        {
         
        int n, a = 0, b = 1, c;
        int lastDigit, square;
         printf("Enter number of terms: ");
         scanf("%d", &n);

         if (n < 0)
        {
        printf("Fibonacci not found\n");
        }
         else
    
        for (int i = 1; i <= n; i++)
        {
            c = (a + b) % 10;   // keep last digit only
            a = b;
            b = c;
            lastDigit = a;
        square = lastDigit * lastDigit;
        printf("Square of last digit is: %d\n", square);
        }
        printf("\n");
    }
    break;

        

        // Exiting program

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }

        // Using sentinal loop

        printf("Do you want to run the program again (y/n): ");
        scanf(" %c", &add);   

    } while (add == 'y' || add == 'Y');

    return 0;
}

