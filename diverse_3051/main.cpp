#include <iostream>

using namespace std;

int main()
{
    long long dp[51]={0,1,2,4,8};
    for(int i=5;i<51;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout<<"case #"<<i<<':'<<endl<<dp[n]<<endl;
    }

    return 0;
}
