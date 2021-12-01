#include <iostream>
#define maxsize 101
using namespace std;

class square
{
public:
    void print();
    void initialize();
    void put(int i,int j);
    int n;
private:
    int arr[maxsize][maxsize];

    int Xmove(int i);
    int Ymove(int j);
};

int main()
{
    square magic;
    cin>>magic.n;
    int i,j;
    i=1;//now x
    j=magic.n/2-1;//now y
    //initialize(n,square);
    if(magic.n==1)
        cout<<'1';
    else
    {
        magic.initialize();
        magic.put(i,j);
        magic.print();
    }
    return 0;
}

int square::Xmove(int i)
{
    if(i>n-1)
        return 0;
    else if(i<0)
        return n-1;
    return i;
}

int square::Ymove(int j)
{
    if(j>n-1)
        return 0;
    return j;
}

void square::initialize()
{
    int l,m;
    for(l=0;l<n;l++)
    {
        for(m=0;m<n;m++)
            arr[l][m]=0;
    }

}

void square::put(int i,int j)
{
    int l,m;//check x,check y
    int cnt=1;
    while(cnt<=n*n)
    {
        l=i-1;
        m=j+1;
        l=Xmove(l);
        m=Ymove(m);
        if(arr[l][m])
        {
            i=Xmove(++i);
            arr[i][j]=cnt;
        }
        else
        {
            i=Xmove(--i);
            j=Ymove(++j);
            arr[i][j]=cnt;
        }
        cnt++;
    }

}

void square::print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j];
            if(j==n-1)
                cout<<endl;
            else
                cout<<"  ";
        }
    }
}
