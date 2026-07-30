// 12. WAP to check whether a number is prime or not.

#include <stdio.h>
void main()
{
    int n;

    printf("Enter any number : ");
    scanf("%d", &n);

    int flag = 0;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            flag++;
    }

    if (flag == 0)
        printf("Given number is Prime");
    else
        printf("Given numbet is not Prime");
}