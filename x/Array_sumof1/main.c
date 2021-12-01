#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double a[5],b[5],s;
    s=0.000000;
    for(i=0;i<=4;i++)
    {
        scanf("%lf",&a[i]);
    }
    for(i=0;i<=4;i++)
    {
        b[i]=1/a[i];
        printf("%.2lf ",b[i]);
        s=s+b[i];
    }
    printf("\n%.6lf",s);

    return 0;
}
