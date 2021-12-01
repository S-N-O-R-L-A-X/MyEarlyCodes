#include <iostream>
#define inf 10000
using namespace std;

void dfs()
{
    if()
}

int main()
{
    int n;
    vector<vector<int>> m(n,vector<int>(n));
    vector<int> vertex(n,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                m[i][j]=0;
            else
                m[i][j]=inf;
        }

    }
    vector<int> edge(n-1);
    for(int i=0;i<n-1;i++)
    {
        int x,y,r;
        cin>>x>>y>>r;
        vector[i]={x,y};
        m[x][y]=m[y][x]=r;
    }
    int q;
    //所有点之间只有一条路可以走
    for(int i=0;i<q;i++)
    {
        vector<int> seq(n);
        vector<int> dis(n);
        vector<bool> visit(n);
        int ret=0;
        for(int j=0;j<n;j++)
            cin>>seq[j];

    }

    return 0;
}
