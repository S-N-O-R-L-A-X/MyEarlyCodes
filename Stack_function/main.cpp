#include <iostream>
#define maxsize 100
using namespace std;

class Stack_f
{
public:
    Stack_f()
    {
        arr[maxsize]=0;
        cnt=0;
    }
    void pop();
    int push(const int &y);
    int top();
    int S_size();
    void S_clear();
    bool full();
private:
    int arr[maxsize];
    int cnt;
};


int main()
{
    Stack_f x;
    int a;

    while(cin>>a&&a!=-1)
    {
        x.push(a);
    }
    while(x.S_size()!=0)
    {
        cout<<x.top()<<' ';
        x.pop();
    }

    return 0;
}

void Stack_f::pop()
{
    cnt--;
}

int Stack_f::push(const int &y)
{
    if(full())
        return -1;
    arr[cnt++]=y;
    return 1;
}

int Stack_f::top()
{
    return arr[cnt-1];
}

bool Stack_f::full()
{
    if(cnt==maxsize)
        return true;
    return false;
}

void Stack_f::S_clear()
{
    cnt=0;
}

int Stack_f::S_size()
{
    return cnt;
}
