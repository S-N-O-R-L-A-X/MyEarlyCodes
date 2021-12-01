#include <iostream>

using namespace std;
bool check[22];
/*
void Permutation_Print(int n,int k,int ans[])
{
    if(k>n)
    {
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(check[i])
        {
            ans[k]=i;
            check[i]=false;
            Permutation_Print(n,k+1,ans);
            check[i]=true;
        }
    }
}*/

unsigned long long Permutation(int n,int m)
{
    //Pnm=n!/m!
    unsigned long long ans=1;
    for(int i=m+1;i<=n;i++)
        ans*=i;
    return ans;
}

void recursion_print(int n,int k,int ans[],int &cnt)
{
    if(cnt>10)
        return ;
    if(k>n)
    {
        cout<<cnt<<':';
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        cnt++;
        return ;
    }

    for(int i=1;i<=n;i++)
    {
        if(check[i])
        {
            ans[k]=i;
            check[i]=false;
            recursion_print(n,k+1,ans,cnt);
            check[i]=true;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int ans[22];
    for(int i=0;i<22;i++)
        check[i]=true;
    int cnt=1;
    recursion_print(n,1,ans,cnt);
//    Permutation_Print(n,1,ans);
    cout<<Permutation(n,1);
    return 0;
}
