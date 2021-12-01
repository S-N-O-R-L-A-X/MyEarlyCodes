#include <stdio.h>
#include <stdlib.h>

void RunningAvg()
{
    float s,b,a;
    int n;
    n=0;
    while(scanf("%f",&a)&&a+1>1E-9)
    {
        n=n+1;
        s=s+a;
        b=s/n;
        printf("%.2f\n",b);
    }
}


int main()
{
    RunningAvg();
    return 0;
}
