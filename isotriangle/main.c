#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<=(n-1)/2;++i)
    {
        if(i==(n-1)/2)
            {
                for(j=1;j<=n;++j)
                    {
                        if(j>=1&&j<=n)
                        printf("*");

                    }
            }
        else
            {
                for(j=1;j<=n;++j)
                {
                if((n+1)/2-i==j||j==(n+1)/2+i)
                    printf("*");
                else
                    printf(" ");
                }
                printf("\n");
            }
    }


    return 0;
}
