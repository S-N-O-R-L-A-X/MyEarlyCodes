#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num,sum,average;
    int n;
    for(n=1;n<=5;++n)
    {
        scanf("%lf",&num);
        sum=sum+num;
    }
        average=sum/5;

    printf("%.1lf",average);

    return 0;
}
