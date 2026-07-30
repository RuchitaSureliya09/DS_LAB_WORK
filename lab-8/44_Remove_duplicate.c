// 44. Write a program to remove the duplicates nodes from given sorted Linked List.
// by info 
// - Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27
// - Output: 1 → 6 → 13 → 27

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *creatsll(int total_nodes)
{
    struct Node *first = NULL;
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

void dupdelete(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty !");
        return;
    }
    else
    {
        struct Node *save, *dup;
        save = first;

        while (save->link != NULL)
        {
            if (save->info == save->link->info)
            {
                dup = save->link;
                save->link = dup->link;
                free(dup);
            }
            else
            {
                save = save->link;
            }
        }
    }
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

void main()
{
    printf("Enter number of nodes : ");
    int n;
    scanf("%d", &n);

    struct Node *node;
    node = creatsll(n);

    printf("Original ");
    display(node);

    dupdelete(node);

    printf("After delete Dupliacte ");
    display(node);
}