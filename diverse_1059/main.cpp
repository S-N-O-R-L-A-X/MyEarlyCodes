#include <iostream>
#include <stdio.h>
using namespace std;
struct answer
{
    int q;
    int d;
    int n;
    int p;
    int sum;
};

int main()
{
    int q,d,n,p,c;
    while(cin>>q>>d>>n>>p>>c)
    {
        answer ans={0,0,0,0,11};
        bool flag=true;
        if(q==0&&n==0&&d==0&&p==0&&c==0)
            break;
        int temp=c;
        if(c==0)
        {
            flag=false;
            ans.sum=0;
        }
        for(int i=q;i>=0;i--)
        {
            temp=c-25*i;
            for(int j=d;j>=0&&temp>=0;j--)
            {
                int temp2=temp;
                temp2-=j*10;
                for(int k=n;k>=0&&temp2>=0;k--)
                {
                    int l=temp2-5*k;
                    int s=i+j+k+l;
                    if(l>=0&&l<=p)
                    {
                        flag=false;
                        if(s<ans.sum)
                        {
                            ans.q=i;
                            ans.d=j;
                            ans.n=k;
                            ans.p=l;
                            ans.sum=s;
                        }
                    }
                }
            }
        }
        if(flag)
            printf("Cannot dispense the desired amount.\n");
        else
            printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",ans.q,ans.d,ans.n,ans.p);
    }
    return 0;
}
