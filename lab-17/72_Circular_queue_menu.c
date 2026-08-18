// 72. Write a menu driven program to implement following operations on a circular queue using an Array
// - Insert
// - Delete
// - Display all elements of the queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

int queue[max];
int front = -1, rear = -1;

void insert()
{
    int ele;

    if ((front == 0 && rear == max - 1) || (front == rear + 1))
    {
        printf("Queue Overflow!");
        return;
    }

    printf("Enter element : ");
    scanf("%d", &ele);

    if (front == -1)
        front = rear = 0;
    else if (rear == max - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = ele;
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Underflow!");
        return;
    }

    printf("Dequeue element : %d\n", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == max - 1)
        front = 0;
    else
        front++;
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue Empty!\n");
        return;
    }

    printf("Queue : ");
    while (true)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % max;
    }
    printf("\n");
}

void main()
{
    int choice;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) INSERT\n");
        printf("2) DEQUEUE\n");
        printf("3) DISPLAY\n");
        printf("4) EXIT\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            display();
            break;
        case 2:
            delete();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit!");
            break;
        default:
            printf("Invalid choice!");
            break;
        }

    } while (choice != 4);
}