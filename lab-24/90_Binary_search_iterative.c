// 90. Write a program to implement a Binary Search using Array. (Iterative) 

#include <stdio.h>

void main()
{
    int a[100], n, key, low, high, mid, found = 0;

    printf("Binary Search By Iterative : \n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            printf("Element found at position %d", mid + 1);
            found = 1;
            break;
        }
        else if(key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if(found == 0)
        printf("Given element not found");
}