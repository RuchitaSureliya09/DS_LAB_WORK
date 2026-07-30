// 50. Write a program to swap two consecutive nodes in the linked list.
// Don’t change the values of nodes, implement by changing the link of the nodes.
// by recursion
// - Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
// - Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7

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

    if (first == NULL) {
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

struct Node *swappairs(struct Node *first)
{
    if (first == NULL || first->link == NULL)
    {
        return first;
    }

    struct Node *second = first->link;
    first->link = swappairs(second->link);
    second->link = first;

    return second;
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

    node1 = swappairs(node);

    printf("\nAfter Swaping ");
    display(node1);
}