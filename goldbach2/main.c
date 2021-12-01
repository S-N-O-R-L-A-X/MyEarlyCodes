#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,j,k;
    scanf("%d",&num);

    printf("%d",num);
    for(i=3;i<=num/2;i=i+2)
    {
        k=num-i;
        for(j=3;j<=k;j=j+2)
        {
            if (j==i)
            {
                if(k==j)
                    printf("=%d+%d",i,k);
                else if(k%j==0)
                    break;
            }
            else if(k==j)
                printf("=%d+%d",i,k);
            else if(i%j==0||k%j==0)
                    break;
            else
                j=j;

        }
    }

    return 0;
}
