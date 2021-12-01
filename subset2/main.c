#include <stdio.h>
#include <stdlib.h>
/*
3:

{}
{0}
{1}
{0,1}
{2}
{0,2}
{1,2}
{0,1,2}

observe the example,
assume that input is 1,no input is 0;
you can find that the output is a serial number of 0-7

*/

int main()
{
    int i,j,k,cmp,n,a,temp;
    char str[100];
    scanf("%d",&n);
    a=1<<n;
    for(i=0;i<=a-1;i++)//control round
    {
        k=0;
        printf("{");
        for(j=0;j<=n;j++)//control switch
        {
            cmp=1<<j;
            temp=i&cmp;
            if(temp>0)
            {
                str[k]=j+'0';
                k++;
                str[k]=',';
                k++;
            }
        }
        if(k>=1)
        {
            str[k-1]='\0';
            printf("%s",str);
        }

        printf("}\n");
    }
}
/*
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    n=1<<n;//there are 2^n subsets
    for(i=0;i<n;i++)//i controls every print
    {
        printf("{");
        j=i;
        k=0;
        while (j!=0)
        {
            if(j%2)
            {
                printf("%d",k);
                if(j>1)
                    printf(",");
            }
            k++;
            j/=2;
        }

        printf("}\n");
    }
    return 0;
}
*/
