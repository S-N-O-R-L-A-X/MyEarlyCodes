#include <iostream>
#include <string>
using namespace std;

int main()
{
    string origin;
    cin>>origin;
    int maxlen=1;
    for(int i=0;i<origin.size();i++)//the beginning
    {
        for(int j=i+1;j<origin.size();j++)
        {
            string tmp(origin,i,j-i);
            if(tmp.find(origin[j])==tmp.npos)
            {
                if(j-i+1>maxlen)
                    maxlen=j-i+1;//include the last
            }
            else
                break;
        }
    }
    cout<<maxlen;
    return 0;
}
