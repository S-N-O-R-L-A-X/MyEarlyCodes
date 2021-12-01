#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,month;
    scanf("%d %d",&year,&month);
    if ((year%4==0)&&(year%100!=0)||(year%400==0))
    {

        printf("LeapYear ");
            switch(month)
            {
            case 1:
                printf("Winter 31");
            break;
            case 2:
                printf("Winter 29");
            break;
            case 12:
                printf("Winter 31");
            break;
            case 3:
                printf("Spring 31");
            break;
            case 4:
                printf("Spring 30");
            break;
            case 5:
                printf("Spring 31");
            break;
            case 6:
                printf("Summer 30");
            break;
            case 7:
                printf("Summer 31");
            break;
            case 8:
                printf("Summer 31");
            break;
            case 9:
                printf("Autumn 30");
            break;
            case 10:
                printf("Autumn 31");
            break;
            default:
                printf("Autumn 30");
            break;
            }
}
    else
 {
     printf("CommonYear ");
    switch(month)
            {
            case 1:
                printf("Winter 31");
            break;
            case 2:
                printf("Winter 28");
            break;
            case 12:
                printf("Winter 31");
            break;
            case 3:
                printf("Spring 31");
            break;
            case 4:
                printf("Spring 30");
            break;
            case 5:
                printf("Spring 31");
            break;
            case 6:
                printf("Summer 30");
            break;
            case 7:
                printf("Summer 31");
            break;
            case 8:
                printf("Summer 31");
            break;
            case 9:
                printf("Autumn 30");
            break;
            case 10:
                printf("Autumn 31");
            break;
            default:
                printf("Autumn 30");
            break;
            }
 }

    return 0;
}
