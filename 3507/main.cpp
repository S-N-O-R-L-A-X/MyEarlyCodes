#include <iostream>

using namespace std;

int main()
{
    int k,n,p;
    cin>>n>>k>>p;

    int once[k]={0};//stores the money if you buy i+1 ticket(s) once
    for(int i=0;i<k;i++)
    {
        int sum=(i+1)*p;
        int cnt=0;
        cnt+=(sum/100);
        sum%=100;
        cnt+=(sum/50);
        sum%=50;
        cnt+=(sum/20);
        sum%=20;
        cnt+=(sum/10);
        sum%=10;
        cnt+=(sum/5);
        sum%=5;
        cnt+=sum;
        once[i]=cnt;
    }


    /*
    reference:
    the minimum cost of buying x tickets must be from
    the minimum cost of buying y ticket(s) and
    the minimum cost of buying x-y ticket(s) (0<=y<=k,0<=x-y<=k)

    */
    int dp[n+1]={0};
    for(int i=1;i<=n;i++)
        dp[i]=9999999;

    for(int i=1;i<=n;i++)
    {
        if(i<=k)
            dp[i]=once[i-1];
        for(int j=1;i>j&&j<=k;j++)
            dp[i]=min(dp[i],dp[i-j]+once[j-1]);

    }
    cout<<dp[n];


    return 0;
}
