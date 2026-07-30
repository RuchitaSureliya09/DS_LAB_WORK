// 18. Write a program to calculate average of first n numbers.

#include <stdio.h>
void main(){
    int n;

    printf("Enter number : ");
    scanf("%d",&n);

    int sum=0,num;

    for (int i = 1; i <= n; i++)
    {
        printf("Enter number %d :",i);
        scanf("%d",&num);
        sum+=num;
    }

    printf("Average of given numbers : %.2f",(sum/n));
}