// 28. Write a program to delete duplicate numbers from an array.

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

    int n_size = size;

    for (int i = 0; i < n_size; i++)
    {
        for (int j = i + 1; j < n_size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n_size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }

                n_size--;
                j--; // check at same position
            }
        }
    }

    printf("\nArray after deleting duplicate elements:\n");

    for (int i = 0; i < n_size; i++)
    {
        printf("%d\t", arr[i]);
    }
}