// 57. Write a menu driven program to implement following operations on the Stack using an Array
// - PUSH, POP, DISPLAY
// - PEEP, CHANGE

#include <stdio.h>
#include <stdlib.h>

int stack[10];
int top = -1;

void push()
{
    int val;

    if (top == 9)
    {
        printf("Stack Overflow!");
        return;
    }
    else
    {
        printf("Enter value : ");
        scanf("%d", &val);

        stack[++top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!");
        return;
    }

    printf("Pop value : %d", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Empty Stack!");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
}

void peep()
{
    printf("Enter position : ");
    int pos;
    scanf("%d", &pos);

    if (top - pos + 1 < 0)
    {
        printf("Stack Underflow!");
        return;
    }

    printf("Peep value : %d", stack[top - pos + 1]);
}

void change()
{
    printf("Enter position of value which you want to change : ");
    int pos;
    scanf("%d", &pos);
    printf("Enter new value : ");
    int val;
    scanf("%d", &val);

    if (top - pos + 1 < 0)
    {
        printf("Stack Underflow!");
        return;
    }

    stack[top - pos + 1] = val;
}

void main()
{
    int choice;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) PUSH\n");
        printf("2) POP\n");
        printf("3) PEEP\n");
        printf("4) CHANGE \n");
        printf("5) DISPLAY\n");
        printf("6) EXIT\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exit!");
            break;
        default:
            printf("Invalide choice!");
            break;
        }

    } while (choice != 6);
}