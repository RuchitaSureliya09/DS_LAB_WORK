// 78. Given a binary tree, determine if it is height-balanced (A height-balanced binary tree is a binary tree 
// in which the depth of the two subtrees of every node never differs by more than one).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int val)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *createTree()
{
    int val;

    scanf("%d", &val);

    if (val == -1)
    {
        return NULL;
    }

    struct Node *root = createNode(val);

    printf("Enter left child of %d\n", val);
    root->left = createTree();

    printf("Enter right child of %d\n", val);
    root->right = createTree();

    return root;
}

int height(struct Node *root)
{
    int leftHeight;
    int rightHeight;

    if (root == NULL)
    {
        return 0;
    }

    leftHeight = height(root->left);

    if (leftHeight == -1)
    {
        return -1;
    }

    rightHeight = height(root->right);

    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

void main()
{
    struct Node *root;
    int result;

    printf("Enter tree (-1 for NULL):\n");

    root = createTree();

    result = height(root);

    if (result == -1)
    {
        printf("Output: FALSE\n");
    }
    else
    {
        printf("Output: TRUE\n");
    }
}