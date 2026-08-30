// 47. Write a program to sort elements of a linked list.
// by change node

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
    int swapped;

    do
    {
        struct Node *curr, *nextNode, *prev;
        curr = first;
        prev = NULL;
        swapped = 0;

        while (curr != NULL && curr->link != NULL)
        {
            nextNode = curr->link;

            if (curr->info > nextNode->info)
            {
                curr->link = nextNode->link;
                nextNode->link = curr;

                if (prev == NULL)
                {
                    first = nextNode;
                }
                else
                {
                    prev->link = nextNode;
                }

                prev = nextNode;
                swapped = 1;
            }
            else
            {
                prev = curr;
                curr = curr->link;
            }
        }
    } while (swapped);

    return first;
}

void main()
{
    printf("Enter number of nodes : ");
    int n;
    scanf("%d", &n);

    struct Node *node;
    node = creatsll(n);

    printf("\nOriginal ");
    display(node);

    node = sortlist(node);

    printf("\nAfter Sorting ");
    display(node);
}