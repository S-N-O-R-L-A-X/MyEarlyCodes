#include <iostream>
#define maxsize 1000
using namespace std;

enum Error_code{underflow,overflow,rangeError,success};
typedef int element;

void process(element &x)
{
    cout<<x<<' ';
}

template <typename element>
class MyList
{
public:
    MyList();
    Error_code Insert(int pos,const element &x);
    Error_code Remove(int pos,element &x);
    Error_code Retrieve(int pos) const;
    element easy_retrieve(int pos) const;
    Error_code Replace(int pos,const element &x);
    void Traverse(void (*visit)(element &));
    int Size() const;
    bool Full() const;
    void clear();
protected:
    int cnt;
    element entry[maxsize];
};



int main()
{
    MyList<int> a;
    int x;
    int pos=0;
    while(cin>>x&&x!=-1)
        a.Insert(pos++,x);
    a.Traverse(process);
    return 0;
}

template <typename element>
MyList<element>::MyList()
{
    cnt=0;
}

template <typename element>
void MyList<element>::clear()
{
    cnt=0;
}

template <typename element>
bool MyList<element>::Full() const
{
    return cnt==maxsize-1;
}

template <typename element>
int MyList<element>::Size() const
{
    return cnt;
}

template <typename element>
Error_code MyList<element>::Insert(int pos,const element &x)
{
    if(Full())
        return overflow;
	if(pos<0||pos>cnt)
        return rangeError;
	for(int i=cnt-1;i>=pos;i--)
        entry[i+1]=entry[i];
	entry[pos]=x;
	cnt++;
	return success;
}

template <typename element>
Error_code MyList<element>::Remove(int pos,element &x)
{
    if(cnt==0)
        return underflow;
    if(pos<0||pos>=cnt)
        return rangeError;
//    x=entry[pos];
    for(int i=pos;i<cnt-1;i++)
        entry[i]=entry[i+1];
    cnt--;
    return success;
}

template <typename element>
Error_code MyList<element>::Retrieve(int pos) const
{
    if(pos<0||pos>=cnt)
        return -1;
    return entry[pos];
}

template <typename element>
element MyList<element>::easy_retrieve(int pos) const
{
    return entry[pos];
}

template <typename element>
Error_code MyList<element>::Replace(int pos,const element &x)
{
    if(pos<0||pos>=cnt)
        return rangeError;
    entry[pos]=x;
	return success;
}

template <typename element>
void MyList<element>::Traverse(void (*visit)(element &))
{
    for (int i=0;i<cnt;i++)
           (*visit)(entry[i]);
}
