// 71. Write a program to implement queue using singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue()
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value : ");
    scanf("%d", &Newnode->info);
    Newnode->link = NULL;

    if (front == NULL)
    {
        front = Newnode;
        rear = Newnode;
    }
    else
    {
        rear->link = Newnode;
        rear = Newnode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue Underflow!");
        return;
    }

    struct Node *save = front;

    printf("Dequeue element : %d\n", front->info);

    front = front->link;

    if (front == NULL)
        rear = NULL;

    free(save);
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue Empty!\n");
        return;
    }

    struct Node *save = front;

    printf("Queue : ");
    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;

        if (save != NULL)
            printf("-> ");
    }
    printf("\n");
}

void main()
{
    int choice;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) ENQUEUE\n");
        printf("2) DEQUEUE\n");
        printf("3) DISPLAY\n");
        printf("4) EXIT\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            display();
            break;
        case 2:
            dequeue();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit!");
            break;
        default:
            printf("Invalid choice!");
            break;
        }

    } while (choice != 4);
}
