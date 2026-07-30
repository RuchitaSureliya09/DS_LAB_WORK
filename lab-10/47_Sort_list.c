// 47. Write a program to sort elements of a linked list.
// by info

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first;

struct Node *creatsll(int total_nodes)
{
    struct Node *save;
    struct Node *newNode;
    first = NULL;

    for (int i = 0; i < total_nodes; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter new node : ");
        scanf("%d", &newNode->info);

        newNode->link = NULL;

        if (first == NULL)
        {
            first = newNode;
            save = first;
        }
        else
        {
            save->link = newNode;
            save = newNode;
        }
    }
    return first;
}

void display(struct Node *first)
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

struct Node *sortlist(struct Node *first)
{
    struct Node *save, *next;
    save = first;
    next = NULL;
    int temp;

    if (first == NULL)
    {
        printf("List is Empty !");
    }

    while (save != NULL)
    {
        next = save;
        while (next != NULL)
        {
            if (save->info > next->info)
            {
                temp = next->info;
                next->info = save->info;
                save->info = temp;
            }
            next = next->link;
        }
        save = save->link;
    }
    return first;
}

void main()
{
    printf("Enter number of nodes : ");
    int n;
    scanf("%d", &n);

    struct Node *node, *node1;
    node = creatsll(n);

    printf("\nOriginal ");
    display(node);

    node1 = sortlist(node);

    printf("\nAfter Sorting ");
    display(node1);
}