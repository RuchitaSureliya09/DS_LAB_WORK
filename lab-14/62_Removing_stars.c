// 62. Removing stars from a string Problem
// You are given a string s, which contains stars *. In one operation, you can: Choose a star in s. Remove the closest non-star character to its left, as well as remove the star itself. Return the string after all stars have been removed.

// Note :
// - The input will be generated such that the operation is always possible.
// - It can be shown that the resulting string will always be unique.

// Sample Example-1:                Sample Example-2:
// Input: s = "leet**cod*e"         Input: s = "erase*****"
// Output: "lecoe"                  Output: ""


#include <stdio.h>
#include <string.h>
#define max 20

char stack[max];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

void main()
{
    char str[max];

    printf("Enter string : ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '*')
            pop();
        else
            push(str[i]);
    }

    printf("Output: ");

    for (int i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
}