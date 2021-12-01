#include <iostream>
#include <stack>
#define maxsize 2048
using namespace std;

class ArrBinaryTree
{
public:
    ArrBinaryTree();
    void insert(string x);
    void del(int start);
    bool symmetric() const;
    int get_height() const;
private:
    int arr[maxsize];
    int cnt;
    int height;
};

ArrBinaryTree::ArrBinaryTree()
{
    for(int i=0;i<maxsize;i++)
        arr[i]=-999;//-999 means available
    cnt=0;
    height=0;
}

void ArrBinaryTree::insert(string x)
{
    while(arr[cnt]==-1)
        cnt++;
    if(arr[cnt]==-999)
    {
        if(x=="null")
            del(cnt);
        else
        {
            int tmp=atoi(x.c_str());
            arr[cnt]=tmp;
        }
    }
    cnt++;
}

void ArrBinaryTree::del(int start)
{
    int dis=1;
    while(true)
    {
        for(int j=0;j<dis;j++)
        {
            if(start+j>=maxsize)
                return ;
            arr[start+j]=-1;
        }
        dis<<=1;
        start=2*start+1;
    }
}


bool ArrBinaryTree::symmetric() const
{
    int start=0;
    while(start<cnt)
    {
        start++;
        for(int j=0;j<(start+1)/2;j++)
        {
            if(arr[start+j]==-1)
            {
                if(arr[2*start-j]!=-999&&arr[2*start-j]!=-1)
                    return false;
            }
            else if(arr[start+j]!=arr[2*start-j])//different number
               return false;
        }
        start<<=1;
    }
    return true;
}

int ArrBinaryTree::get_height() const
{
    if(cnt==0)
        return -1;
	int tmp=1,k;
	for(k=0;tmp<=cnt;k++)//log2size
        tmp*=2;
	return k-1;
}

int main()
{
    int n;
    cin>>n;
    ArrBinaryTree a;

    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        a.insert(x);
    }
    if(a.symmetric())
        cout<<a.get_height()<<" true";
    else
        cout<<a.get_height()<<" false";
    return 0;

}

/*
test:
10 0 1 1 null 3 3 null null 5 5
3 true
*/
