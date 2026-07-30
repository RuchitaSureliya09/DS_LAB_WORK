// 9. WAP to find power of a number using loop.

#include <stdio.h>
void main()
{
    int x, y;

    printf("Enter value of base x & power y : ");
    scanf("%d %d", &x, &y);

    int mul = 1;

    for (int i = 0; i < y; i++)
        mul *= x;

    printf("Answer of %d^%d : %d", x, y, mul);
}