// 25. Write a program to delete a number from a given location in an array.

#include <stdio.h>
void main()
{
    int size;

    printf("Enter size of array : ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element a[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    int pos;

    printf("\nEnter position of delete element : ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= size)
    {
        printf("Invalid position");
        return;
    }

    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("\nAfter delete element : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}