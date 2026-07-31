// 70. Write a menu driven program to implement following operations on the Queue using an Array
// - ENQUEUE
// - DEQUEUE
// - DISPLAY

#include <stdio.h>
#include <stdlib.h>
#define max 10

int queue[max];
int front = -1, rear = -1;

void enqueue()
{
    int ele;

    if (rear == max - 1)
    {
        printf("Queue Overflow!");
        return;
    }

    printf("Enter element : ");
    scanf("%d", &ele);

    if (front == -1)
        front = 0;

    queue[++rear] = ele;
}

void dequeue()
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
    else
        front++;
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue Empty!");
        return;
    }

    printf("\nQueue : ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d  ", queue[i]);
    }
}

void main()
{
    int choice;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) ENQUEUE\n");
        printf("2) DEQUEUE\n");
        printf("3) DISPLAY\n");
        printf("4) EXIT\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            display();
            break;
        case 2:
            dequeue();
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