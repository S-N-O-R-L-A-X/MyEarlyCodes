#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int cnt=0;
    int digit[1000];
    int sum[10]={0};
    int sample[10]={0,1,2,3,4,5,6,7,8,9};

    while (digit[cnt]=getchar())
    {
        if(digit[cnt]>'9'||digit[cnt]<'0')
            break;
        digit[cnt]-='0';
        cnt=cnt+1;
    }
    for(i=0;i<=cnt-1;i++)
    {
        for(j=0;j<=9;j++)
        {
            if(digit[i]==sample[j])
                sum[j]=sum[j]+1;
        }
    }
    for(i=0;i<=9;i++)
    {
        if(sum[i]!=0)
        {
            printf("%d:%d\n",i,sum[i]);
        }
    }
    return 0;
}
