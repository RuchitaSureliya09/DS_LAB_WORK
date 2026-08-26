// 61. Valid Parenthesis Problem
// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.
// Now Chef wants to know if the given string is balanced or not.
// If is balanced then print 1, otherwise print 0.

// A balanced parenthesis string is defined as follows:
// - The empty string is balanced
// - If P is balanced then (P), {P}, [P] is also balanced
// - if P and Q are balanced PQ is also balanced
// - "([])", "({})[()]" are balanced parenthesis strings
// - "([{]})", "())" are not balanced.


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
    int valid = 1;

    printf("Enter Input String : ");
    scanf("%s", str);

    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if(top == -1)
            {
                valid = 0;
                break;
            }

            char ch = pop();

            if((str[i] == ')' && ch != '(') ||
               (str[i] == '}' && ch != '{') ||
               (str[i] == ']' && ch != '['))
            {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1)
        valid = 0;


    if(valid)
        printf("1");
    else
        printf("0");
}