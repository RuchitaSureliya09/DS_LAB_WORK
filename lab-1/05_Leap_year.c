// 5. WAP to check for the leap year.

#include <stdio.h>
void main()
{
    int year;

    printf("Enter any year : ");
    scanf("%d", &year);

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        printf("Given year is Leap year");
    else
        printf("Given year is not Leap year");
}