// 19. Write a program to find position of the smallest number & the largest number from given n numbers.

#include <stdio.h>
void main(){
    int size;

    printf("Enter size of array :");
    scanf("%d",&size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element [%d] : ",i);
        scanf("%d",&arr[i]);
    }

    int max=arr[0],min=arr[0],pos1=0,pos2=0;

    for (int i = 0; i < size; i++)
    {
        if(arr[i]>max){
            max=arr[i];
            pos1=i;
        }
        else if (arr[i]<min){
            min=arr[i];
            pos2=i;
        }
    }
    
    printf("\nLargest number : %d at position index  : %d",max,pos1);
    printf("\nSmallest number : %d at position index : %d",min,pos2);
}