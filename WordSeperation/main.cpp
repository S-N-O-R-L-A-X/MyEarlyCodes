#include <iostream>
#include <string>
using namespace std;

struct group
{
    bool alphabet[26];
    string str[100];
    int alphaCnt;
    int stringCnt;
    group();
};

int CountAlpha(string a)
{
    int alphabet[26]={0};
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(alphabet[a[i]-'a']==0)
        {
            cnt++;
            alphabet[a[i]-'a']=1;
        }
    }
    return cnt;
}

bool cmp(string a,const group p)
{
    if(CountAlpha(a)!=p.alphaCnt)
        return false;
    for(int i=0;i<a.size();i++)
    {
        if(!p.alphabet[a[i]-'a'])
            return false;
    }
    return true;
}

int index(string a,group p[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(cmp(a,p[i]))
            return i;
    }
    return -1;
}

void add(group *p,string a)
{
    p->alphaCnt=CountAlpha(a);
    for(int i=0;i<a.size();i++)
    {
        if(p->alphabet[a[i]-'a']==0)
            p->alphabet[a[i]-'a']=true;
    }
    p->str[(p->stringCnt)++]=a;
}

void print(const group arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i].stringCnt;j++)
            cout<<arr[i].str[j]<<' ';
        cout<<endl;
    }
}

int main()
{
    string a;
    int cnt=0;
    group arr[100];
    while(cin>>a)
    {
        int idx=index(a,arr,cnt);
        if(idx==-1)//not found
        {
            add(&arr[cnt],a);//add
            cnt++;
        }
        else
        {
            arr[idx].str[arr[idx].stringCnt]=a;
            arr[idx].stringCnt++;
        }
    }
    cout<<cnt<<endl;
    print(arr,cnt);
    return 0;
}

group::group()
{
    alphaCnt=0;
    for(int i=0;i<26;i++)
        alphabet[i]=false;
    stringCnt=0;
}
