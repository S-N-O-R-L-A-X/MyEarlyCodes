
#include <stdio.h>
#include <stdlib.h>
typedef struct _dot
{
    int neighbour;
    int life;//if 1 =>live
}dot;

void print(int n,dot (*point0)[62],dot (*point1)[62]);
void point1Change(int j,int k,dot (*point0)[62],dot (*point1)[62]);
void point0Change(int j,int k,dot (*point0)[62],dot (*point1)[62]);
int countNeighbour(int x,int y,dot (*arr)[62]);


int main()
{
    dot point0[22][62]={0,0};//add a frame
    dot point1[22][62]={0,0};//create a copy and use it in turn
    int x,y,flag,i,j,k,n;
    while(scanf(" %d %d",&x,&y)&&x!=-1&&y!=-1)
        point1[x][y].life=1;

    flag=1;
    scanf(" %d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=20;j++)
        {
            for(k=1;k<=60;k++)
            {
                if(flag)
                {
                    point1[j][k].neighbour=countNeighbour(j,k,point1);
                    point0Change(j,k,point0,point1);
                }
                else
                {
                    point0[j][k].neighbour=countNeighbour(j,k,point0);
                    point1Change(j,k,point0,point1);
                }
            }
        }
        flag=!flag;
    }
	print(n,point0,point1);
    return 0;
}

void point1Change(int j,int k,dot (*point0)[62],dot (*point1)[62])
{
    if(point0[j][k].life==1)
    {
        if(point0[j][k].neighbour<=1||point0[j][k].neighbour>=4)
            point1[j][k].life=0;
        else
            point1[j][k].life=1;
    }
    else
    {
        if(point0[j][k].neighbour==3)
            point1[j][k].life=1;
        else
            point1[j][k].life=0;
    }
}

void point0Change(int j,int k,dot (*point0)[62],dot (*point1)[62])
{
    if(point1[j][k].life==1)
    {
        if(point1[j][k].neighbour<=1||point1[j][k].neighbour>=4)
            point0[j][k].life=0;
        else
            point0[j][k].life=1;
    }
    else
    {
        if(point1[j][k].neighbour==3)
            point0[j][k].life=1;
        else
            point0[j][k].life=0;
    }

}

int countNeighbour(int x,int y,dot (*arr)[62])
{
    int i,j,cnt;
    cnt=0;
    for(i=x-1;i<=x+1;i++)
    {
        for(j=y-1;j<=y+1;j++)
        {
            if(arr[i][j].life&&(!(i==x&&j==y)))
                cnt++;
        }
    }
    return cnt;
}

void print(int n,dot (*point0)[62],dot (*point1)[62])
{
    int j,k;
    if(n%2==0)//change twice or more
    {
        for(j=1;j<=20;j++)
        {
            for(k=1;k<=60;k++)
            {
                if(point1[j][k].life)
                    printf("*");
                else
                    printf("-");
            }
            printf("\n");
        }
    }
    else
    {
        for(j=1;j<=20;j++)
        {
            for(k=1;k<=60;k++)
            {
                if(point0[j][k].life)
                    printf("*");
                else
                    printf("-");
            }
            printf("\n");
        }
    }
}
