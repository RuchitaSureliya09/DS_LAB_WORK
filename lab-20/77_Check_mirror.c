// 77. Write a program to check whether the given tree is symmetric or not.

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
        return NULL;

    struct Node *newNode;

    newNode = createNode(val);

    printf("Enter left child of %d\n", val);
    newNode->left = createTree();

    printf("Enter right child of %d\n", val);
    newNode->right = createTree();

    return newNode;
}

int isMirrorTree(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    if (root1->data != root2->data)
        return 0;

    return (isMirrorTree(root1->left, root2->right) 
                            &&
            isMirrorTree(root1->right, root2->left));
}

void main()
{
    struct Node *root1;
    struct Node *root2;

    printf("\n---- TREE ----\n\n");
    root1 = createTree();

    if (isMirrorTree(root1->left, root1->right))
        printf("\nGiven trees are Symmetric.\n");
    else
        printf("\nGiven trees are not Symmetric.\n");

}