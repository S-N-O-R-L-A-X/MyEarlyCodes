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
    void Swap(int pos1,int pos2);
    void QuickSort();
    void recursive_quicksort(int low,int high,bool flag);
    int Partition(int low,int high,bool flag);
protected:
    int cnt;
    element entry[maxsize];
};


int main()
{
    MyList<int> a;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.Insert(i,x);
    }

    a.QuickSort();
    a.Traverse(process);
    return 0;
}

template <typename element>
void MyList<element>::Swap(int pos1,int pos2)
{
    element x;
    x=entry[pos1];
    entry[pos1]=entry[pos2];
    entry[pos2]=x;
}

template <typename element>
int MyList<element>::Partition(int low,int high,bool flag)
{
    element pivot;
	int	last_small;// position of the last key less than pivot，记录小于抽点的数值下标

	Swap(high,low);//exchange the position of pivot and the mid ，并放置于最小的位置
	pivot=entry[low]; //the last entry is now pivot .
	last_small=low;//initialize

	for(int i=low+1;i<=high;i++)
    {
        if(entry[i]<pivot)
        {
			last_small++; //从low+1开始放置。
			Swap(last_small,i); // Move large entry to right and small to left.
		}
    }
	Swap(low,last_small); // Put the pivot into its proper position.
	if(flag)
    {
        for(int i=0;i<cnt;i++)
            cout<<entry[i]<<' ';
        cout<<endl;
    }

	return last_small;
}

template <typename element>
void MyList<element>::recursive_quicksort(int low,int high,bool flag)
/* Pre: low and high are valid positions in the Sortable list.
The entries of the Sortable list have been rearranged
so that their keys are sorted into nondecreasing order.*/
{
	int pivot_position;
	if(low<high)
    {
        pivot_position=Partition(low,high,flag);
		recursive_quicksort(low,pivot_position-1,false);
		recursive_quicksort(pivot_position+1,high,false);
	}

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

template <typename element>
void MyList<element>::QuickSort()
{
    recursive_quicksort(0,cnt-1,true);
}
