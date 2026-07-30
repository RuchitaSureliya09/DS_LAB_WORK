// 2. WAP to find whether a number is odd or even.

#include <stdio.h>
void main()
{
    int n;

    printf("Enter any number : ");
    scanf("%d", &n);

    if (n % 2 == 0)
        printf("Given number is Even");
    else
        printf("Given number is Odd");
}