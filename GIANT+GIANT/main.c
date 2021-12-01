#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,j,k,delta,plus,max;

    char a[100],b[100];
    int c[101],d[100],e[100];
    plus=0;
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
    }/*input*/
    for(i=0;i<=99;i++)
    {
        scanf("%c",&b[i]);
        if(b[i]==' '||b[i]=='\n')
            {
                k=i;break;
            }
        e[i]=b[i]-'0';
    }/*input*/
    delta=k-j;
    if(delta>0)
    {
        max=k;
        for(i=99;i>=delta;i--)
        {
            d[i]=d[i-delta];
        }
        for(i=0;i<delta;i++)
        {
            d[i]=0;
        }
    }
    else
       {
           max=j;
        for(i=99;i>=-delta;i--)
        {
            e[i]=e[i+delta];
        }
        for(i=0;i<-delta;i++)
        {
            e[i]=0;
        }
    }/*calculate figure*/
    c[0]=0;
    for(i=max;i>=0;i--)
    {

        c[i+1]=d[i]+e[i]+plus;
        if(c[i+1]>=10)
            {
                c[i]=c[i]+1;
                c[i+1]=c[i+1]-10;
                plus=1;
            }
        else
            plus=0;
    }
    for(i=0;i<=100;i++)
    {
        if(c[0]==0&&i==0)
            i=i;
        else
            {
                if(c[i]>=0)
                    printf("%d",c[i]);
                else
                    break;
            }

    }
    return 0;
}
