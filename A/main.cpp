#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string str;
        cin>>str;
        int cnta=0;
        int cntb=0;
        bool flag=true;//true means alive,false means dead;
        bool flag2=true;
        char former='e';
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='a')
            {
                cnta++;
                if(former=='a')
                    flag2=false;
            }
            else
                cntb++;
            former=str[i];
            if(cnta<cntb)
            {
                cout<<"Dead Fang"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            if(cnta==cntb||flag2)
                cout<<"Happy Fang"<<endl;
            else
                cout<<"Sad Fang"<<endl;
        }

    }
    return 0;
}
