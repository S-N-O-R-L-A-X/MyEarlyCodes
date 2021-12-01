#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double a[5];
    for(i=0;i<=4;i++)
    {
        scanf("%lf",&a[i]);
        printf("$%.2lf ",a[i]-0.004);
    }
    return 0;
}
