#include <stdio.h>
#include <stdlib.h>

int main()
{
    int date;
    scanf("%d",&date);
    switch(date)
    {
        case 1:
            printf("Monday");
        break;

        case 2:
            printf("Tuesday");
        break;

        case 3:
            printf("Wednesday");
        break;

        case 4:
            printf("Thursday");
        break;

        case 5:
            printf("Friday");
        break;

        case 6:
            printf("Saturday");
        break;

        default:
            printf("Sunday");
        break;
    }

    return 0;
}
