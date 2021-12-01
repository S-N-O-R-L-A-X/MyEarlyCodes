#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        int cnt=0;
        for(int m=0;m<a;m++)
        {
            for(int n=0;n<b;n++)
            {
                if((m&n)<k)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
