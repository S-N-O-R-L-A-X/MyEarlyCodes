#include <iostream>
#include <cmath>
#include <algorithm>
#define eps 1E-7
#define maxsize 1000
using namespace std;

class coordination
{
public:
    int x;
    int y;
    int quadrant;
    double dis;
    bool operator <(const coordination that)
    {
        if(dis<that.dis)
            return true;
        if(fabs(dis-that.dis)<eps)
            return quadrant<that.quadrant;
        return false;
    }
};

ostream &operator <<(ostream &output,const coordination a)
{
    output<<a.x<<' '<<a.y<<' ';
    return output;
}

template <typename element>
class PriorityQueue
{
public:
    PriorityQueue()
    {
        cnt=0;
    }
    void insert(const element &x);
    void insert(const int &x,const int &y);
    void insert_heap(const element &current,int low,int high);
    element remove_heap();
    void build_heap();
    void heap_sort();
    void traverse(void (*visit)(element &));
    int size();
private:
    int cnt;
    element entry[maxsize];
};

typedef coordination element;
void print(element &x)
{
    cout<<x<<' ';
}

int main()
{
    PriorityQueue<coordination> pq;
    int k,x,y;
    cin>>k;
    while(cin>>x>>y)
        pq.insert(x,y);
    pq.heap_sort();
    for(int i=0;i<k;i++)
    {
        cout<<pq.remove_heap();//now the biggest is at the top
        pq.heap_sort();
    }

    return 0;
}

template <typename element>
int PriorityQueue <element>::size()
{
    return cnt;
}

template <typename element>
void PriorityQueue <element>::insert(const element &x)
{
    entry[cnt++]=x;
}

template <typename element>
void PriorityQueue <element>::insert(const int &x,const int &y)
{
    entry[cnt].x=x;
    entry[cnt].y=y;
    if(x>0&&y>0)
        entry[cnt].quadrant=1;
    else if(x<0&&y>0)
        entry[cnt].quadrant=2;
    else if(x<0&&y<0)
        entry[cnt].quadrant=3;
    else if(x>0&&y<0)
        entry[cnt].quadrant=4;
    else
        entry[cnt].quadrant=0;
    entry[cnt].dis=sqrt((double)x*x+y*y);
    cnt++;
}

template <typename element>
element PriorityQueue <element>::remove_heap()
{
    element ret=entry[0];//temporary storage for moving entries
	for(int i=0;i<cnt-1;i++)
        entry[i]=entry[i+1];
    cnt--;
    build_heap();
    return ret;
}


template <typename element>
void PriorityQueue <element>::insert_heap(const element &current,int low,int high)
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
void PriorityQueue <element>::build_heap()
/* Post: The entries of the Sortable list have been rearranged
so that it becomes a heap.
Uses: The contiguous List implementation of Chapter 6,
and insert heap . */
{
	int low; // All entries beyond the position low form a heap.
        //非叶子结点K的满足的条件是：2K+1<=COUNT-1
        //K<=1/2*COUNT-1
	for(low=cnt/2-1;low>=0;low--)
    {
		element current=entry[low];
		insert_heap(current,low,cnt-1);
	}
}

template <typename element>
void PriorityQueue<element>::heap_sort()
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
void PriorityQueue <element>::traverse(void (*visit)(element &))
{
    for(int i=0;i<cnt;i++)
        (* visit)(entry[i]);
}
