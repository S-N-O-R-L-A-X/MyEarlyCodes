#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,j,k,temp;

    char a[100],b[100];
    int c[101],d[100],e[100];
    for(i=0;i<=99;i++)
    {
        a[i]='a';
        b[i]='b';
        d[i]=-1;
        e[i]=-1;
    }/*initialize*/
    for(i=0;i<=99;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]==' '||a[i]=='\n')
            {
                j=i;break;
            }
        d[i]=a[i]-'0';

    }
    for(i=0;i<=99;i++)
    {
        scanf("%c",&b[i]);
        if(b[i]==' '||b[i]=='\n')
            {
                k=i;break;
            }
        e[i]=b[i]-'0';
    }
    for(i=0;i<=j-1;i++)
    {
        temp=d[i];
        d[i]=d[1+j-i];
        d[1+j-i]=temp;
    }
    for(i=0;i<=k-1;i++)
    {
        temp=e[i];
        e[i]=e[1+k-i];
        e[1+k-i]=temp;
    }

    if(j<k)
    {
        for(i=0;i<=j;i++)
        {
            c[i]=d[i]+e[i];
        }
        for(i=0)
    }
    else
    {
        for(i=0;i<=k-1;i++)
        {
            c[i]=d[i]+e[i];
        }
        for(i=k;i<=j;i++)
        {
            c[i]=d[i];
        }
    }

    return 0;
}
