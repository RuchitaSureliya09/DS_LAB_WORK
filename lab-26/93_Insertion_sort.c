// 93. Write a program to implement Insertion Sort using Array.

#include <stdio.h>

void main()
{
    int a[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    printf("Sorted array by Insertion Sort :\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}