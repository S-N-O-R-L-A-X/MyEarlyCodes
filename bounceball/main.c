#include <stdio.h>
#include <stdlib.h>

int main()
{
    double dis,hei;
    int n;

    hei=100;
    dis=100;

    for(n=2;n<=10;++n)
        {
            hei=0.5*hei;
            dis=dis+hei*2;

        }



        hei=hei/2;

    printf("%.3lf %.3lf",dis,hei);
    return 0;
}
