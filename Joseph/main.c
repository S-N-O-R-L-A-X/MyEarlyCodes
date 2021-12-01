#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j,cnt,step;
    scanf("%d %d",&n,&m);
    cnt=0;step=0;
    int a[n*n*n];
    int b[n],output[n];
    for(i=0;i<=n-1;i++)
    {
        b[i]=i+1;
    }//create the array
    for(i=0;i<=n*n*n-1;i++)
    {
        a[i]=b[i%n];
    }//create a bar like circle
    for(i=0;i<=n*n*n-1;i++)
    {
        if(a[i]!=0)
        {
            step=step+1;
        }//count step
        if(a[i]!=0&&step%m==0)
        {
            output[cnt]=a[i];
            cnt=cnt+1;
            for(j=n*n*n-1;j>=0;j--)
            {
                if(a[j]==a[i])
                    a[j]=0;//eliminate digit
            }
            step=0;
        }
    }
    for(i=0;i<=n-1;i++)
    {
        if(i==n-1)
            printf("Last No is: %d\n",output[i]);
        else
            printf("No%d: %d\n",i+1,output[i]);

    }
}
