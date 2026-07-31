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
        printf("Stack Overflow!\n");
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
        printf("Stack Underflow!\n");
        return;
    }

    printf("Pop value : %d\n", stack[top--]);
}

void display()
{
    if (top == -1)
    {
        printf("Empty Stack!\n");
        return;
    }

    printf("Stack :");
    for (int i = top; i >= 0; i--)
    {
        printf("  %d", stack[i]);
    }
    printf("\n");
}

void peep()
{
    printf("Enter position : ");
    int pos;
    scanf("%d", &pos);

    if (top - pos + 1 < 0)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Peep value : %d\n", stack[top - pos + 1]);
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
        printf("Stack Underflow!\n");
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
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            peep();
            display();
            break;
        case 4:
            change();
            display();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exit!\n");
            break;
        default:
            printf("Invalide choice!\n");
            break;
        }

    } while (choice != 6);
}