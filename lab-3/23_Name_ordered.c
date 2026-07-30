// 23. WAP to sort the N names in an alphabetical order.

#include <stdio.h>
#include <string.h>

void main() {
    int n;
    printf("enter n :");
    scanf("%d",&n);

    char name[n][100];

    for (int i = 0; i < n; i++)
    {
        printf("enter name %d : ",i);
        scanf("%s",name[i]);
    }

    char temp[100];

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(strcmp(name[i],name[j]) > 0) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("\nSorted name : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%s\t",name[i]);
    }
}