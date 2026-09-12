// 60. Write a program to determine if an input character string is of the form (a^i)(b^i) where i >= 1
// i.e., Number of ‘a’ should be equal to number of ‘b’.

#include <stdio.h>
#include <string.h>
#define max 20

char stack[max];
int top = -1;

void push(char ch)
{
    if (top == max - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = ch;
}

char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

void main()
{
    char str[max];
    int i = 0, valid = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[i] == 'a')
    {
        push(str[i]);
        i++;
    }

    if (top == -1)
        valid = 0;

    while (valid && str[i] == 'b')
    {
        if (top == -1)
        {
            valid = 0;
            break;
        }
        pop();
        i++;
    }

    if (str[i] != '\0' || top != -1)
        valid = 0;

    if (valid)
        printf("String is of the form (a^i)(b^i)\n");
    else
        printf("String is NOT of the form (a^i)(b^i)\n");
}