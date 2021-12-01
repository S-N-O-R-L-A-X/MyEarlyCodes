#include <iostream>
#include <vector>
#define maxsize 300001
using namespace std;

int CountDivided(int n)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            cnt++;
    }
    return cnt;
}


vector<int> num[maxsize];

int main()
{

	int q,n;
	cin>>q>>n;
	int visit[maxsize];
	if(q==1)
        cout<<CountDivided(n);
    else
    {
		int cnt=0;
		for(int i=1;i<n;i++)
        {
			for(int j=1;j*j<=i;j++)
			{
				if(i%j==0)
				{
					num[i].push_back(j);
					if(j*j!=i)
						num[i].push_back(i/j);
				}
			}
		}

		for(int i=0;i<maxsize;i++)
            visit[i]=0;

		for(int a=1;a<=n-1;a++)
		{
			for(int x=1;a*x<=n-1;x++)
			{
				int t=n-a*x;//t=by
				for(int i=0;i<num[t].size();i++)
				{
				    int b=num[t][i];
					if(visit[b]!=a)
					{
						cnt++;
						visit[b]=a;
					}
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}




/*
int PrimeCount(int n)
{
    int cnt=0;
    int prime;
    while(n%2==0)
    {
        cnt++;
        n/=2;
    }
    for(prime=3;prime<=n;prime+=2)
    {
        while(n!=1)
        {
            if(n%prime==0)
            {
                cnt++;
                n=n/prime;
            }
            else
                break;
        }
    }
    return cnt;
}

int CountDivided(int n)
{
    int cnt=0;
    int prime;
    bool flag1=false,flag2=false,flag3=false;
    while(n%2==0)
    {
        cnt++;
        n/=2;
        flag1=true;
    }
    for(prime=3;prime<=n;prime+=2)
    {
        while(n!=1)
        {
            if(n%prime==0)
            {
                cnt++;
                n=n/prime;
                if(flag2)
                    flag3=true;
                else
                    flag2=true;
            }
            else
                break;
        }
    }
    if((flag1&&flag2)||(flag2&&flag3)||(flag1&&flag3))
        return cnt;
    else
        return cnt-1;
}

struct test
{
    int a;
    int b;
};


int Extended_Euclid(int a,int b,int &x,int &y)
{
    if(a==0&&b==0)
        return -1;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int temp=Extended_Euclid(b,a%b,y,x);
    y=y-a/b*x;
    return temp;
}


int main()
{
    int q,n;
    cin>>q>>n;
    int cnt=0;


    if(q==1)
        cout<<CountDivided(n);
    else
    {
        /*
        test *arr=new test[n*(n+1)/2];
        int k=0;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                arr[k].a=i;
                arr[k++].b=j;
            }
        }
        int len=k;
        for(int i=0;i<k;i++)
        {
            int tmpa=arr[i].a,tmpb=arr[i].b;
            for(int x=1;x<=(n-tmpb)/tmpa;x++)
            {
                if((n-tmpa*x)%tmpb==0&&(n-tmpa*x)/tmpb>0)
                {
                    cnt++;
                    break;
                }
            }
        }
        for(int a=1;a<=n-1;a++)
        {
            for(int b=1;b<=n-a;b++)
            {
                int x,y;
                int d=Extended_Euclid(a,b,x,y);
                if(n%d==0)
                {
                    double tmin=-(double)n*x*d/b;
                    double tmax=(double)n*y*d/a;
                    if((int)floor(tmax)-(int)ceil(tmin)>=0)
                        cnt++;
                }
                for(int x=1;x<=(n-b)/a;x++)
                {
                    if((n-a*x)%b==0&&(n-a*x)/b>0)
                    {
                        cnt++;
                        break;
                    }
                }
            }
        }

        cout<<cnt;

    }

    return 0;
}*/
