#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

clock_t start1,stop1,start2,stop2,start,stop;
double duration1,duration2,duration;
#define round 1e7

void forprint(int n)
{
    int i;
    for(i=1;i<=n;i++)
        printf("%d\n",i);
}
void recursionprint(int n)
{
    if(n)
    {
        return recursionprint(n-1);
        printf("%d\n",n);
    }

}

double polynomial(int n,double a[],double x)
{
    int i;
    double out=a[0];
    for(i=1;i<=n;i++)
        out+=(a[i]*pow(x,i));
    return out;
}

double qjspolynomial(int n,double a[],double x)
{
    int i;

    double p=a[n];
    for(i=n;i>=1;i--)
        p=a[i-1]+x*p;
    return p;
}



void dtime(double *p)
{
    start=clock();

    stop=clock();
    duration=((double)(stop-start))/CLK_TCK;
    printf("%lf\n",(double)(stop-start));
    printf("%lf",duration);
}

int main()
{


    int n;
//    scanf("%d %d %d",&n);
//    forprint(n);
//    recursionprint(n);
    double a[11];
    for(int i=0;i<=9;i++)
        a[i]=i+(double)i/10;

    double (*p)(int n,double a[],double x);
    p=polynomial;

    //
    start1=clock();
    for(int j=1;j<=round;j++)
        polynomial(10,a,2.0);
    stop1=clock();
    duration1=((double)(stop1-start1))/CLK_TCK/round;
    printf("%lf\n",(double)(stop1-start1));
    printf("%.2e\n",duration1);
    //

    //
    start2=clock();
    for(int j=1;j<=round;j++)
        qjspolynomial(10,a,2.0);
    stop2=clock();
    duration2=((double)(stop2-start2))/CLK_TCK/round;
    printf("%lf\n",(double)(stop2-start2));
    printf("%.2e\n",duration2);
    //
    return 0;
}

