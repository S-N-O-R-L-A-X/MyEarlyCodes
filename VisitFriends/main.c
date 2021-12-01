#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long s;
    int n,i,j,k,l,min;
    scanf("%d",&n);
    s=0;
    for(i=1;i<=n;i++)//control round
    {
        scanf("%d",&j);
        int a[j],b[j];
        for(k=0;k<=j-1;k++)//input number
        {
            scanf("%d",&a[k]);
        }
        for(k=0;k<=j-1;k++)
        {
            for(l=0;l<=j-1;l++)
            {
                s=s+abs(a[k]-a[l]);
                if(l==j-1)
                    b[k]=s;
            }
            if(k==0)
                min=0;
            else
            {
                if(b[k]<b[k-1])
                    min=k;
            }
            s=0;
        }
        printf("%d\n",a[min]);
    }

    return 0;
}
