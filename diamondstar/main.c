#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,i,j,k,l;
    scanf(" %d",&n);
    for(l=1;l<=n;l++)
    {
        scanf(" %d",&a);
        for(i=1;i<=a;i++)
        {
            for(j=1;j<=2*(a-i);j++)
            {
                printf(" ");
            }
            for(k=1;k<=2*i-1;k++)
            {
                printf("* ");
                if(k==2*i-1)
                    printf("\n");
            }
        }
        for(i=a-1;i>=1;i--)
        {
            for(j=2*(a-i);j>=1;j--)
            {
                printf(" ");
            }
            for(k=2*i-1;k>=1;k--)
            {
                printf("* ");
                if(k==1)
                    printf("\n");
            }
        }
    }


    return 0;
}
