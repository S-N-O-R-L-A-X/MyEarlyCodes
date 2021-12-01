#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double s,a,b,c;
    a=1.0;
    b=2.0;
    s=0.00;
    for(i=1;i<=50;i++)
    {
        s=s+b/a;
        c=a;
        a=b;
        b=c+b;

    }
    printf("%.2lf",s);
    return 0;
}
