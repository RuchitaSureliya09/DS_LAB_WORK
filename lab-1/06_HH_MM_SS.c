// 6. WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
// [e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)].

#include <stdio.h>
void main()
{
    int sec;

    printf("Enter total seconds :");
    scanf("%d", &sec);

    int hour = sec / 3600;
    int min = (sec % 3600) / 60;
    int sec1 = (sec % 3600) % 60;

    printf("Hour : %d\n", hour);
    printf("Minute : %d\n", min);
    printf("Second : %d", sec1);
}