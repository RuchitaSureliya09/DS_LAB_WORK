// 7. WAP to convert number of days into year, week & days 
// [e.g. 375 days mean 1 year, 1 week and 3 days].

#include <stdio.h>
void main()
{
    int days;

    printf("Enter total days :");
    scanf("%d", &days);

    int year = days / 365;
    int week = (days % 365) / 7;
    int day = (days % 365) % 7;

    printf("Year : %d\n", year);
    printf("Week : %d\n", week);
    printf("Day : %d", day);
}