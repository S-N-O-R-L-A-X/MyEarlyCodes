#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf(" ");
        for(j=1;j<=i;j++)
            {
            a=i*j;
            printf("%d * %d = ",j,i);
            if(a>=10)
                printf("%d ",a);
            else
                printf(" %d ",a);
            }
        printf("\n");
    }

    return 0;
}
