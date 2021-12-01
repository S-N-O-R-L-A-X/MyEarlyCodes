#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,j,k,l,m;
    scanf("%d",&n);
        for(j=1;j<=n;j++)/*column control*/
             {
                for(m=2*(n-j);m>0;m--)
                printf(" ");
                for(k=1;k<=j;k++)/*content control*/
                {

                    printf("%d",k);
                    if(k==j)
                        printf("=");
                    else
                        printf("+");
                }
                for(l=j;l>=1;l--)
                    {
                        if(l==j)
                            printf("%d",l);
                        else
                        printf("+%d",l);
                    }
                printf("\n");
             }



    return 0;
}
