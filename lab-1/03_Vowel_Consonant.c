// 3. WAP to determine whether the entered character is vowel or not.

#include <stdio.h>
void main()
{
    char ch;

    printf("Enter any character value : ");
    scanf("%c", &ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        printf("Given character is Vowel");
    else
        printf("Given character is Consonant");
}