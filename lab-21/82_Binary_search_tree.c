// 82. WAP to find the smallest and largest elements in the Binary Search Tree. 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int info)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int info)
{
    if (root == NULL)
        return createNode(info);

    if (info < root->info)
        root->left = insert(root->left, info);
    else
        root->right = insert(root->right, info);

    return root;
}

int findSmallest(struct Node *root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->info;
}

int findLargest(struct Node *root)
{
    if (root == NULL)
        return -1;

    while (root->right != NULL)
        root = root->right;

    return root->info;
}

void main()
{
    struct Node *root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nSmallest Element: %d", findSmallest(root));
    printf("\nLargest Element: %d", findLargest(root));
}