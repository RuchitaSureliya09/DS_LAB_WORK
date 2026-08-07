// 58. Write a program to implement stack using singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int info;
    struct StackNode *link;
};

struct StackNode *top = NULL;

void push()
{
    struct StackNode *Newnode = (struct StackNode *)malloc(sizeof(struct StackNode));

    printf("Enter value : ");
    scanf("%d", &Newnode->info);
    Newnode->link = NULL;

    if (top == NULL)
        top = Newnode;
    else
    {
        Newnode->link = top;
        top = Newnode;
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    struct StackNode *save = top;

    printf("Pop value : %d\n", top->info);

    top = top->link;

    free(save);
}

void peep()
{
    printf("Enter position : ");
    int pos;
    scanf("%d", &pos);

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    struct StackNode *save = top;

    for (int i = 1; i < pos; i++)
    {
        if (save->link == NULL)
        {
            printf("Invalid Position!\n");
            return;
        }
        save = save->link;
    }

    printf("Peep value : %d\n", save->info);
}

void change()
{
    printf("Enter position of value which you want to change : ");
    int pos;
    scanf("%d", &pos);
    printf("Enter new value : ");
    int val;
    scanf("%d", &val);


    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    struct StackNode *save = top;

    for (int i = 1; i < pos; i++)
    {
        if (save->link == NULL)
        {
            printf("Invalid Position!\n");
            return;
        }
        save = save->link;
    }

    save->info = val;
}

void display()
{
    if (top == NULL)
    {
        printf("Empty Stack!\n");
        return;
    }

    struct StackNode *save = top;

    printf("Stack :");
    while (save != NULL)
    {
        printf("  %d", save->info);
        save = save->link;
    }
    printf("\n");
}

void main(){
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
