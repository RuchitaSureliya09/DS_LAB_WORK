// 39. WAP to check whether the string is Palindrome or not using Pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char *str;
    str = (char *)malloc(100 * sizeof(char));

    printf("Enter string : ");
    scanf("%s", str);

    int len = strlen(str);
    int i = 0, j = len - 1;

    while (i <= j)
    {
        if (*(str + i) != *(str + j))
        {
            printf("Not Pallindrome string");
            break;
        }
        i++;
        j--;
    }

    if (i > j)
    {
        printf("Pallindrome string");
    }
}