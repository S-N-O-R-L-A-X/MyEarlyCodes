#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double ddd,ppp,rrr;
    float mmm;
    scanf("%lf %lf %lf",&ddd,&ppp,&rrr);
    if (fabs(rrr - 0) < 1e-5)
        printf("0");
    else
    {
        rrr/=100;
        if(fabs(ddd - 0) < 1e-5|| fabs(ppp - 0 ) < 1e-5)
            printf("0");
        else
        {
            mmm=log(ppp/(ppp-ddd*rrr))/log(1+rrr);
            printf("%.0f",mmm);
        }

    }
    return 0;
}
