#include <iostream>
#include <stdio.h>
using namespace std;

#define maxsize 12
char maze[maxsize][maxsize];
bool path[maxsize][maxsize];

int check(int x,int y)
{
    if(maze[x][y]=='W')
        return -1;
    else if(maze[x][y]=='E')
        return 0;
    return 1;
}

void judgeAns(int cnt,int *quick)
{
    if(*quick==-1)
        *quick=cnt;
    else if(*quick>cnt)
        *quick=cnt;
}

bool judgeReturn(int x,int y,int cnt,int *quick)
{
    if(x==-1||y==-1||x==12||y==12||check(x,y)==-1)
        return true;
    else if(check(x,y)==0)
    {
        judgeAns(cnt,quick);
        return true;
    }
    return false;
}

void go(int x,int y,int cnt,int *quick)
{
//    if(x==-1||y==-1||x==12||y==12||check(x,y)==-1)
//        return ;
//    else if(check(x,y)==0)
//    {
//        judgeAns(cnt,quick);
//        return ;
//    }
    if(judgeReturn(x,y,cnt,quick))
        return ;

    if(path[x][y])
    {
        path[x][y]=false;
        go(x-1,y,cnt+1,quick);//left
        path[x][y]=true;
    }
    if(path[x][y])
    {
        path[x][y]=false;
        go(x+1,y,cnt+1,quick);//right
        path[x][y]=true;
    }
    if(path[x][y])
    {
        path[x][y]=false;
        go(x,y-1,cnt+1,quick);//up
        path[x][y]=true;
    }
    if(path[x][y])
    {
        path[x][y]=false;
        go(x,y+1,cnt+1,quick);//down
        path[x][y]=true;
    }
}

void initialize()
{
    for(int i=0;i<maxsize;i++)
    {
        for(int j=0;j<maxsize;j++)
            path[i][j]=true;
    }
}

int main()
{
    for(int i=0;i<maxsize;i++)
    {
        for(int j=0;j<maxsize;j++)
            scanf("%c ",&maze[i][j]);
    }

    int x1,y1,x2,y2,x3,y3;
    scanf("(%d,%d) (%d,%d) (%d,%d)",&x1,&y1,&x2,&y2,&x3,&y3);
    int cnt=1,quick=-1;initialize();
    go(x1,y1,cnt,&quick);
    cout<<quick<<' ';
    cnt=1;quick=-1;initialize();
    go(x2,y2,cnt,&quick);
    cout<<quick<<' ';
    cnt=1;quick=-1;initialize();
    go(x3,y3,cnt,&quick);
    cout<<quick<<' ';
    return 0;
}
