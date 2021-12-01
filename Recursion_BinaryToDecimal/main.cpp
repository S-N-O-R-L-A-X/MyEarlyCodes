#include <iostream>
#include <stdio.h>

using namespace std;

void BtoD(char *p,long long ans)
{
    if(*p=='\0')
    {
        cout<<ans;
        return ;
    }
    if((*p)-'0'==1)
        return BtoD(p+1,(ans<<1)+1);
    return BtoD(p+1,ans<<1);
}

int main()
{
    char p[21];
    cin.getline(p,'/n');
    long long ans=0;
    BtoD(p,ans);
    return 0;
}
