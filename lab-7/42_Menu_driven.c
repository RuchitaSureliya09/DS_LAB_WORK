// 42. Write a menu driven program to implement following operations on the singly linked list.
// - Insert a node at the front of the linked list.
// - Display all nodes.
// - Delete a first node of the linked list.
// - Insert a node at the end of the linked list.
// - Delete a last node of the linked list.
// - Delete a node from specified position.
// - Count the no. of nodes in the linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insertfirst()
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new node : ");
    scanf("%d", &Newnode->info);
    Newnode->link = NULL;

    if (first == NULL)
        first = Newnode;
    else
    {
        Newnode->link = first;
        first = Newnode;
    }
}

void display()
{
    struct Node *save;
    save = first;

    if (first == NULL)
        printf("List is empty!\n");
    else
    {
        printf("Singly Liked List : ");

        while (save != NULL)
        {
            printf("%d ", save->info);
            save = save->link;

            if (save != NULL)
                printf("-> ");
        }
        printf("\n");
    }
}

void deletefirst()
{
    if (first == NULL)
        printf("List is empty!\n");
    else
    {
        struct Node *save;
        save = first;

        first = first->link;

        printf("Deleted node : %d\n", save->info);

        free(save);
    }
}

void insertlast()
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new node : ");
    scanf("%d", &Newnode->info);

    Newnode->link = NULL;

    if (first == NULL)
        first = Newnode;
    else
    {
        struct Node *save;
        save = first;

        while (save->link != NULL)
        {
            save = save->link;
        }

        save->link = Newnode;
    }
}

void deletelast()
{
    if (first == NULL)
        printf("List is empty!\n");
    else
    {
        if (first->link == NULL)
        {
            printf("Delete last node : %d\n", first->info);

            free(first);
            first = NULL;

            return;
        }

        struct Node *pred;
        struct Node *save;
        save = first;

        while (save->link != NULL)
        {
            pred = save;
            save = save->link;
        }

        if (save->link == NULL)
            pred->link = NULL;

        printf("Delete last node : %d\n", save->info);

        free(save);
    }
}

void deleteposition()
{
    int pos;
    printf("Enter position : ");
    scanf("%d", &pos);

    if (first == NULL)
        printf("List is empty!\n");
    else if (pos == 1)
        deletefirst();
    else
    {
        struct Node *pred;
        struct Node *save;
        save = first;

        int i = 1;

        while (i < pos && save != NULL)
        {
            pred = save;
            save = save->link;
            i++;
        }

        if (save == NULL)
            printf("Invalid position !\n");
        else
            pred->link = save->link;

        printf("Delete node : %d\n", save->info);

        free(save);
    }
}

void countnode()
{
    struct Node *save;
    save = first;

    int count = 0;

    while (save != NULL)
    {
        count++;
        save = save->link;
    }

    printf("Total number of node : %d\n", count);
}

void main()
{
    int choice;
    do
    {
        printf("\n----- MENU -----\n");
        printf("1) Insert node at front\n");
        printf("2) Display nodes\n");
        printf("3) Delete first node\n");
        printf("4) Insert node at end\n");
        printf("5) Delete last node\n");
        printf("6) Delete node from position\n");
        printf("7) Count nodes\n");
        printf("8) Exit\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertfirst();
            break;
        case 2:
            display();
            break;
        case 3:
            deletefirst();
            break;
        case 4:
            insertlast();
            break;
        case 5:
            deletelast();
            break;
        case 6:
            deleteposition();
            break;
        case 7:
            countnode();
            break;
        case 8:
            printf("Exit !\n");
            break;
        default:
            printf("Invalid choice!");
            break;
        }

    } while (choice != 8);
}