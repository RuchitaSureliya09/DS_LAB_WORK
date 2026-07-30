// 13. WAP to print prime numbers between given interval.

#include <stdio.h>
void prime(int n)
{
    int flag = 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            flag++;
    }

    if (flag == 0)
        printf("%d\n",n);
}

void main()
{
    int n1,n2;

    printf("Enter any two number : ");
    scanf("%d %d", &n1,&n2);
    
    for (int i = n1; i <= n2; i++)
    {
        prime(i);
    }
}