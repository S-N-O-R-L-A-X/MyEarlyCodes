#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned num;
    int n,a;
    n=0;
    scanf("%u",&num);

    while (num>0)
    {
        a=num&1;
        if  (a==1)
            n=n+1;
        num=num>>1;
    }
    printf("%d",n);
    return 0;
}
