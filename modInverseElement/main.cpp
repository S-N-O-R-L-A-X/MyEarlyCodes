#include <iostream>

using namespace std;


/*ax+by=gcd(a,b)*/
long long Extended_Euclid(long long a,long long b,long long *x,long long *y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    else
    {
        long long ans=Extended_Euclid(b,a%b,x,y);
        long long temp=*x;
        *x=*y;
        *y=temp-a/b*(*y) ;
        return ans;
    }
}

long long Extended_Euclid2(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0)
        return -1;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long temp=Extended_Euclid2(b,a%b,y,x);
    y-=a/b*x;
    return temp;
}


long long Inverse_Element(long long a,long long p)
{
    long long x,y;
    long long d=Extended_Euclid(a,p,&x,&y);
    if(d==1)
        return(x%p+p)%p;
    else
        return -1;
}


//a<p
long long inv2(long long a,long long p)
{
    if(a==1)
        return 1;
    return inv(p%a,p)*(p-p/a)%p;
}



int main()
{
//    int a,b,x,y;
//    cin>>a>>b;
//    int ans=Extended_Euclid(a,b,&x,&y);
//    cout<<ans<<endl<<x<<endl<<y<<endl;
//    cout << "Hello world!" << endl;
    int a,p;
    cin>>a>>p;
    cout<<inv(a,p);
    return 0;
}
