#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int card[n];
    int total[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            total[i][j]=0;
    }

    for(int i=0;i<n;i++)
        cin>>card[i];

    int no,num,s=0;
    for(int i=0;i<m;i++)
    {
        cin>>no>>num;
        for(int j=0;j<m;j++)
        {
            if(total[no-1][j]==0)
            {
                total[no-1][j]=num;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        sort(total[i],total[i]+m,cmp);
        s=s+total[i][0]*card[i];
    }
    cout<<s;
    return 0;
}
