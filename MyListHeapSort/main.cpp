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
    void insert_heap(const element &current,int low,int high);
    void build_heap();
    void heap_sort();
protected:
    int cnt;
    element entry[maxsize];
};



int main()
{
    MyList<int> a;
    int x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.Insert(i,x);
    }

    a.build_heap();
    a.Traverse(process);
    cout<<endl;
    a.heap_sort();
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
void MyList<element>::insert_heap(const element &current,int low,int high)
//high is the last element that should be sorted.
{
	int large=2*low+1;//position of the larger child of entry[low]
	//and initialized as the left child of low.
	int lowbackup=low;//prevent the parameter reassignment in OCLint
	while(large<=high)
    {
		if(large<high&&entry[large]<entry[large+1])
			large++;//move to the right child
		if(entry[large]<current)
			break;//current belongs in position low.
		else
		{//promote entry[large] and move down the tree.
			entry[lowbackup]=entry[large];
			lowbackup=large;
			large=2*lowbackup+1;
		}
	}
	entry[lowbackup]=current;
}

template <typename element>
void MyList<element>::build_heap()
{
	int low;//All entries beyond the position low form a heap.
    //the node k that isn't a leaf has the property:2k+1<=cnt-1 => k<=1/2*cnt-1
	for(low=cnt/2-1;low>=0;low--)
    {
		element current=entry[low];
		insert_heap(current,low,cnt-1);
	}
}

template <typename element>
void MyList<element>::heap_sort()
{
    element current;// temporary storage for moving entries
	int last_unsorted;//entries beyond last unsorted have been sorted.
	build_heap();//turn the list into a heap first.
	for(last_unsorted=cnt-1;last_unsorted>0;last_unsorted--)
    {
		current=entry[last_unsorted];//extract last entry from list.
		entry[last_unsorted]=entry[0];//move top of heap to the end
		insert_heap(current,0,last_unsorted-1);//Restore the heap
	}
}

template <typename element>
void MyList<element>::Traverse(void (*visit)(element &))
{
    for (int i=0;i<cnt;i++)
           (*visit)(entry[i]);
}
