// 43. WAP to check whether 2 singly linked lists are same or not.

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
    int n1;
    scanf("%d", &n1);

    struct Node *node1;
    node1 = creatsll(n1);

    printf("\nEnter number of nodes : ");
    int n2;
    scanf("%d", &n2);

    struct Node *node2;
    node2 = creatsll(n2);

    printf("\n");
    display(node1);
    display(node2);

    if (n1 != n2)
    {
        printf("\nNot Same Both Singly Linked List");
        return;
    }
    else
    {
        int flag = 1;

        while (node1 != NULL && node2 != NULL)
        {
            if (node1->info != node2->info)
            {
                flag = 0;
                break;
            }
            node1 = node1->link;
            node2 = node2->link;
        }

        if (flag == 1)
        {
            printf("\nSame Both Singly Linked List");
        }
        else
        {
            printf("\nNot Same Both Singly Linked List");
        }
    }
}