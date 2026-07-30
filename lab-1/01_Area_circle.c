// 1. WAP to calculate area of a Circle (A = πr2).

#include <stdio.h>
void main()
{
    int rad;

    printf("Enter radius : ");
    scanf("%d", &rad);

    float area = 3.14 * rad * rad;

    printf("Area of Circle : %.2f", area);
}