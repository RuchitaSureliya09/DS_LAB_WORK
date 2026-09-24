// 90. Write a program to implement a Binary Search using Array. (recursive) 

#include <stdio.h>

int b_search(int a[], int low, int high, int key)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;


    if(a[mid] == key)
        return mid;
    else if(key < a[mid])
        return b_search(a, low, mid - 1, key);
    else
        return b_search(a, mid + 1, high, key);
}

void main()
{
    int a[100], n, key, result;

    printf("Binary Search By Recursive : \n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = b_search(a, 0, n - 1, key);

    if(result == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", result + 1);
}