// 38. WAP to sort the array elements using Pointer.

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

    printf("\nBefore sorting : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(size + i));
    }

    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(size + i) > *(size + j))
            {
                temp = *(size + i);
                *(size + i) = *(size + j);
                *(size + j) = temp;
            }
        }
    }

    printf("\nAfter sorting : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(size + i));
    }
}