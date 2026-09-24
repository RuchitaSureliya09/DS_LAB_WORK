// 92. Write a program to implement Selection Sort using Array. 

#include <stdio.h>

void main()
{
    int a[100], n, min, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Sorted array by Selection Sort :\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}