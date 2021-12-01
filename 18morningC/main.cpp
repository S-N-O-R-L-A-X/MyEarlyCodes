#include <iostream>

using namespace std;

int main()
{
    string str;
    cin>>str;
    bool flag=true;
    int i,j;
    for(i=0;i<str.size();)
    {
        string rest(str,i,str.size()-i);
        int pos=rest.find('x');
        if(pos==rest.npos)
            break;
        if(rest[pos-1]!='0')
        {
            i+=(pos+1);
            continue;
        }
        string tmp(rest,pos,rest.size());
        for(j=1;j<tmp.size();j++)
        {
            if((tmp[j]<='9'&&tmp[j]>='0')||(tmp[j]<='f'&&tmp[j]>='a'))
                continue;
            else
                break;
        }
        string ans(tmp,1,j-1);
        i+=(pos+1);
        if(ans.size()==0)
            continue;
        unsigned int out=0;
        for(int j=0;j<ans.size();j++)
        {
            flag=false;
            out*=16;
            if(ans[j]>='a')
                out=out+ans[j]-'a'+10;
            else
                out=out+ans[j]-'0';
        }
        cout<<out<<' ';
    }
    if(flag)
        cout<<"-1";
    return 0;
}
