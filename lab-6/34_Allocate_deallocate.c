// 34. WAP to allocate and de-allocate memory for int, char and float variable at runtime.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p1;
    char *p2;
    float *p3;

    // allocate
    p1 = (int *)malloc(sizeof(int));
    p2 = (char *)malloc(sizeof(char));
    p3 = (float *)malloc(sizeof(float));

    printf("Enter integer : ");
    scanf("%d", p1);
    printf("Enter character : ");
    scanf(" %c", p2);
    printf("Enter float : ");
    scanf("%f", p3);

    printf("\nInteger : value = %d & address = %d\n", *p1, p1);
    printf("Character : value = %c & address = %d\n", *p2, p2);
    printf("Float : value = %.2f & address = %d", *p3, p3);

    // de-allocate
    free(p1);
    free(p2);
    free(p3);
}