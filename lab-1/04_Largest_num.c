// 4. WAP to find the largest among the given three numbers by user.

#include <stdio.h>
void main()
{
    int n1, n2, n3;

    printf("Enter any three number : ");
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 > n2)
    {
        if (n1 > n3)
            printf("Largest number is %d", n1);
        else
            printf("Largest number is %d", n3);
    }
    else
    {
        if (n2 > n3)
            printf("Largest number is %d", n2);
        else
            printf("Largest number is %d", n3);
    }
}