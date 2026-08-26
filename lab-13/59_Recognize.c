// 59. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a program to solve the above problem.

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
    int len, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        push(str[i]);
    }

    for(int i = 0; i < len; i++)
    {
        if(str[i] != pop())
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        printf("String is recognized");
    else
        printf("String is not recognized");
}