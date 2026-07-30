// 48. WAP to swap Kth node from beginning with Kth node from end in a singly linked list.
// by change info

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

struct Node *swapnodes(struct Node *first, int k, int n)
{
    if (k <= 0 || k > n)
    {
        printf("Invalid value of k\n");
        return first;
    }

    struct Node *save1, *save2;
    int temp;
    save1 = first;
    save2 = first;

    for (int i = 1; i < k; i++)
    {
        save1 = save1->link;
    }

    for (int i = 1; i < n - k + 1; i++)
    {
        save2 = save2->link;
    }

    temp = save1->info;
    save1->info = save2->info;
    save2->info = temp;

    return first;
}

void main()
{
    printf("Enter number of nodes : ");
    int n;
    scanf("%d", &n);

    struct Node *node, *node1;
    node = creatsll(n);

    printf("Enter position of kth nodes : ");
    int k;
    scanf("%d", &k);

    printf("\nOriginal ");
    display(node);

    node1 = swapnodes(node, k, n);

    printf("\nAfter Swaping Kth nodes ");
    display(node1);
}