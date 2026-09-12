// 53. Write a program to perform addition of two polynomial equations using appropriate data structure.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *link;
};

struct Node *createnode(int coeff, int exp)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->link = NULL;

    return newnode;
}

void insert(struct Node **poly, int coeff, int exp)
{
    struct Node *newnode, *temp;

    newnode = createnode(coeff, exp);

    if (*poly == NULL)
    {
        *poly = newnode;
        return;
    }

    temp = *poly;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = newnode;
}

struct Node *addpolynomial(struct Node *p1, struct Node *p2)
{
    struct Node *finalans = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp == p2->exp)
        {
            if (p1->coeff + p2->coeff != 0)
            {
                insert(&finalans, p1->coeff + p2->coeff, p1->exp);
            }

            p1 = p1->link;
            p2 = p2->link;
        }
        else if (p1->exp > p2->exp)
        {
            insert(&finalans, p1->coeff, p1->exp);
            p1 = p1->link;
        }
        else
        {
            insert(&finalans, p2->coeff, p2->exp);
            p2 = p2->link;
        }
    }

    while (p1 != NULL)
    {
        insert(&finalans, p1->coeff, p1->exp);
        p1 = p1->link;
    }

    while (p2 != NULL)
    {
        insert(&finalans, p2->coeff, p2->exp);
        p2 = p2->link;
    }

    return finalans;
}

void display(struct Node *poly)
{
    int first = 1;

    while (poly != NULL)
    {
        if (poly->coeff != 0)
        {
            if (!first)
            {
                if (poly->coeff > 0)
                    printf("+");
            }

            if (poly->exp == 0)
            {
                printf("%d", poly->coeff);
            }
            else if (poly->exp == 1)
            {
                printf("%dx", poly->coeff);
            }
            else
            {
                printf("%dx^%d", poly->coeff, poly->exp);
            }

            first = 0;
        }

        poly = poly->link;
    }

    printf("\n");
}

void main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *finalans = NULL;

    int n1, n2;
    int coeff, exp;
    int i;

    printf("\nEnter terms of polynomial in decreasing order of exponent:\n");

    printf("\nEnter number of terms in first polynomial: ");
    scanf("%d", &n1);


    for (i = 0; i < n1; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        insert(&poly1, coeff, exp);
    }

    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);

    for (i = 0; i < n2; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);

        insert(&poly2, coeff, exp);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    finalans = addpolynomial(poly1, poly2);

    printf("Addition: ");
    display(finalans);
}