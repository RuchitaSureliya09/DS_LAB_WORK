// 17. Write a program to calculate sum of numbers from m to n.

#include <stdio.h>
void main() {
    int m,n,sum=0;

    printf("Enter starting number m : ");
    scanf("%d",&m);
    printf("Enter starting number n : ");
    scanf("%d",&n);

    for (int i = m; i <= n; i++)
    {
        sum+=i;
    }

    printf("Sum of number %d to %d : %d",m,n,sum);
}