#include <iostream>
#define maxsize 1000
using namespace std;

enum Error_code{underflow,overflow,rangeError,success};
typedef int element;

void process(element &x)
{
    cout<<x<<' ';
}

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
    void InsertionSortOnce(int i);
    void InsertionSort();
    void InsertionSort(int round);
    void clear();
protected:
    int cnt;
    element entry[maxsize];
};



int main()
{
    MyList a;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.Insert(i,x);
    }
    a.InsertionSort(n/2);
    a.Traverse(process);

    a.InsertionSort();
    a.Traverse(process);
    return 0;
}

MyList::MyList()
{
    cnt=0;
}

void MyList::clear()
{
    cnt=0;
}

bool MyList::Full() const
{
    return cnt==maxsize-1;
}

int MyList::Size() const
{
    return cnt;
}

Error_code MyList::Insert(int pos,const element &x)
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

Error_code MyList::Remove(int pos,element &x)
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

element MyList::Retrieve(int pos) const
{
    if(pos<0||pos>=cnt)
        return -1;
    return entry[pos];
}

Error_code MyList::Replace(int pos,const element &x)
{
    if(pos<0||pos>=cnt)
        return rangeError;
    entry[pos]=x;
	return success;
}

void MyList::Traverse(void (*visit)(element &))
{
    for(int i=0;i<cnt;i++)
           (*visit)(entry[i]);
    cout<<endl;
}

void MyList::InsertionSortOnce(int i)//i records the position of first unsorted element
{
    if(entry[i]<entry[i-1])
    {
        int position=i;
        int current=entry[i]; // Pull unsorted entry out of the list.
        while(position>0&&entry[position-1]>current)
        {   // Shift right all entries until the proper position is found.
            entry[position]=entry[position-1];
            position--;
        }
        entry[position]=current;
    }
}

void MyList::InsertionSort()
{
    for(int i=1;i<cnt;i++)//i records the position of first unsorted element
        InsertionSortOnce(i);
}

void MyList::InsertionSort(int round)
{
    for(int i=1;i<round;i++)
        InsertionSortOnce(i);
}

