#include <iostream>

using namespace std;

int main()
{
    int num;
    while(cin>>num)
    {
        if(num==0)
            cout<<"equal"<<endl;
        else if(num>0)
            cout<<"big"<<endl;
        else
            cout<<"small"<<endl;
    }
    return 0;
}
