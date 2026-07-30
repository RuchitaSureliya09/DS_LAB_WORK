// 68. Write a program for evaluation of prefix Expression using Stack.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

void main()
{
    char str[100];
    int op1, op2, result;

    printf("Enter any string : ");
    scanf("%s", str);

    int num, i = strlen(str) - 1;

    while (i >= 0)
    {
        if (str[i] == ',')
        {
            i--;
            continue;
        }

        if (isdigit(str[i]))
        {
            num = str[i] - '0';

            if (i > 0 && str[i - 1] != ',')
            {
                int k = 10;
                while (i > 0 && str[i - 1] != ',')
                {
                    num = num + ((str[i - 1] - '0') * k);
                    k *= 10;
                    i--;
                }
            }
            push(num);
            i--;
        }
        else
        {
            op1 = pop();
            op2 = pop();

            switch (str[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                if (op2 != 0)
                    result = op1 / op2;
                else
                {
                    printf("Division by zero not possible!\n");
                    return;
                }
                break;
            case '%':
                if (op2 == 0)
                {
                    printf("Modulo by zero not possible!\n");
                    return;
                }
                result = op1 % op2;
                break;
            default:
                printf("Invalid operator! Check your expression.");
                return;
            }

            push(result);
        }
        i--;
    }

    printf("Answer : %d", stack[top]);
}