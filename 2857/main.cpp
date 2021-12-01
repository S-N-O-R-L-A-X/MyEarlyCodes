#include <iostream>
#include <string>
using namespace std;

int min_of_3int(int a,int b,int c)
{
    int ans=min(a,b);
    ans=min(ans,c);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        string c=" ";
        c.append(a);
        string d=" ";
        d.append(b);
        int n=c.size();
        int m=d.size();
        int edit[n][m]={0};

        for(int j=0;j<n;j++)//initialize column 0
            edit[j][0]=j;

        for(int k=1;k<m;k++)
            edit[0][k]=k;//initialize row 0

        for(int j=1;j<n;j++)
        {
            for(int k=1;k<m;k++)
            {
                edit[j][k]=min_of_3int(edit[j-1][k]+1,edit[j][k-1]+1,edit[j-1][k-1]+(c[j]==d[k]?0:1));
            }
        }
        cout<<edit[n-1][m-1]<<endl;
    }
    return 0;
}
