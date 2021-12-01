#include <iostream>
#include <algorithm>

using namespace std;

struct seq
{
    int num;
    int rank;
    int aftersort;
};

bool cmp1(seq q1,seq q2)
{
    if(q1.num!=q2.num)
        return q1.num<q2.num;
    return q1.rank<q2.rank;
}

bool cmp2(seq q1,seq q2)
{
    return q1.rank<q2.rank;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        seq q[m];
        for(int j=0;j<m;j++)
        {
            cin>>q[j].num;
            q[j].rank=j;
        }
        sort(q,q+m,cmp1);
        for(int j=0;j<m;j++)
        {
            q[j].aftersort=j;
        }
        sort(q,q+m,cmp2);
        for(int j=0;j<m;j++)
            cout<<q[j].aftersort<<' ';
        cout<<endl;
    }
    return 0;
}
