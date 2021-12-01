#include <iostream>
#define maxsize 1000
using namespace std;

typedef int element;

class PriorityQueue
{
public:
    PriorityQueue()
    {
        cnt=0;
    }
    void insert(const element &x);
    void insert_heap(const element &current,int low,int high);
    void insert_heap(const element &x);
    element remove_heap();
    void swap(int i,int j);
    void build_heap();
    void traverse(void (*visit)(element &));
    int size();
private:
    int cnt;
    element entry[maxsize];
};

void print(element &x)
{
    cout<<x<<' ';
}

int main()
{
    element x;
    PriorityQueue pq;
    while(cin>>x&&x!=-1)
        pq.insert(x);
    pq.build_heap();
    pq.traverse(print);
    cout<<endl;
    int del;
    cin>>del;
    for(int i=0;i<del;i++)
        pq.remove_heap();
    pq.traverse(print);
    cout<<endl;
    while(cin>>x&&x!=-1)
        pq.insert_heap(x);
    pq.traverse(print);
    return 0;
}

int PriorityQueue::size()
{
    return cnt;
}

void PriorityQueue::insert(const element &x)
{
    entry[cnt++]=x;
}

void PriorityQueue::swap(int i,int j)
{
    element temp=entry[i];
    entry[i]=entry[j];
    entry[j]=temp;
}

element PriorityQueue::remove_heap()
{
    element ret=entry[0]; // temporary storage for moving entries
    swap(0,cnt-1);
    cnt--;
    build_heap();
    return ret;
}

void PriorityQueue::insert_heap(const element &current,int low,int high)
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


void PriorityQueue::build_heap()
/* Post: The entries of the Sortable list have been rearranged
so that it becomes a heap.
Uses: The contiguous List implementation of Chapter 6,
and insert heap . */
{
	int low; //All entries beyond the position low form a heap.
    //the node k that isn't a leaf has the property:2k+1<=cnt-1 => k<=1/2*cnt-1
	for(low=cnt/2-1;low>=0;low--)
    {
		element current=entry[low];
		insert_heap(current,low,cnt-1);
	}
}

void PriorityQueue::insert_heap(const element &x)
{
    entry[cnt]=x;
    int i=cnt;
    cnt++;
    while(i)
    {
        if(entry[i]>entry[(i-1)/2])
            swap(i,(i-1)/2);
        i=(i-1)/2;
    }
}

void PriorityQueue::traverse(void (*visit)(element &))
{
    for(int i=0;i<cnt;i++)
        (* visit)(entry[i]);
}
