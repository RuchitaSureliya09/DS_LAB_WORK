// 51. Write a menu driven program to implement following operations on the circular linked list.
// - Insert a node at the front of the linked list.
// - Delete a node from specified position.
// - Insert a node at the end of the linked list.
// - Display all nodes.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;
struct Node *last = NULL;

void insertfirst()
{
    struct Node *Newnode;
    Newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new node : ");
    scanf("%d", &Newnode->info);
    Newnode->link = NULL;

    if (first == NULL)
    {
        Newnode->link = Newnode;
        first = Newnode;
        last = Newnode;
    }
    else
    {
        Newnode->link = first;
        last->link = Newnode;
        first = Newnode;
    }
}

void deletefirst()
{
    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (first == last)
    {
        printf("Deleted node : %d\n", first->info);

        free(first);
        first = NULL;
        last = NULL;
        return;
    }

    struct Node *save = first;

    first = first->link;
    last->link = first;

    printf("Deleted node : %d\n", save->info);

    free(save);
}

void deleteposition()
{
    int pos;
    printf("Enter position : ");
    scanf("%d", &pos);

    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1)
    {
        deletefirst();
        return;
    }

    struct Node *pred, *save;
    save = first;

    int i = 1;

    while (i < pos && save != last)
    {
        pred = save;
        save = save->link;
        i++;
    }

    if (i != pos)
    {
        printf("Invalid position !\n");
        return;
    }

    pred->link = save->link;

    if (save == last)
    {
        last = pred;
    }

    printf("Delete node : %d\n", save->info);

    free(save);
}

void insertlast()
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new node : ");
    scanf("%d", &Newnode->info);

    Newnode->link = NULL;

    if (first == NULL)
    {
        Newnode->link = Newnode;
        first = Newnode;
        last = Newnode;
    }
    else
    {
        Newnode->link = first;
        last->link = Newnode;
        last = Newnode;
    }
}

void display()
{
    struct Node *save;
    save = first;

    if (first == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        printf("Circular Liked List : ");

        do
        {
            printf("%d -> ", save->info);
            save = save->link;

        } while (save != first);

        printf("\n");
    }
}

void main()
{
    int choice;
    do
    {
        printf("\n----- MENU -----\n");
        printf("1) Insert node at front\n");
        printf("2) Display nodes\n");
        printf("3) Insert node at end\n");
        printf("4) Delete node from position\n");
        printf("5) Exit\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertfirst();
            display();
            break;
        case 2:
            display();
            break;
        case 3:
            insertlast();
            display();
            break;
        case 4:
            deleteposition();
            display();
            break;
        case 5:
            printf("Exit !\n");
            break;
        default :
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 5);
}
