// 15. WAP to print Armstrong number from 1 to 1000.

#include <stdio.h>
int power(int x, int y);
void armstrong(int n)
{
    int temp = n, tem1 = n, count = 0;

    while (temp != 0)
    {
        temp % 10;
        temp /= 10;
        count++;
    }

    int rem = 0, sum = 0;

    while (tem1 != 0)
    {
        rem = tem1 % 10;
        sum += power(rem, count);
        tem1 /= 10;
    }

    if (sum == n)
        printf("%d\n", n);
}

int power(int x, int y)
{
    int mul = 1;

    for (int i = 0; i < y; i++)
        mul *= x;

    return mul;
}

void main()
{
    printf("Armstrong number between 1 to 1000 : \n");

    for (int i = 1; i <= 1000; i++)
    {
        armstrong(i);
    }
}