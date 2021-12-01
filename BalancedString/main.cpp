#include <iostream>
#include <string>

using namespace std;


int main()
{
    int n;
    cin>>n;
    cin.get();
    string str;
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        int index=str.find(':',0);
        if(index==string::npos)
            cout<<'N'<<endl;
        else
        {
            string s1(str,0,index);
            string s2(str,index+1);
            if(s1.size()>s2.size())
                cout<<'L'<<endl;
            else if(s1.size()<s2.size())
                cout<<'R'<<endl;
            else
            {
                if(s1.compare(s2)==0)
                    cout<<'S'<<endl;
                else
                    cout<<'D'<<endl;
            }
        }

    }
    return 0;
}
