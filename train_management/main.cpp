#include <iostream>
#define maxsize 100
using namespace std;

class Myarr
{
public:
    Myarr();
    bool check();
    bool judge(int x);
    bool initiailize(int x);
private:
    int cnt;
    int arr[maxsize];
};

int main()
{
    int n;
    cin>>n;
    int temp;
    Myarr arrMain;
    Myarr arrAssist;
    for(int step=0;step<n;step++)
    {
        cin>>temp;

        if(arrMain.judge(temp))
            arrMain.initiailize(temp);
        else
            arrAssist.initiailize(temp);
    }
    if(arrAssist.check()&&arrMain.check())
        cout<<n<<" Yes";
    else
        cout<<n<<" No";
    return 0;
}

Myarr::Myarr()
{
    cnt=0;
    arr[0]=0;
}

bool Myarr::check()
{
    for(int i=0;i<cnt-1;i++)
    {
        if(arr[i]>=arr[i+1])
            return false;
    }
    return true;
}

bool Myarr::judge(int x)
{
    if(x>arr[cnt-1]||cnt==0)
        return true;
    return false;
}

bool Myarr::initiailize(int x)
{
	if(cnt==maxsize)
		return false;
    arr[cnt++]=x;
	return true;
}
