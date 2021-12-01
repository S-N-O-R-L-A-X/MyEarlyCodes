#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,x,out;

    scanf("%d",&n);
    int a[n];
    int sum=0;
    out=0;
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    for(i=1;i<=n;i++)/*how many plus*/
    {
        for(j=0;j<=n-i;j++)/*start*/
            {
                for(k=j;k<=j+i-1;k++)/*sum  */
                    {
                        sum=a[k]+sum;
                        if(sum>=x)
                            {
                                out=i;break;
                            }
                    }
                if(out!=0)
                    break;
                sum=0;
            }
        if(out!=0)
            break;
    }
    printf("%d",out);



    return 0;
}
