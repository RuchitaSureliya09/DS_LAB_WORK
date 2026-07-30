// 69. You have an array A of integers of size N, an array B (initially empty) and a stack S (initially empty). 
// You are allowed to do the following operations:
// - Take the first element of array A and push it into S and remove it from A.
// - Take the top element from stack S, append it to the end of array B and remove it from S.

// You have to tell if it possible to move all the elements of array A to array B using the above 
// operations such that finally the array B is sorted in ascending order.

// Input Format :
// - First line will contain T, number of testcases. Then the testcases follow.
// - First line of each testcase contains a single integer N.
// - Second line of each testcase contains N distinct integers : A1,A2...AN.

// Output Format :
// For each testcase, if it possible to move all the elements of array A to array B using the above operations such that finally, 
// the array B is sorted in ascending order, print "YES" (without quotes), else print "NO" (without quotes).

#include <stdio.h>
#include <string.h>

int stack[100];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

int peek()
{
    return stack[top];
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main()
{
    int test;

    printf("Enter no. of test : ");
    scanf("%d", &test);

    while (test--)
    {
        top = -1;

        int len;
        printf("Enter length : ");
        scanf("%d", &len);

        int a[100], sorted[100];

        for (int i = 0; i < len; i++)
        {
            printf("Enter num : ");
            scanf("%d",&a[i]);

            sorted[i] = a[i];
        }

        sort(sorted, len);

        int exp = 0;

        for (int i = 0; i < len; i++)
        {
            push(a[i]);

            while (top != -1 && peek() == sorted[exp])
            {
                pop();
                exp++;
            }
            
        }

        if(top == -1)
            printf("YES\n\n");
        else
            printf("NO\n\n");
    }

}