// 66. Write a program to convert infix notation to prefix notation using stack.

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

char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int isoperand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return 1;

    return 0;
}

void reverse(char str[])
{
    int j;
    char temp;

    for (int i = 0; i < strlen(str) / 2; i++)
    {
        j = strlen(str) - 1 - i;

        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void main()
{
    char infix[max], prefix[max], ch;
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    top = -1;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isoperand(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                prefix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
                pop();
        }
        else
        {
            while (top != -1 && peek() != '(' && precedence(peek()) > precedence(ch))
            {
                prefix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);
}