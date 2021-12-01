#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 64

void update(int dot[]);
int CountNeighbour(int n,int dot[]);
int judge(int i,int dot[]);
void print(int  dot[]);

int main()
{
    int dot[MAXSIZE]={0};
    int n;
    while(scanf(" %d",&n)&&n!=-1)
        dot[n+1]=1;
    scanf(" %d",&n);
    for(int i=1;i<=n;i++)
        update(dot);
    print(dot);
    return 0;
}

int CountNeighbour(int n,int dot[])
{
    int cnt=0;
    for(int i=n-2;i<=n+2;i++)
        cnt+=dot[i];
    cnt-=dot[n];
    return cnt;
}

int judge(int i,int dot[])
{
    int nb=CountNeighbour(i,dot);
    if(dot[i])
    {
        if(nb==0||nb==1||nb==3)
            return 0;
        return 1;
    }
    if(nb==2||nb==3)
        return 1;
    return 0;
}

void update(int dot[])
{
    int i;
    int copy[MAXSIZE];
    for(i=0;i<MAXSIZE;i++)
        copy[i]=dot[i];
    for(i=2;i<MAXSIZE-2;i++)
        dot[i]=judge(i,copy);
}

void print(int dot[])
{
    for(int i=2;i<MAXSIZE-2;i++)
    {
        if(dot[i])
            printf("*");
        else
            printf("-");
    }
}
