#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    int n,m,tmp;
    cin>>n>>m;
    vector<int> preSum(n+1);
    vector<int> M(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>tmp;
        preSum[i]=preSum[i-1]+tmp;
    }

    for(int i=1;i<=n;i++)
        M[i]=max(M[i-1],preSum[i]);
    int ans=999999999;
    for(int i=m;i<=n;i++)
        ans=min(ans,preSum[i]-M[i-m]);
    */
    vector<int> v{1,2,5,2,9,4};
    cout<<max({1,2,5,2,9,4});
    return 0;
}
