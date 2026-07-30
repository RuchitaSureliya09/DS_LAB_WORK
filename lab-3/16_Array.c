// 16. Write a program to read and display n numbers using an array.

#include <stdio.h>
void main(){
    int size;

    printf("Enter size of array : ");
    scanf("%d",&size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element a[%d] : ",i);
        scanf("%d",&arr[i]);
    }

    printf("Array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
}