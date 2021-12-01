#include <iostream>
#include <string>

using namespace std;


void Insertion_Sort(string arr[],int len)
{
    int pos;
    string cur;
    for(int i=1;i<len;i++)
    {
        if(arr[i]+arr[i-1]>arr[i-1]+arr[i])
        {
            pos=i;
            cur=arr[i];
            while(pos>0&&arr[pos-1]+cur<cur+arr[pos-1])
            {
                arr[pos]=arr[pos-1];
                pos--;
            }
            arr[pos]=cur;
        }
    }
}

int main()
{
    int i=0;
    string arr[1000];
    while(cin>>arr[i])
        i++;

    Insertion_Sort(arr,i);
    for(int j=0;j<i;j++)
        cout<<arr[j];
    return 0;
}
