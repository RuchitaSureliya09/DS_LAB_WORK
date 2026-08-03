// 73. Write a menu driven program to implement following operations on the Doubled Ended Queue using an Array
// - Insert at front end, Insert at rear end
// - Delete from front end, Delete from rear end
// - Display all elements of the queue

#include <stdio.h>
#include <stdlib.h>
#define max 10

int queue[max];
int front = -1, rear = -1;

void insertrear(){
    int ele;

    if (rear == max - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element : ");
    scanf("%d", &ele);

    if (front == -1)
        front = 0;

    queue[++rear] = ele;
}

void insertfront(){
    int ele;

    if (front == 0)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element : ");
    scanf("%d", &ele);

    if (front == -1)
        front = rear = 0;
    else
        front--;

    queue[front] = ele;
    
}

void deletefront(){
    if (front == -1)
    {
        printf("Queue Underflow\n!");
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

void deleterear(){
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Dequeue element : %d\n", queue[rear]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        rear--;
}

void display()
{
    if (front == -1)
    {
        printf("Queue Empty!\n");
        return;
    }

    printf("Queue : ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d  ", queue[i]);
    }
    printf("\n");
}

void main()
{
    int choice;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) Insert at front end\n");
        printf("2) Insert at rear end\n");
        printf("3) Delete from front end\n");
        printf("4) Delete from rear end\n");
        printf("5) Display\n");
        printf("6) Exit\n");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertfront();
            display();
            break;
        case 2:
            insertrear();
            display();
            break;
        case 3:
            deletefront();
            display();
            break;
        case 4:
            deleterear();
            display();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exit!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }

    } while (choice != 6);
}