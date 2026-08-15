// 76. Write a program to check whether the given two trees are same or not.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* createTree()
{
    int val;

    printf("Enter data (-1 for NULL): ");
    scanf("%d", &val);

    if (val == -1)
    {
        return NULL;
    }

    struct Node *newNode;

    newNode = createNode(val);

    printf("Enter left child of %d\n", val);
    newNode->left = createTree();

    printf("Enter right child of %d\n", val);
    newNode->right = createTree();

    return newNode;
}

int isSameTree(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    if (root1->data != root2->data)
    {
        return 0;
    }

    return isSameTree(root1->left, root2->left) &&
           isSameTree(root1->right, root2->right);
}

void main()
{
    struct Node *root1;
    struct Node *root2;

    printf("\n---- FIRST TREE ----\n\n");
    root1 = createTree();

    printf("\n---- SECOND TREE ----\n\n");
    root2 = createTree();

    if (isSameTree(root1, root2))
    {
        printf("\nGiven trees are same.\n");
    }
    else
    {
        printf("\nGiven trees are not same.\n");
    }
}