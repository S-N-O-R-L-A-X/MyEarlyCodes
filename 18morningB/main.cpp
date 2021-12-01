#include <iostream>
#include <algorithm>
using namespace std;

struct alpha
{
    int index;
    int app;
    int score;
    alpha()
    {
        score=0;
        app=0;
    }
};

bool cmp(alpha a1,alpha a2)
{
    return a1.app>a2.app;
}

bool cmp2(alpha a1,alpha a2)
{
    return a1.index<a2.index;
}

int main()
{
    int s=0;
    string origin;
    cin>>origin;
    alpha record[26];
    for(int i=0;i<26;i++)
        record[i].index=i;

    for(int i=0;i<origin.size();i++)
    {
        if(origin[i]>='a')
        {
            int idx=origin[i]-'a';
            record[idx].app++;
            record[idx].index=idx;
        }
        else
        {
            int idx=origin[i]-'A';
            record[idx].app++;
            record[idx].index=idx;
        }
    }
    sort(record,record+26,cmp);

    for(int i=0;i<26;i++)
        record[i].score=26-i;


    sort(record,record+26,cmp2);

    for(int i=0;i<origin.size();i++)
    {
        int idx=(origin[i]>='a'?origin[i]-'a':origin[i]-'A');
        s+=(record[idx].score);
    }
    cout<<s;
    return 0;
}
