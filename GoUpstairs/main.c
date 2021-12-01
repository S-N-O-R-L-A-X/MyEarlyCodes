#include <stdio.h>
#include <stdlib.h>

long long comb(int a,int b)
{
int i;
long long int out=1;
    if(b<a-b)
        b=a-b;
    for(i=b+1;i<=a;i++)
        out=out*i;
    for(i=1;i<=a-b;i++)out=out/i;
        return out;
}//组合数

int main()
{
    int n,i,x,k;
    long long s;
    scanf("%d",&n);
    int a[n];
    s=0;
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]-1;
    }
    for(k=0;k<=n-1;k++)
    {
        for(i=a[k]/2;i>=0;i--)
        {
            x=a[k]-2*i;
            if(x>=i)
            {
                s=s+comb(x+i,i);//隔板法求个数
            }
            else
            {
                s=s+comb(i+x,x);
            }
        }
        printf("%ld\n",s);
        s=0;
    }
}
