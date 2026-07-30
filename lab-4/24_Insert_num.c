// 24. Write a program to insert a number at a given location in an array.

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

    int pos, new;

    printf("\nEnter new number : ");
    scanf("%d", &new);
    printf("\nEnter position of new number : ");
    scanf("%d", &pos);

    if (pos < 1 || pos > size + 1)
    {
        printf("\nInvalid position");
        return;
    }

    for (int i = size; i > pos - 1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = new;
    size++;

    printf("\nAfter insert new number : \n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}