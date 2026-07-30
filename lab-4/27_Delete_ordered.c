// 27. Write a program to delete a number from an array that is already sorted in an ascending order.

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

    int pos, num, found=0;

    printf("\nEnter delete element : ");
    scanf("%d",&num);

    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            pos = i;
            found = 1;
            break;
        }
    }

    if (found)
    {
        for (int i = pos ; i < size-1; i++)
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
    else 
        printf("\nNot found number");
 
}