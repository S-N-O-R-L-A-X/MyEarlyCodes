#include <bits/stdc++.h>

using namespace std;

vector<int> solve()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>> del(n,{0,n-1});//the numbers can be filled in pos i
    vector<vector<int>> conserve(n,{0,n-1});//the position that the number can be used
    vector<int> ans(n,-1);
    for(int i=0;i<q;i++)
    {
        int l,r,x;
        cin>>l>>r>>x;
        for(int j=l;j<=r;j++)
        {
            if(x>n-1)
                return ans;
            del[j][0]=max(del[j][0],x);
        }
        if(conserve[x][0]>r||conserve[x][1]<l)
            return ans;
        else
        {
            conserve[x][0]=max(conserve[x][0],l);
            conserve[x][1]=min(conserve[x][1],r);
        }
    }

    int cnt=0;
    while(cnt<n)
    {
        bool flag=true;
        for(int i=conserve[cnt][0];i<=conserve[cnt][1];i++)
        {
            if(ans[i]==-1&&del[i][0]<=cnt)
            {
                ans[i]=cnt++;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            vector<int> ret(n,-1);
            return ret;
        }
    }
    return ans;
}

int main()
{
    vector<int> ans=solve();
    for(const int &num:ans)
    {
        cout<<num<<' ';
    }
    return 0;
}
