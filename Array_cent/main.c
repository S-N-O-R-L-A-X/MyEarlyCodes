#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float amounts[5];
    long dollars[5],cents[5];
    int i;

    for(i=0;i<=4;i++)
    {
        scanf("%f",&amounts[i]);
        dollars[i]=amounts[i];
        cents[i]=100*(amounts[i]-dollars[i]+0.005);

        printf("$%ld.%ld ",dollars[i],cents[i]);
    }


    return 0;
}
