// 75. Write a menu driven program to implement Binary Search Tree (BST) & perform following operations:
// - Insert a node
// - Delete a node
// - Search a node
// - Preorder Traversal
// - Postorder Traversal
// - Inorder Traversal

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

void insert(int val)
{
    struct Node *Newnode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    Newnode->data = val;
    Newnode->left = NULL;
    Newnode->right = NULL;

    if (root == NULL)
    {
        root = Newnode;
        return;
    }

    temp = root;

    while (1)
    {
        if (val < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = Newnode;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
        else if (val > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = Newnode;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            printf("Duplicate value not allowed!");
            free(Newnode);
            return;
        }
    }
}

void delete(int val)
{
    struct Node *temp = root;
    struct Node *parent = NULL;

    while (temp != NULL && temp->data != val)
    {
        parent = temp;

        if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if (parent->left == temp)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }

        free(temp);

        printf("Node deleted successfully.\n");
    }

    else if (temp->left != NULL && temp->right != NULL)
    {
        struct Node *successor = temp->right;
        struct Node *successorParent = temp;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        temp->data = successor->data;

        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }

        free(successor);

        printf("Node deleted successfully.\n");
    }

    else
    {
        struct Node *child;

        if (temp->left != NULL)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }

        if (parent == NULL)
        {
            root = child;
        }
        else if (parent->left == temp)
        {
            parent->left = child;
        }
        else
        {   
            parent->right = child;
        }

        free(temp);
    }
}

void search(int val)
{
    struct Node *temp = root;

    while (temp != NULL)
    {
        if (val == temp->data)
        {
            printf("%d is found", val);
            return;
        }
        else if (val < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    printf("%d is not found!", val);
}

void preorder(struct Node *temp)
{
    if (temp != NULL)
    {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct Node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void inorder(struct Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void main()
{
    int choice;
    int val;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) Insert a node\n");
        printf("2) Delete a node\n");
        printf("3) Search a node\n");
        printf("4) Preorder Traversal\n");
        printf("5) Inorder Traversal\n");
        printf("6) Postorder Traversal\n");
        printf("7) Exit\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value for insert : ");
            scanf("%d", &val);

            insert(val);
            break;
        case 2:
            printf("Enter value for delete : ");
            scanf("%d", &val);

            delete(val);
            break;
        case 3:
            printf("Enter value for search : ");
            scanf("%d", &val);

            search(val);
            break;
        case 4:
            printf("Preorder : ");

            if (root == NULL)
                printf("Tree is empty!");
            else
                preorder(root);

            printf("\n");
            break;
        case 5:
            printf("Inorder : ");

            if (root == NULL)
                printf("Tree is empty!");
            else
                inorder(root);

            printf("\n");
            break;
        case 6:
            printf("Postorder : ");

            if (root == NULL)
                printf("Tree is empty!");
            else
                postorder(root);

            printf("\n");
            break;
        case 7:
            printf("Exit!");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }

    } while (choice != 7);
}
