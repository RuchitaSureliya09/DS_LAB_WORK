// 45. Write a program to copy a linked list.

#include <stdio.h>
#include <stdlib.h>

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
    {
        printf("List is empty!\n");
        return;
    }
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

struct Node *copy(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is Empty !");
        return NULL;
    }
    else
    {
        struct Node *first2, *last, *save, *newNode;
        first2 = NULL;
        last = NULL;
        save = first;

        while (save != NULL)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));

            newNode->info = save->info;
            newNode->link = NULL;

            if (first2 == NULL)
            {
                first2 = newNode;
                last = newNode;
            }
            else
            {
                last->link = newNode;
                last = newNode;
            }

            save = save->link;
        }
        return first2;
    }
}

void main()
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);

    struct Node *node1;
    node1 = creatsll(n);

    struct Node *node2;
    node2 = copy(node1);

    printf("Original ");
    display(node1);

    printf("Copy ");
    display(node2);
}