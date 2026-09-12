// 65. Write a program to convert infix notation to postfix notation using stack.

#include <stdio.h>
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
    {
        return '\0';
    }

    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }

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

void main()
{
    char infix[max], postfix[max], ch;
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
                pop();
        }
        else
        {
            while (top != -1 && peek() != '(' && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}