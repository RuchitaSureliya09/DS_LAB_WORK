// 22. WAP to print Pascal triangle.

#include <stdio.h>
void main()
{
    int row;

    printf("Enter number of rows : ");
    scanf("%d", &row);

    for (int i = 0; i < row; i++)
    {
        // space
        for (int j = 0; j < row - i; j++)
        {
            printf(" ");
        }

        // value
        int num = 1;
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", num);
            num = num * (i - j) / (j + 1);
        }
        printf("\n");
    }
}