// 44. Write a program to remove the duplicates nodes from given sorted Linked List.
// by node 
// - Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27
// - Output: 1 → 6 → 13 → 27

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
    first = NULL;
    struct Node *save;
    struct Node *newNode;

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

            if(save != NULL)
                printf("-> ");
        }
        printf("\n");
    }
}

void dupdelete(struct Node *first)
{
    struct Node *save, *temp;

    save = first;

    while (save != NULL && save->link != NULL)
    {
        if (save->info == save->link->info)
        {
            temp = save->link;
            save->link = temp->link;
            free(temp);
        }
        else
        {
            save = save->link;
        }
    }
}

void main() {
    printf("Enter number of nodes : ");
    int n;
    scanf("%d",&n);

    struct Node *node;
    node = creatsll(n);

    printf("\nOriginal ");
    display(node);

    dupdelete(node);

    printf("\nAfter delete Dupliacte ");
    display(node);
}