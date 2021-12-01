#include <iostream>
#include <list>
#define maxsize 1000
using namespace std;

enum Error_code{underflow,overflow,rangeError,success};

class record
{
public:
    int order;
    string key;
    string other;
    record();
    record(int x,string a,string b);
};

bool operator ==(const record &x,const record &y);

ostream &operator<<(ostream &output,record a)
{
    output<<a.order<<endl;
    output<<a.key<<' '<<a.other<<endl;
    return output;
}

record::record()
{

}

record::record(int x,string a,string b)
{
    order=x;
    key=a;
    other=b;
}
/*
bool operator==(const record &x,const record &y)
{
    return x.key==y.key;
}

bool operator <(const record &x,const record &y)
{

}*/

/*void process(element &x)
{
    cout<<x<<' ';
}*/

template <typename element>
class MyList
{
public:
    MyList();
    Error_code Insert(int pos,const element &x);
    Error_code Remove(int pos,element &x);
    element Retrieve(int pos) const;
    Error_code Replace(int pos,const element &x);
    void Traverse(void (*visit)(element &));
    int Size() const;
    bool Full() const;
    void clear();
    void binary_search(string target);

protected:
    int cnt;
    element entry[maxsize];
};

/*
template <typename element>
class OrderedList:public MyList<element>
{
public:
	Error_code insert(const element &data);
	Error_code insert(int pos,const element &data);
	Error_code replace(int pos,const element &data);
};


template <typename element>
Error_code OrderedList::insert(const element &data)
{

    for(int i=0;i<Size();i++)
    {
        record tmp;
        tmp=Retrieve(i)
        if(tmp<data)

    }
}
*/

int main()
{
    MyList <record> a;
    string target,buf1,buf2;
    cin>>target;
    int idx=0;
    while(cin>>buf1)
    {
        cin>>buf2;
        record tmp(idx,buf1,buf2);
        a.Insert(idx,tmp);
        idx++;
    }
    a.binary_search(target);

    return 0;
}

template <typename element> MyList<element>::MyList()
{
    cnt=0;
}

template <typename element> void MyList<element>::clear()
{
    cnt=0;
}

template <typename element> bool MyList<element>::Full() const
{
    return cnt==maxsize-1;
}

template <typename element> int MyList<element>::Size() const
{
    return cnt;
}

template <typename element> Error_code MyList<element>::Insert(int pos,const element &x)
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

template <typename element> Error_code MyList<element>::Remove(int pos,element &x)
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

template <typename element> element MyList<element>::Retrieve(int pos) const
{
    /*if(pos<0||pos>=cnt)
        return -1;*/
    return entry[pos];
}

template <typename element> Error_code MyList<element>::Replace(int pos,const element &x)
{
    if(pos<0||pos>=cnt)
        return rangeError;
    entry[pos]=x;
	return success;
}

template <typename element> void MyList<element>::Traverse(void (*visit)(element &))
{
    for (int i=0;i<cnt;i++)
           (*visit)(entry[i]);
}

template <typename element> void MyList<element>::binary_search(string target)
{
    int left=0,right=cnt-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        element x=Retrieve(mid);
        if(x.key==target)
        {
            cout<<x;
            return ;
        }
        if(x.key<target)
            left=mid+1;
        else
            right=mid-1;
    }
    cout<<"-1";
}
