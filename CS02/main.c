#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int div16(int x)
{
    int bias =(x>>31)&0xF;
    printf("%d",(x+bias)>>4);
}
/*
2.77
{
    k=17:x<<4+x
    k=-7:-x<<3+x
    k=60:x<<6-x<<2
    k=-112:-x<<7+x<<4
}

2.82
{

}
*/

void A()
{
    if((INT_MIN<0)==(-INT_MIN>0))
        printf("shit");
    else
        printf("fuck");
}

void E()
{
    if(((-3,221,225,472)>>2<<2)<=-3,221,225,472)
        printf("shit");
    else
        printf("fuck");
}

int main()
{
//    int x;scanf("%d",&x);
    int x=-1610612736;
    int y=x>>2;
    int z=y<<2;

    if(z<=x)
        printf("shit");
    else
        printf("fuck");

    printf("%lf",0.0/0.0);
//    printf("%d  %u",0-1,0-1);
//    printf("\n%d  %u",(unsigned)0-1,(unsigned)0-1);
    return 0;
}
