// 37. WAP to find the largest element in the array using Pointer.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;

    printf("Enter number of element : ");
    scanf("%d", &n);

    int a[n], *size;
    size = a;

    size = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", (size + i));
    }

    printf("\nArray : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(size + i));
    }
}