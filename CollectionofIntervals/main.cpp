#include <iostream>
#include <algorithm>
using namespace std;

struct interval
{
    int left;
    int right;
};

bool cmp(interval a,interval b)
{
    if(a.left!=b.left)
        return a.left<b.left;
    return a.right<b.right;
}

int main()
{
    int n;
    cin>>n;
    interval arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].left>>arr[i].right;
    sort(arr,arr+n,cmp);
    int start=arr[0].left;
    int end=arr[0].right;
    for(int i=0;i<n-1;i++)
    {
        int j=i+1;
        if(arr[j].left<=end)
            end=max(arr[j].right,end);
        else
        {
            cout<<start<<' '<<end<<' ';
            start=arr[j].left;
            end=arr[j].right;
        }
        if(j==n-1)
            cout<<start<<' '<<end<<' ';
    }

    return 0;
}
