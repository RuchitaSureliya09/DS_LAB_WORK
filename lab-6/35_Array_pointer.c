// 35. WAP to get and print the array elements using Pointer.

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

    //get array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", (size + i));
    }

    //print array
    printf("\nArray : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(size + i));
    }
}