// 54. Write a menu driven program to implement following operations on the doubly linked list.
// - Insert a node at the front of the linked list.
// - Delete a node from specified position.
// - Insert a node at the end of the linked list.
// - Display all nodes.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first = NULL;
struct Node *last = NULL;

void insertFront()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->lptr = NULL;
    newnode->rptr = first;

    if (first == NULL)
    {
        first = last = newnode;
    }
    else
    {
        first->lptr = newnode;
        first = newnode;
    }
}

void insertEnd()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->rptr = NULL;
    newnode->lptr = last;

    if (last == NULL)
    {
        first = last = newnode;
    }
    else
    {
        last->rptr = newnode;
        last = newnode;
    }
}

void deletePosition()
{
    int pos;
    struct Node *temp;

    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = first;

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->rptr;
    }

    if (temp == NULL)
    {
        printf("Position does not exist.\n");
        return;
    }

    if (temp == first && temp == last)
    {
        first = last = NULL;
    }
    else if (temp == first)
    {
        first = first->rptr;
        first->lptr = NULL;
    }
    else if (temp == last)
    {
        last = last->lptr;
        last->rptr = NULL;
    }
    else
    {
        temp->lptr->rptr = temp->rptr;
        temp->rptr->lptr = temp->lptr;
    }

    free(temp);
}

void display()
{

    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *save;
    save = first;

    printf("Doubly Liked List : ");

    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->rptr;

        if (save != NULL)
            printf("<-> ");
    }

    printf("\n");
}

void main()
{
    int choice;

    do
    {
        printf("\n----- DOUBLY LINKED LIST -----\n");
        printf("1. Insert a node at front\n");
        printf("2. Delete a node from specified position\n");
        printf("3. Insert a node at end\n");
        printf("4. Display all nodes\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertFront();
            display();
            break;

        case 2:
            deletePosition();
            display();
            break;

        case 3:
            insertEnd();
            display();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exit!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);
}
