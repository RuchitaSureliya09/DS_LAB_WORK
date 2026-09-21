// 83. Write a program to implement phone book dictionary using Binary Search Tree which provides following operations: 
// - Add new entry in phone book,  
// - Remove entry from phone book,  
// - Search phone number  
// - List all entries in asc order of name and 
// - List all entries in desc order of name


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    char phone[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createnode(char name[], char phone[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char name[], char phone[])
{
    if(root == NULL)
        return createnode(name, phone);

    if(strcmp(name, root->name) < 0)
    {
        root->left = insert(root->left, name, phone);
    }
    else if(strcmp(name, root->name) > 0)
    {
        root->right = insert(root->right, name, phone);
    }
    else
    {
        strcpy(root->phone, phone);
    }

    return root;
}

struct Node* search(struct Node *root, char name[])
{
    if(root == NULL)
        return NULL;

    if(strcmp(name, root->name) == 0)
        return root;

    if(strcmp(name, root->name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

struct Node* findMin(struct Node *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

struct Node* deleteNode(struct Node *root, char name[])
{
    struct Node *temp;

    if(root == NULL)
        return NULL;
        

    if(strcmp(name, root->name) < 0)
    {
        root->left = deleteNode(root->left, name);
    }
    else if(strcmp(name, root->name) > 0)
    {
        root->right = deleteNode(root->right, name);
    }
    else
    {
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

void asc(struct Node *root)
{
    if(root != NULL)
    {
        asc(root->left);
        printf("%s : %s\n", root->name, root->phone);
        asc(root->right);
    }
}

void desc(struct Node *root)
{
    if(root != NULL)
    {
        desc(root->right);
        printf("%s : %s\n", root->name, root->phone);
        desc(root->left);
    }
}

void main()
{
    struct Node *root = NULL;
    struct Node *result;

    int choice;
    char name[50], phone[20];

    do
    {
        printf("\n===== PHONE BOOK =====\n");
        printf("1. Add New Entry\n");
        printf("2. Remove Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. Display Asc Order\n");
        printf("5. Display Desc Order\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]", name);

                printf("Enter phone number: ");
                scanf(" %[^\n]", phone);

                root = insert(root, name, phone);

                printf("Entry added successfully!\n");

                break;
            case 2:
                printf("Enter name to remove: ");
                scanf(" %[^\n]", name);

                result = search(root, name);

                if(result == NULL)
                    printf("Entry not found!\n");
                else
                {
                    root = deleteNode(root, name);
                    printf("Entry removed successfully!\n");
                }
                break;
            case 3:
                printf("Enter name to search: ");
                scanf(" %[^\n]", name);

                result = search(root, name);

                if(result == NULL)
                    printf("Entry not found!\n");
                else
                {
                    printf("Name: %s\n", result->name);
                    printf("Phone: %s\n", result->phone);
                }
                break;
            case 4:
                if(root == NULL)
                    printf("Phone book is empty!\n");
                else
                {
                    printf("\nAsc Order:\n");
                    asc(root);
                }
                break;
            case 5:
                if(root == NULL)
                    printf("Phone book is empty!\n");
                else
                {
                    printf("\nDesc Order:\n");
                    desc(root);
                }
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 6);
}