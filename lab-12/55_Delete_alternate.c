// 55. WAP to delete alternate nodes of a doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *first;
struct Node *last;

struct Node *createlist(struct Node *first, int n)
{
    first = NULL;
    last = NULL;

    for (int i = 1; i <= n; i++)
    {
        struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter new node : ");
        scanf("%d", &Newnode->info);

        Newnode->lptr = NULL;
        Newnode->rptr = NULL;

        if (first == NULL)
        {
            first = Newnode;
            last = Newnode;
            continue;
        }

        last->rptr = Newnode;
        Newnode->lptr = last;
        Newnode->rptr = NULL;
        last = Newnode;
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

    printf("Doubly Liked List : ");

    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->rptr;

        if (save != NULL)
            printf("<-> ");
    }

    printf("\n");
}

void deleteAlternate(int pos)
{
    struct Node *temp;
    struct Node *del;
    int count = 1;

    temp = first;

    while (temp != NULL && count < pos)
    {
        temp = temp->rptr;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return;
    }

    while (temp != NULL)
    {
        del = temp;
        temp = temp->rptr;

        if (del->lptr != NULL)
            del->lptr->rptr = del->rptr;
        else
            first = del->rptr;


        if (del->rptr != NULL)
            del->rptr->lptr = del->lptr;
        else
            last = del->lptr;

        free(del);


        if (temp != NULL)
            temp = temp->rptr;
    }
}

void main()
{
    int n, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    first = createlist(first,n);

    printf("\nOriginal Doubly Linked List:\n");
    display(first);

    printf("\nEnter starting position for alternate deletion: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        return;
    }
    else
    {
        deleteAlternate(pos);

        printf("\nAfter deleting alternate nodes:\n");
        display(first);
    }
}