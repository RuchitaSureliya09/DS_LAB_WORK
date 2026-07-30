// 49. WAP to perform given operation in the linked list. There exist a Linked List. Add a node that contains the GCD of those two nodes between every pair adjacent node of Linked List.
// - Input: 18 → 6 → 10 → 3
// - Output: 18 → 6 → 6 → 2 → 10 → 1 → 3

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

int findgcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Node *addgcd(struct Node *first)
{
    struct Node *newNode, *save;
    newNode = NULL;
    save = first;

    if (first == NULL)
    {
        printf("List is Empty !");
        return NULL;
    }

    while (save != NULL && save->link != NULL)
    {
        int ans = findgcd(save->info, save->link->info);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->info = ans;
        newNode->link = save->link;
        save->link = newNode;

        save = newNode->link;
    }

    return first1;
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

    node1 = addgcd(node);

    printf("\nAfter add GCD ");
    display(node1);
}