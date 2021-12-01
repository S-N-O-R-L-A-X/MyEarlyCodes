#include <iostream>

using namespace std;

struct question
{
    char c;
    int choice;
    int hand;
};

int pow2minus1(int x)
{
    int ans=1;
    for(int i=1;i<=x;i++)
        ans<<=1;

    return ans-1;
}

int main()
{
    int n;
    cin>>n;
    question q[n];
    int M=0;
    for(int i=0;i<n;i++)
    {
        cin>>q[i].c>>q[i].choice;
        if(q[i].c=='S')
            q[i].hand=q[i].choice;
        else
            q[i].hand=pow2minus1(q[i].choice);
        M=max(q[i].hand,M);
    }
    cout<<M;
    return 0;
}
