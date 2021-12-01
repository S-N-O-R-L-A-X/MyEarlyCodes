#include <iostream>
#include <stdio.h>
#include <cmath>
#define PI 3.14159265359
#define eps 1E-7
using namespace std;

double arr[6];//a,alpha,b,beta,Acnt,gamma

void AngleToAngle()
{
	double t=0;
	for(int i=1;i<6;i+=2)
    {
		if(arr[i]<0)
            continue;
		t+=arr[i];
	}
	for(int i=1;i<6;i+=2)
	{
	    if(arr[i]<0)
            arr[i]=PI-t;
	}
}

double getAngle(double a,double b,double Acnt)
{
	return acos((a*a+b*b-Acnt*Acnt)/(2*a*b));
}

void SideToAngle()
{
	for(int i=1;i<=5;i+=2)
    {
		if(arr[i]<0)
			arr[i]=getAngle(arr[(i+1)%6],arr[(i+3)%6],arr[i-1]);
	}
}

double getSide(double x,double y,double Acnt)
{
	return sqrt(x*x+y*y-2*x*y*cos(Acnt));
}

bool judge()
{
	for(int i=0;i<6;i++)
	{
	    if(arr[i]<0)
			return false;
	}

	if(fabs(arr[1]+arr[3]+arr[5]-PI)>eps)
		return false;//judge the sum of angles<PI

	if(arr[0]+arr[2]<=arr[4]||arr[2]+arr[4]<=arr[0]||arr[0]+arr[4]<=arr[2])
		return false;//judge a+b>Acnt

	for(int i=0;i<4;i+=2)
    {
		if(fabs(arr[i]*sin(arr[i+3])-sin(arr[i+1])*arr[i+2])>eps)
			return false;
	}//judge a/sin(a)=b/sin(b)=Acnt/sin(Acnt)
	return true;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        int known=0,Acnt=0,Scnt=0;
		bool flag=false;
		for(int j=0;j<6;j++)
        {
			cin>>arr[j];
			if(arr[j]>0)
			{
				known++;
				if(j&1)//j%2==1
                    Acnt++;//angles++
				else
                    Scnt++;//sides++
			}
		}

		if(known<3)
        {
			cout<<"Invalid input."<<endl;
			continue;
		}

		while(known<6)
        {
			int T=known;
			if(Acnt==2)
            {
				AngleToAngle();
				known++;
                Acnt=3;
			}

			if(Scnt==3)
            {
				SideToAngle();
				known=known+3-Acnt;
                Acnt=3;
			}
            /*
            it sees arr[0],arr[1](arr[2],arr[3])(arr[4],arr[5]) as a unity

            */
			for(int i=0;i<6;i+=2)
            {
				if(arr[i]>0&&arr[i+1]>0)
				{
					for(int j=0;j<6;j+=2)
					{
						if((arr[j]>0&&arr[j+1]>0)||(arr[j]<0&&arr[j+1]<0))
                            continue;//judge whether have the same signal

						if(arr[j]<0)//not know a side but know the angle
                        {
							arr[j]=arr[i]/sin(arr[i+1])*sin(arr[j+1]);
							known++;
                            Scnt++;
						}
						else
                        {
							if(arr[i+1]<PI/2&&arr[i]<arr[j]&&arr[i]>arr[j]*sin(arr[i+1]))
								flag=true;//judge whether has two solutions
							double tmp=sin(arr[i+1])*arr[j]/arr[i];
							if(tmp>1||tmp<0)
								continue;
							arr[j+1]=asin(sin(arr[i+1])*arr[j]/arr[i]);
							known++;
                            Acnt++;
						}
					}
				}
			}

			if(Scnt==2)
            {
				for(int i=0;i<6;i+=2)
				{
					if(arr[i]<0&&arr[i+1]>0)
                    {
						arr[i]=getSide(arr[(i+2)%6],arr[(i+4)%6],arr[i+1]);
						known++;
						Scnt++;
					}
				}
			}
			if(T==known)
				break;
		}

		if(judge())
        {
			if(flag)
				cout<<"More than one solution."<<endl;
			else
			{
				for(int i=0;i<6;i++)
				    printf("%.6lf%c",arr[i],i==5?'\n':' ');
			}
		}
		else
			cout<<"Invalid input."<<endl;

    }

	return 0;
}

