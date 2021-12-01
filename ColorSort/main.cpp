#include <iostream>

using namespace std;

int main()
{
    int color[3]={0};
    int x;
    while(cin>>x)
        color[x]++;
    while(color[0])
    {
        cout<<"0 ";
        color[0]--;
    }
    while(color[1])
    {
        cout<<"1 ";
        color[1]--;
    }
    while(color[2])
    {
        cout<<"2 ";
        color[2]--;
    }

    return 0;
}
