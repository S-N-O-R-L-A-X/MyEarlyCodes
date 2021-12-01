#include <stdio.h>
#include <stdlib.h>

unsigned int invert(unsigned int xxx, int ppp, int nnn)
{
    return xxx^(~(~0<<nnn)<<(ppp+1-nnn));
}

int main()
{

    unsigned xxx,ppp,nnn;
    scanf("%u %u %u",&xxx,&ppp,&nnn);

    if (nnn>=32)
        printf("%u",xxx);
    else
    {
       unsigned  int output=invert(xxx,ppp,nnn);
       printf("%u",output);
    }



    return 0;
}
