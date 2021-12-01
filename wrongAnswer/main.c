#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long a,b,c;
    int n,i;
    long double d,e;


    scanf("%lld+%lld=%lld",&a,&b,&c);


    for(i=10;i>=-10;i--)
    {
        if(i>=0)
        {
            if (a==0&&b==0)
                {
                    n=0;
                    break;
                }
            else
            {
                d=(long double)(pow(10.0,i));
                e=fabs(a*d+b-c);
                if (e<1E-9)
                {
                    n=i;
                    break;
                }
            }

        }
        else
        {
            d=(long double)(pow(10.0,-i));
            e=fabs(b*d+a-c);
            if (e<1E-9)
            n=i;
        }

    }
        printf("%d",n);
    return 0;
}
