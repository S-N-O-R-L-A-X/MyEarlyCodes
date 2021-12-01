#include <iostream>

using namespace std;

int main()
{
    int in=0,out=0,cnt=0;
    int y;
    cin>>y;
    for(int i=2001;i<=y;i++)
    {
        if(i%400==0||(i%4==0&&i%100!=0))
        {
            cnt++;
            in+=700;
        }

        out+=140;
    }
    cout<<cnt<<' '<<out<<' '<<in;
    return 0;
}
