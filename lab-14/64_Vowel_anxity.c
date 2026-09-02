// 64. Vowel Anxiety Problem
// Utkarsh has recently started taking English-language classes to improve his reading and writing skills. However, he is still struggling to learn English.
// His teacher gave him the following problem to improve his vowel-identification skills:
// There is a string S of length N consisting of lowercase English letters only.
// Utkarsh has to start from the first letter of the string. Each time he encounters a vowel; he has to reverse the entire substring that came before the vowel.
// Utkarsh needs help verifying his answer. Can you print the final string after performing all the operations for him?



#include <stdio.h>
#include <string.h>
#define max 30

int isVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u');
}

void reverse(char str[], int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void main()
{
    int test;
    printf("Enter number of test cases : ");
    scanf("%d", &test);

    while (test--)
    {
        int n;
        char str[max];

        printf("\nEnter length of string : ");
        scanf("%d", &n);
        printf("Enter string : ");
        scanf("%s", str);

        for (int i = 0; i < n; i++)
        {
            if (isVowel(str[i]))
            {
                reverse(str, 0, i - 1);
            }
        }

        printf("Final string : ");
        printf("%s\n", str);
    }
}