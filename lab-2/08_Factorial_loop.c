// 8. WAP to find factorial of a number. (Using loop)

#include <stdio.h>
void main()
{
    int n;

    printf("Enter any number : ");
    scanf("%d", &n);

    int fact = 1;

    for (int i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial of given number %d: %d", n, fact);
}