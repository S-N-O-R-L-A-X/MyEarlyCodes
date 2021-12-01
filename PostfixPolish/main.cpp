#include <iostream>

using namespace std;

class MyStack
{
public:
    MyStack()
    {
        s[0]=0;
        cnt=0;
        flag=true;
    }
    void pop();
    void push(int x);
    int top();
    void changeFlag();
    bool flagOut();
    int cntOut();
private:
    int s[10];
    int cnt;
    bool flag;
};

bool calculate(MyStack &a);
void calc(int p,int q,char ch,MyStack &a);

int main()
{
    MyStack a;
    if(calculate(a))
    {
        int ans=a.top();
        if(a.top()==-1000000)
            cout<<"none"<<endl;
        else
            cout<<ans<<endl;
    }
    else
        cout<<"none"<<endl;
    return 0;
}

void MyStack::push(int x)
{
    if(cnt==10)
    {
        flag=false;
        return ;
    }
    s[cnt++]=x;
}

void MyStack::pop()
{
     cnt--;
}

int MyStack::top()
{
    if(cnt==0)
    {
        flag=false;
        return -1000000;
    }
    return s[cnt-1];
}

bool MyStack::flagOut()
{
    return flag;
}

bool calculate(MyStack &a)
{
    char ch;
    int p,q;
    while((cin.get(ch))&&ch!='\n')
    {
        if(ch>='0'&&ch<='9')
            a.push(ch-'0');
        else
        {
            p=a.top();
            a.pop();
            q=a.top();
            a.pop();
            calc(p,q,ch,a);
        }
        if(!a.flagOut())
            return false;
    }
    if(a.cntOut()>1)
        return false;
    return true;
}

void MyStack::changeFlag()
{
    flag=false;
}

int MyStack::cntOut()
{
    return cnt;
}

void calc(int p,int q,char ch,MyStack &a)
{
    if(ch=='+')
        a.push(p+q);
    else if(ch=='-')
        a.push(q-p);
    else if(ch=='*')
        a.push(p*q);
    else
    {
        if(p==0)
            a.changeFlag();
        else
            a.push(q/p);
    }
    /*switch(ch)
    {
        case '+':a.push(p+q);break;
        case '-':a.push(q-p);break;
        case '*':a.push(p*q);break;
        default:if(p==0) a.changeFlag();
                else a.push(q/p);break;
    }*/
}
