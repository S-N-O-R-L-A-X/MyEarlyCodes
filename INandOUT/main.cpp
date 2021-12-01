#include <iostream>

using namespace std;

class MyStack
{
public:
    MyStack()
    {
        str[0]='0';
        cnt=0;
        flag=true;
    }
    void push();
    void pop();
    bool flagOut();
private:
    char str[40];
    int cnt;
    bool flag;
};

void judge();


int main()
{
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++)
        judge();

    return 0;
}

void MyStack::push()
{
    if(cnt==40)
        flag=false;
    str[cnt++]='I';
}

void MyStack::pop()
{
    if(cnt==0)
        flag=false;
    cnt--;
}

bool MyStack::flagOut()
{
    return flag;
}

void judge()
{
    MyStack a;
    while(1)
    {
        char ch=cin.get();
        if(ch=='\n')
        {
			if(a.flagOut())
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
            break;

        }
        else
        {
            if(ch=='O')
                a.pop();
            else
                a.push();
        }

    }

}
