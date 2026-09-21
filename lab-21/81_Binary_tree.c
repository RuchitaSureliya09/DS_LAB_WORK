// 81. Write a program to construct a binary tree from given Postorder and Preorder traversal sequence.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char info;
    struct Node *left;
    struct Node *right;
};

struct Node *createnode(char info)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->info = info;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int search(char post[], int start, int end, char value)
{
    int i;

    for (i = start; i <= end; i++)
    {
        if (post[i] == value)
            return i;
    }

    return -1;
}

struct Node *tree(char pre[], char post[], int *preIndex, int postStart, int postEnd, int n)
{
    struct Node *root;
    int index;

    if (*preIndex >= n || postStart > postEnd)
        return NULL;

    root = createnode(pre[*preIndex]);
    (*preIndex)++;

    if (postStart == postEnd)
        return root;

    index = search(post, postStart, postEnd, pre[*preIndex]);

    if (index != -1)
    {
        root->left = tree(pre, post, preIndex, postStart, index, n);

        root->right = tree(pre, post, preIndex, index + 1, postEnd - 1, n);
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c ", root->info);
    inorder(root->right);
}

void main()
{
    char pre[50], post[50];
    int n, preIndex = 0;
    struct Node *root;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter Preorder traversal: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &pre[i]);
    }

    printf("Enter Postorder traversal: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &post[i]);
    }

    root = tree(pre, post, &preIndex, 0, n - 1, n);

    printf("\nInorder Traversal: ");
    inorder(root);
}