// 63. Merge Intervals Problem
// Given a set of time intervals in any order, our task is to merge all overlapping intervals into one and 
// output the result which should have only mutually exclusive intervals.

// Sample Example-1:
// Input: Intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}
// Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping intervals here,[1,3] and [2,4]. 
// Therefore we will merge these two and return [1,4],[6,8], [9,10]

// Sample Example-2:
// Input: Intervals = {{6,8},{1,9},{2,4},{4,7}}
// Output: {{1, 9}}


#include <stdio.h>

void main()
{
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int a[n][2];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Interval %d: ", i + 1);
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][0] > a[j][0])
            {
                int temp = a[i][0];
                a[i][0] = a[j][0];
                a[j][0] = temp;

                temp = a[i][1];
                a[i][1] = a[j][1];
                a[j][1] = temp;
            }
        }
    }

    int start = a[0][0];
    int end = a[0][1];

    printf("Output: ");

    for (int i = 1; i < n; i++)
    {
        if (a[i][0] <= end)
        {
            if (a[i][1] > end)
                end = a[i][1];
        }
        else
        {
            printf("{%d, %d} ", start, end);

            start = a[i][0];
            end = a[i][1];
        }
    }

    printf("{%d, %d}", start, end);
}
