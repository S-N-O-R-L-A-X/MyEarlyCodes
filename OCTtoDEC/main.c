#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int OCTtoDEC(int a)
{
    int i,n,x,r,b,d,c,f;
    d=0;
    n=0;
    f=a;
    while(a>0)
    {
        a=a/10;
        n=n+1;

    }
    for(i=1;i<=n;i++)
        {
            b=(int)(pow(10.0,i)+0.5);
            c=(int)(pow(10.0,i-1)+0.5);
            x=f%b/c;
            r=(int)(x*pow(8.0,i-1)+0.5);
            d=d+r;
        }
    printf("%d",d);
}

int main()
{
    int num;
    scanf("%d",&num);
    OCTtoDEC(num);
    return 0;
}
