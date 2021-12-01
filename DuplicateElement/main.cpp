#include <iostream>
#define maxsize 49999
using namespace std;


int main()
{
    int n,cnt=0;
    cin>>n;
    int arr[maxsize]={0};

    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        int Hash=(tmp+maxsize)%maxsize;
        arr[Hash]++;
        if(arr[Hash]>=2)
        {
            cnt++;
            arr[Hash]=-4361967;
        }
    }

    cout<<cnt;
    return 0;
}
