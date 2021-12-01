#include <iostream>
#define eps 1E-7
#include <cmath>
using namespace std;

long long llabs(long long x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    double xm=(double)(x1+x2)/2;
    double ym=(double)(y1+y2)/2;
    bool flag=true;
    if(y1==y2)
    {
        double x=(double)(x1+x2)/2;
        if(fabs(x-(long long)x)<eps)
            cout<<x<<' '<<y1;
        else
            cout<<"NO";
    }
    else
    {
        long long ansx,ansy,ansr;
        long long tmp=llabs(y2-y1+xm);
        for(long long x=-tmp;x<=tmp;x++)
        {
            double y=(double)(x1-x2)/(y2-y1)*(x-xm)+ym;
            if(fabs(y-(long long)y)<1E-7)
            {
                if(flag)
                {
                    flag=false;
                    ansx=x;
                    ansy=(long long)y;
                    ansr=llabs(x-x1)+llabs((long long)y-y1);
                }
                else
                {
                    if(llabs(x-x1)+llabs((long long)y-y1)<ansr)
                    {
                        ansx=x;
                        ansy=(long long)y;
                        ansr=llabs(x-x1)+llabs((long long)y-y1);
                    }
                    else if(llabs(x-x1)+llabs((long long)y-y1)==ansr)
                    {
                        if(x<ansx)
                        {
                            ansx=x;
                            ansy=(long long)y;
                            ansr=llabs(x-x1)+llabs((long long)y-y1);
                        }
                        else if(x==ansx&&y<ansy)
                        {
                            ansx=x;
                            ansy=(long long)y;
                            ansr=llabs(x-x1)+llabs((long long)y-y1);
                        }

                    }
                }
            }
        }
        if(flag)
            cout<<"NO";
        else
            cout<<ansx<<' '<<ansy;

    }
    return 0;
}
