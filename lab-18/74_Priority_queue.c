// 74. WAP to implement Priority Queue.

#include <stdio.h>
#define max 10

struct Queue
{
    int data;
    int priority;
};

struct Queue pq[max];
int n=0;

void insert(){
    if (n == max)
    {
        printf("Priority Queue Overflow!\n");
        return;
    }

    printf("Enter element : ");
    scanf("%d", &pq[n].data);
    printf("Enter priority : ");
    scanf("%d", &pq[n].priority);

    n++;
}

void delete(){
    if (n==0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    int MAX = 0;

    for (int i = 1; i <= n; i++)
    {
        if (pq[i].priority > pq[MAX].priority)
        {
            MAX = i;
        }        
    }

    printf("Deleted Element : %d\n",pq[MAX].data);

    for (int i = MAX; i < n-1; i++)
    {
        pq[i]=pq[i+1];
    }
    n--;
}

void display(){
    if (n==0)
    {
       printf("Priority Queue Empty !\n");
       return;
    }

    printf("\nElement\tPriority\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n" , pq[i].data ,pq[i].priority);
    }
}

void main()
{
    int choice;

    do
    {
        printf("\n-------MENU-------\n");
        printf("1) Insert\n");
        printf("2) Delete highest priority\n");
        printf("3) Display\n");
        printf("4) Exit\n");

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
            display();
            break;
        case 4:
            printf("Exit!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }

    } while (choice != 4);
}