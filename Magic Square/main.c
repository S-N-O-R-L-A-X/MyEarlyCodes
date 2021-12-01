#include <stdio.h>
#include <stdlib.h>
void print(int n,int square[][n]);
void initialize(int n,int arr[][n]);

int main()
{
    int n;
    scanf("%d",&n);
    int square[n][n];
    int i,j,cnt,flag;
    cnt=1;

    i=1;//now x
    j=n/2-1;//now y
    //initialize(n,square);
    if(n==1)
        printf("1");
    else
    {
        initialize(n,square);
        int l,m;//check x,check y
        while(cnt<=n*n)
        {
            l=i-1;
            m=j+1;
            l=(i-1+n)%n;
            m=(j+1)%n;
            if(square[l][m])
            {
                i=(i+1)%n;
                square[i][j]=cnt;
            }
            else
            {
                i=(i-1+n)%n;
                j=(j+1)%n;
                square[i][j]=cnt;
            }
            cnt++;
        }

        print(n,square);
    }
    return 0;
}



void initialize(int n,int arr[][n])
{
    int l,m;
    for(l=0;l<n;l++)
    {
        for(m=0;m<n;m++)
            arr[l][m]=0;
    }

}

void print(int n,int square[][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",square[i][j]);
            if(j==n-1)
                printf("\n");
            else
                printf("  ");
        }
    }
}
