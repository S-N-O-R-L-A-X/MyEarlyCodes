#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long num1,num2,s;
    int m,n,i,a;


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
        a=num1%(long long)(pow(10.0,i)+0.5)/(long long)(pow(10.0,i-1)+0.5);

            if(i-m>0)
            {
                s=s+a*(long long)(pow(10.0,(i-m-1))+0.5);
            }
            else
            {
                s=s+a*(long long)(pow(10.0,(n+i-m-1))+0.5);
            }

    }
    printf("%d %lld",n,s);
    return 0;
}
