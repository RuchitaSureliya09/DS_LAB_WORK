// 52. WAP to split a circular linked list into two halves.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first;
struct Node *last;

struct Node *createlist(int n)
{
    first = NULL;
    last = NULL;

    for (int i = 0; i < n; i++)
    {
        struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter new node : ");
        scanf("%d", &Newnode->info);

        if (first == NULL)
        {
            first = Newnode;
            last = Newnode;
            last->link = first;
            continue;
        }
        else
        {
            last->link = Newnode;
            last = Newnode;
            last->link = first;
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
        printf("Circular Liked List : ");

        do
        {
            printf("%d -> ", save->info);
            save = save->link;

        } while (save != first);

        printf("\n");
    }
}

void split(struct Node *first, int n)
{
    if (first == NULL)
    {
        printf("List is Empty !");
        return;
    }

    struct Node *save1, *save2;
    save1 = first;
    save2 = first;

    while (save2->link != first && save2->link->link != first)
    {
        save1 = save1->link;
        save2 = save2->link->link;
    }

    if (save2->link->link == first)
    {
        save2 = save2->link;
    }

    struct Node *node1 = first;
    struct Node *node2 = save1->link;

    save1->link = node1;
    save2->link = node2;

    printf("Split 1 ");
    display(node1);
    printf("Split 2 ");
    display(node2);
}

void main()
{
    printf("Enter number of nodes : ");
    int n;
    scanf("%d", &n);

    struct Node *node;
    node = createlist(n);

    display(node);
    split(node, n);
}