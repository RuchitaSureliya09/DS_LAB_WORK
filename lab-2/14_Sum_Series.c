// 14. WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n).

#include <stdio.h>
void main()
{
    int n;

    printf("Enter any number : ");
    scanf("%d", &n);

    int sum = 0, sum1 = 0;

    for (int i = 1; i <= n; i++)
    {
        sum1 = 0;
        for (int j = 1; j <= i; j++)
        {
            sum1 += j;
        }
        sum += sum1;
    }

    printf("Sum of given series : %d", sum);
}