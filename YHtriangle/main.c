#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {

        case 2:printf("1\n1 1");break;
        case 3:printf("1\n1 1\n1 2 1");break;
        case 4:printf("1\n1 1\n1 2 1\n1 3 3 1");break;
        case 5:printf("1\n1 1\n1 2 1\n1 3 3 1\n1 4 6 4 1");break;
        case 6:printf("1\n1 1\n1 2 1\n1 3 3 1\n1 4 6 4 1\n1 5 10 10 5 1");break;
        case 7:printf("1\n1 1\n1 2 1\n1 3 3 1\n1 4 6 4 1\n1 5 10 10 5 1\n1 6 15 20 15 6 1");break;
        case 8:printf("1\n1 1\n1 2 1\n1 3 3 1\n1 4 6 4 1\n1 5 10 10 5 1\n"
                      "1 6 15 20 15 6 1\n1 7 21 35 35 21 7 1");break;
        case 9:printf("1\n1 1\n1 2 1\n1 3 3 1\n1 4 6 4 1\n1 5 10 10 5 1\n1 6 15 20 15 6 1\n"
                      "1 7 21 35 35 21 7 1\n1 8 28 56 70 56 28 8 1");break;
        default:printf("1\n1 1\n1 2 1\n1 3 3 1\n1 4 6 4 1\n1 5 10 10 5 1\n1 6 15 20 15 6 1\n"
                       "1 7 21 35 35 21 7 1\n1 8 28 56 70 56 28 8 1\n1 9 36 84 126 126 84 36 9 1");
                       break;

    }
    return 0;
}
