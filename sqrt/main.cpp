#include <iostream>

using namespace std;

int main()
{
    long long x;
    cin>>x;
    long long left=0,right=x;
    if(x==1)
        cout<<'1';
    else
    {
        while(left!=right-1)
        {
            long long mid=(left+right)/2;
            if(mid*mid==x)
            {
                left=mid;
                break;
            }
            else if(mid*mid<x&&mid*mid>=0)
                left=mid;
            else
                right=mid;
        }
        cout<<left;
    }

    return 0;
}
