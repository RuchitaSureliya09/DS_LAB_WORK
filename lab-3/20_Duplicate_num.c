// 20. Write a program to find whether the array contains a duplicate number or not.

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

    int a=0;

    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]==arr[j]){
                a=1;
                break;
            }
        }
    }
    
    if(a==1)
        printf("\nDuplicate element available");
    else
        printf("\nDuplicate element not available");
    
}