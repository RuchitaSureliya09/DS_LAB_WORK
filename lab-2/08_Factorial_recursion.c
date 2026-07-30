// 8. WAP to find factorial of a number. (recursion)

#include <stdio.h>
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        return (n * factorial(n - 1));
}
void main()
{
    int n;

    printf("Enter any number : ");
    scanf("%d", &n);

    printf("Factorail of given number %d : %d", n, factorial(n));
}