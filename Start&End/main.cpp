#include <iostream>
#define maxsize 2020
using namespace std;

void binary_search(int num[],int idx,int target)
{
    int left=0,right=idx-1;
    int start,end;

    while(left<=right)
    {
        int mid=(left+right)/2;
        if(num[mid]>=target)
            right=mid-1;
        else
            left=mid+1;
    }
    if(left<=idx&&num[left]==target)
        start=left;
    else
        start=-1;

    left=0;
    right=idx-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(num[mid]<=target)
            left=mid+1;
        else
            right=mid-1;
    }

    if(right>=0&&num[right]==target)
        end=right;
    else
        end=-1;

    cout<<'['<<start<<','<<end<<']';
}

int main()
{
    int target;
    cin>>target;
    int num[maxsize];
    int idx=0,a;
    while(cin>>a&&a!=-1)
        num[idx++]=a;
    binary_search(num,idx,target);
}
