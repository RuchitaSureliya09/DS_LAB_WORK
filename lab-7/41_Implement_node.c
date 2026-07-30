// 41. Write a program to implement a node structure for singly linked list. Read the data in a node, print the node.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

void main()
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter new node : ");
    scanf("%d", &Newnode->info);

    Newnode->link = NULL;

    printf("value of new node   : %d\n", Newnode->info);
    printf("link of new node   : %d\n", Newnode->link);

    free(Newnode);
}
