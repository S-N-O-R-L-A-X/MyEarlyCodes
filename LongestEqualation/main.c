#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,cnt,out,temp;
    scanf("%d",&n);
    int data[n];
    cnt=1;out=1;

    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&data[i]);
    }

    for(i=1;i<=n-1;i++)
    {
        if(data[i]==data[i-1])
            {
                cnt=cnt+1;
            }
        else
            {
                cnt=1;
            }
        if(cnt>out)
            {
                out=cnt;
            }

    }
    printf("%d",out);
    return 0;
}
