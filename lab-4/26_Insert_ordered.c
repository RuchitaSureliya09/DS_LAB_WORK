// 26. Write a program to insert a number in an array that is already sorted in an ascending order.

#include <stdio.h>

void main()
{
    int size;

    printf("Enter size of array : ");
    scanf("%d", &size);

    int arr[size + 1];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element a[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    int pos = size, new;

    printf("\nEnter new number : ");
    scanf("%d", &new);

    for (int i = 0; i < size; i++)
    {
        if (new < arr[i])
        {
            pos = i;
            break;
        }
    }

    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = new; // in case new number sabse large hai to vo last me insert hoga because pos = size pehle hi initialize hai
    size++;

    printf("\nAfter insert new number : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}