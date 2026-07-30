// 36. WAP to calculate the sum of n numbers using Pointer.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, *size, sum = 0;

    printf("Enter number of element : ");
    scanf("%d", &n);

    size = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", (size + i));
        sum = sum + *(size + i);
    }

    printf("\nArray : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(size + i));
    }

    printf("\n\nSum of array element : %d",sum);
}