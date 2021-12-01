#include <stdio.h>
#include <stdlib.h>

unsigned int getbits(unsigned int xxx,int ppp,int nnn)
{
      return (xxx >> (ppp+1-nnn))&~(~0 <<nnn);
}
int main()
{
    unsigned xxx;
	int	ppp,nnn;
    scanf("%u %d %d",&xxx,&ppp,&nnn);
    if(1<=nnn<=31)
    {
        unsigned int output=getbits(xxx,ppp,nnn);
        printf("%u",output);

    }
    else
        printf("%u",xxx);
    return 0;
}
