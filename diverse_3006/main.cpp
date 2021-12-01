#include <iostream>
#define mod 1000000007
using namespace std;

long long fact[1000001]={1,1};

//C(n,m)%p=C(n/p,m/p)*C(n%p,m%p)%p
long long Extended_Euclid(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0)
        return -1;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long temp=Extended_Euclid(b,a%b,y,x);
    y-=a/b*x;
    return temp;
}

long long Inverse_Element(long long a,long long p)
{
    long long x,y;
    long long d=Extended_Euclid(a,p,x,y);
    if(d==1)//relatively prime
        return(x%p+p)%p;
    else//no inverse element
        return -1;
}

void factorialMod()
{
    for(int i=2;i<1000001;i++)
        fact[i]=fact[i-1]*i%mod;
}

long long combinationMod(long long n,long long m)
{
    return n<m?0:fact[n]*Inverse_Element(fact[m],mod)%mod*Inverse_Element(fact[n-m],mod)%mod;
}

long long lucas(long long n,long long m)
{
    return m==0?1:lucas(n/mod,m/mod)*combinationMod(n%mod,m%mod)%mod;
}

/*
note:right but too slow
long long factorialMod(long long n)
{
    long long ans=1;
    for(int i=2;i<=n;i++)
        ans=ans*i%mod;
    return ans;
}


long long combinationMod(long long n,long long m)
{
    return n<m?0:factorialMod(n)%mod*Inverse_Element(factorialMod(m),mod)%mod*Inverse_Element(factorialMod(n-m),mod)%mod;
}

long long lucas(long long n,long long m)
{
    return m==0?1:lucas(n/mod,m/mod)*combinationMod(n%mod,m%mod)%mod;
}
*/

/*
too slow
long long llpow(int a,int k)
{
    long long ans=1;
    if(a==0)
        return 0;
    for(int i=1;i<=k;i++)
        ans=ans*a%mod;
    return ans;
}
*/
/*
reference:
a^k=a^(sum(pi*2^i))(pi=0or1)(i>=0)

e.g.
a^21=a^(1*2^0+1*2^2+1*2^4)
    =a^1*a^4*a^16
*/
long long llpow(long long a,long long k)
{
    if(a==0)
        return 0;
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*a%mod;
        a=(a*a)%mod;//a=a^i%mod
        k>>=1;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    factorialMod();
    for(int i=0;i<t;i++)
    {
        int a,b,k,n,m;
        cin>>a>>b>>k>>n>>m;
        cout<<"case #"<<i<<':'<<endl;
        cout<<lucas(k,n)*llpow(a,n)%mod*llpow(b,m)%mod<<endl;
    }
    return 0;
}
