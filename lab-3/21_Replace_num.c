// 21. Read n numbers in an array then read two different numbers, replace 1st number with 2nd number 
// in an array and print its index and final array.

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

    int n1, n2, index, true = 0;

    printf("Enter exist number that you want to change : ");
    scanf("%d", &n1);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n1)
        {
            index = i;
            true ++;
        }
    }

    if (true != 0)
    {
        printf("Enter new number that replace with number 1 : ");
        scanf("%d", &n2);

        arr[index]=n2;

        printf("\n%d replace with %d\n ", n1, n2);
        
        printf("\nNew Array : \n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
    else
        printf("Doesn't exist given number");
}