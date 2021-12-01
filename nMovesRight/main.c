#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long num1,num2,num3,num4,s;
    int m,n,a,j,i,l;


    num3=1;
    s=0;
    n=0;
    scanf("%lld %d",&num1,&m);
    num2=num1;
    while(num2>0)
    {
        num2=num2/10;
        n=n+1;
    }

    if(m>=n)
        m=m%n;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            {
                num3=num3*10;

            }
        for(l=1;l<=i-1;l++)
            num4=num4*10;

        a=num1%num3/num4;

            if(i-m>0)
            {
                s=s+a*pow(10,(i-m-1));
            }
            else
            {
                s=s+a*pow(10,(n+i-m-1));
            }
            num3=1;
            num4=1;
    }
    printf("%d %lld",n,s);
    return 0;
}
