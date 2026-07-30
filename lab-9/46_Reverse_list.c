// 46. Write a program to reverse a linked list.

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

            if(save != NULL)
                printf("-> ");
        }
        printf("\n");
    }
}

struct Node *reverse(struct Node *first1)
{
    struct Node *curr, *prev, *next;
    curr = first1;
    prev = NULL;
    next = NULL;

    if (first1 == NULL)
    {
        printf("List is Empty!");
        return NULL;
    }
    else
    {
        while (curr != NULL)
        {
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
    }

    return prev;
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
    
    node = reverse(node);
    
    printf("\nAfter Reverse ");
    display(node);
}