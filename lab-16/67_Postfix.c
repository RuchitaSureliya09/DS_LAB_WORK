// 67. Write a program for evaluation of postfix Expression using Stack.

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

    printf("Enter any string (comma seprated): ");
    scanf("%s", str);
    int num, i = 0;

    while (str[i] != '\0')
    {
        if (isdigit(str[i]))
        {
            num = str[i] - '0';

            if (str[i + 1] != ',')
            {
                do
                {
                    num = (num * 10) + (str[i + 1] - '0');
                    i++;
                } while (str[i + 1] != ',');
            }
            push(num);
        }
        else
        {
            op2 = pop();
            op1 = pop();

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
                if (op2 == 0)
                {
                    printf("Division by zero not possible!\n");
                    return;
                }
                result = op1 / op2;
                break;
            case '%':
                if (op2 == 0)
                {
                    printf("Modulo by zero not possible!\n");
                    return;
                }
                result = op1 % op2;
                break;
                ;
            default:
                printf("Invalid operator! Check your expression.");
                return;
            }

            push(result);
        }
        i++;
    }

    printf("Answer : %d", stack[top]);
}