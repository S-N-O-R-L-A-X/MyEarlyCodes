#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double data[100],s;
    int i;
    s=0.0000;
    for(i=0;i<=99;i++)
    {
        data[i]=1.0/(2*(i+1)*(2*(i+1)+1)*(2*(i+1)+2));
        s=pow(-1.0,i)*data[i]+s;
    }
    printf("%.4lf",s*4+3);

    return 0;
}
