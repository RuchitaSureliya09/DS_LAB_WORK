// 29. Write a program to merge two unsorted arrays.

#include <stdio.h>
void main() {
    int size,size1;

    printf("Enter size of array 1 : ");
    scanf("%d", &size);

    int arr1[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element a[%d] : ", i);
        scanf("%d", &arr1[i]);
    }

    printf("\nEnter size of array 2 : ");
    scanf("%d", &size1);

    int arr2[size1];

    for (int i = 0; i < size1; i++)
    {
        printf("Enter element a[%d] : ", i);
        scanf("%d", &arr2[i]);
    }

    int new[size+size1],index=0;

    for (int i = 0; i < size; i++)
    {
        new[index]=arr1[i];
        index++;
    }

    for (int i = 0; i < size1; i++)
    {
        new[index]=arr2[i];
        index++;
    }

    printf("\nAfter merge two array new array : \n");

    for (int i = 0; i < index; i++)
    {
        printf("%d\t",new[i]);
    }
}