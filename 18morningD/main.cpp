#include <iostream>
#include <algorithm>
using namespace std;

struct card
{
    int a;
    int b;
};

bool cmp1(card c1,card c2)
{
    return c1.b<c2.b;
}

bool cmp2(card c1,card c2)
{
    return c1.a<c2.a;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        card arr[n];
        card backup[n];

        for(int j=0;j<n;j++)
        {
            cin>>arr[j].a>>arr[j].b;
//            backup[j].a=arr[j].a;
//            backup[j].b=arr[j].b;
        }

        int j,k=0;
        bool flag=true;
        for(j=0;j<n&&flag;j++)
        {
            for(k=0;k<n&&flag;k++)
            {
                if(j==k)
                    continue;

                if((arr[j].b==arr[k].a)||(arr[j].a==arr[k].a))
                    flag=false;
            }
        }

        /*
        int j,k=0;
        bool flag=true;
        for(j=0;j<n&&flag;j++)
        {
            for(k=0;k<n&&flag;k++)
            {
                if(arr[j].b==backup[k].a)
                    flag=false;
            }
        }
        */
        /*
        sort(arr,arr+n,cmp1);
        sort(backup,backup+n,cmp2);

        for(j=0;j<n&&flag;j++)
        {
            for(;k<n&&flag;k++)
            {
                if(arr[j].b==arr[k].a)
                    flag=false;
                else if(arr[j].b<arr[k].a)
                {
                    if(k-1>=0)
                        k--;
                    else
                        k=0;
                    break;
                }
            }
        }
        */
        if(flag)
            cout<<"Lucky dxw!"<<endl;
        else
            cout<<"Poor dxw!"<<endl;
    }
    return 0;
}
