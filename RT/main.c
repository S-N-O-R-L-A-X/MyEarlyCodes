#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for (i=1;i<=n;++i)
    {       if(i==n)
                {
                  for(j=1;j<=n;++j)
                    printf("*");
                }
            else
            {
                for(j=1;j<=n;++j)
                {
                    if(i==j||j==1)
                        printf("*");
                    else
                        printf(" ");

                }
                printf("\n");
            }


    }

    return 0;
}
