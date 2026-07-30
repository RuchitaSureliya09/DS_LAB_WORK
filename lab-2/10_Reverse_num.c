// 10. WAP to reverse a number.

#include <stdio.h>
void main()
{
    int n;

    printf("Enter any number : ");
    scanf("%d", &n);

    int rem = 0, rev = 0;

    while (n != 0)
    {
        rem = n % 10;
        rev = (rev * 10) + rem;
        n /= 10;
    }

    printf("Reverse number of given number : %d", rev);
}