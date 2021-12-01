#include <iostream>
#define max 22;
using namespace std;

//life class declaration
class dot
{
public:
    void initialize();
    void update();
    void print();

private:
    int countNeighbour(int x,int y);
    int grid[22][62];
};


int main()
{
    int n;
    dot life;
    life.initialize();
    cin>>n;

    for(int i=0;i<n;i++){
        life.update();
    }
    life.print();
    return 0;
}

void dot::initialize()
{
    int x,y;
    for(int i=0;i<22;i++)
    {
        for(int j=0;j<62;j++)
            grid[i][j]=0;
    }
    cin>>x>>y;
    while(x!=-1&&y!=-1)
    {
        grid[x][y]=1;
        cin>>x>>y;
    }
}

int dot::countNeighbour(int x,int y)
{
    int i=x-1;
    int j=y-1;
    int cnt=0;
    for(i=x-1;i<=x+1;i++)
    {
        for(j=y-1;j<=y+1;j++)
        {
            if(grid[i][j])
                cnt++;
        }
    }
    cnt-=grid[x][y];
    return cnt;
}

void dot::update()
{
    int i,j;
    int temp[22][62]={0};
    for(i=1;i<21;i++)
    {
        for(j=1;j<61;j++)
        {
            if(countNeighbour(i,j)==2)
                temp[i][j]=grid[i][j];
            else if(countNeighbour(i,j)==3)
                temp[i][j]=1;
            else
                temp[i][j]=0;
        }
    }
    for(i=1;i<21;i++)
    {
        for(j=1;j<61;j++)
            grid[i][j]=temp[i][j];
    }
}

void dot::print()
{
    for(int i=1;i<21;i++)
    {
        for(int j=1;j<61;j++)
        {
            if(grid[i][j])
                cout<<'*';
            else
                cout<<'-';
        }
        cout<<endl;
    }
}
