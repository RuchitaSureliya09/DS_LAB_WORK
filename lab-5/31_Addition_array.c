// 31. Read two 2x2 matrices and perform addition of matrices into third matrix and print it

#include <stdio.h>
void main() {

    int a[2][2],b[2][2],c[2][2];

    printf("Enter elements for a :\n");

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            printf("Enter element : ");
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter elements for b :\n");

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            printf("Enter element : ");
            scanf("%d",&b[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("Addition of two array : \n");

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}