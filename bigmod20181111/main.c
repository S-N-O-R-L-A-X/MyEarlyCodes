#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long x;
    int n,i;
    x=1;s=0;cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        x=x*i;
        x=x%20181111;
    }
    printf("%lld",x);
    return 0;
}
