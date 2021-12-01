#include <stdio.h>
#include <stdlib.h>

unsigned int getbits(unsigned int x,int p,int n)
{
      return (x >> (p+1-n))&~(~0 <<n);
}
int main()
{
    unsigned x,p,n;
    scanf("%u %u %u",&x,&p,&n);
    if(1<=n<=31)
    {
        unsigned output=getbits(x,p,n);
        printf("%u",output);

    }
    else
        printf("0");
    return 0;
}
