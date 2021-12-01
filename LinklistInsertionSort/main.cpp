#include <iostream>

using namespace std;

typedef int element;

void print(element &x)
{
    cout<<x<<' ';
}

struct node
{
    element item;
    node *next;
    node();
    node(element entry,node *p=NULL);
};

enum Error_code{underflow,overflow,rangeError,success};
class MyLinklist
{
public:
	~MyLinklist( );
	MyLinklist( );
	MyLinklist(const MyLinklist &copy);
	void operator = (const MyLinklist &copy);
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void (*visit)(element &));
	Error_code retrieve(int pos,element &x) const;
    element easy_retrieve(int pos) const;
	Error_code replace(int pos,const element &x);
	Error_code remove(int pos,element &x);
	Error_code insert(int pos,const element &x);
	void InsertionSortOnce(int i);
	void InsertionSort(int n);
	void InsertionSort();
protected:
	int cnt;
	node *head;
	node *set_pos(int pos) const; //return the node at pos
};

int main()
{
    MyLinklist a;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.insert(i,x);
    }
    a.InsertionSort(n/2);
    a.traverse(print);
    cout<<endl;
    a.InsertionSort();
    a.traverse(print);
    return 0;
}

node::node()
{
    next=NULL;
}

node::node(element entry,node *p)
{
    item=entry;
    next=p;
}

MyLinklist::MyLinklist()
{
    cnt=0;
    head=NULL;
}

MyLinklist::MyLinklist(const MyLinklist &copy)
{
    cnt=0;
    head=NULL;
    int i=0;
    for(node *q=copy.head;q;q=q->next)
    {
        insert(i,q->item);
        i++;
    }
}

void MyLinklist::operator=(const MyLinklist &copy)
{
    element x;
	if(this==&copy)
        return;
	while(!empty())
        remove(0,x);
	int i=0;
	for(node *q=copy.head;q;q=q->next)
    {
		insert(i,q->item);
		i++;
	}
}

MyLinklist::~MyLinklist()
{
    element a;
    while(!empty())
        remove(0,a);
}

bool MyLinklist::empty() const
{
    return cnt==0;
}

bool MyLinklist::full() const
{
    node *q=new node();
    if(q==NULL)
        return true;
    delete q;
    return false;
}

int MyLinklist::size() const
{
    return cnt;
}

void MyLinklist::clear()
{
    element a;
    while(!empty())
        remove(0,a);
}

node *MyLinklist::set_pos(int pos) const
{
    node *q=head;
    for(int i=0;i<pos;i++)
        q=q->next;
    return q;
}

void MyLinklist::traverse(void (*visit)(element &))
{
    for(node *p=head;p;p=p->next)
        (*visit)(p->item);
}

/*
Error_code MyLinklist::retrieve(int pos,element &x) const
{
    if(pos<0||pos>=cnt)
        return rangeError;
    node *p=set_pos(pos);
    x=p->item;
    return success;
}
*/

element MyLinklist::easy_retrieve(int pos)const
{
    node *p=set_pos(pos);
    return p->item;
}

Error_code MyLinklist::insert(int pos,const element &x)
{
    if(pos<0||pos>cnt)
        return rangeError;
    node *cur,*pre;
    if(pos>0)
    {
        pre=set_pos(pos-1);
        cur=pre->next;
    }
    else
        cur=head;
    node *q=new node(x,cur);
    if(q==NULL)
        return overflow;
    if(pos==0)
		head=q;
	else
		pre->next=q;
	cnt++;
	return success;
}

Error_code MyLinklist::remove(int pos,element &x)
{
	if(pos<0||pos>=cnt)
		return rangeError;
	node *pre,*cur;
	if(pos>0)
    {
		pre=set_pos(pos-1);
		cur=pre->next;
		pre->next=cur->next;
	}
	else
	{
		cur=head;
		head=head->next;
	}
//    x=cur->item;
	delete cur;
    	cnt--;
	return success;
}

Error_code MyLinklist::replace(int pos,const element &x)
{
    if(pos<0||pos>cnt)
        return rangeError;
    node *p=set_pos(pos);
    p->item=x;
    return success;
}

void MyLinklist::InsertionSortOnce(int pos)
{
    if(pos==0)
        return ;//sort head
    node *last_ordered=set_pos(pos-1);
    node *cur=last_ordered->next;
    bool flag=false;/*OClint says that "prefer early exits and continue"
                    if "return" takes the place of flag*/
    if(cur->item<last_ordered->item)
    {
        for(int i=0;i<cnt;i++)
        {
            node *p=set_pos(i);
            if(cur->item<p->item)
            {
                if(p==head)
                {
                    last_ordered->next=cur->next;
                    cur->next=head;
                    head=cur;
                    flag=true;
                }
                else
                {
                    node *q=set_pos(i-1);//the previous of p
                    last_ordered->next=cur->next;
                    cur->next=p;
                    q->next=cur;
                    flag=true;
                }
            }
            if(flag)
                break;
        }
    }
}

void MyLinklist::InsertionSort()
{
    for(int i=0;i<cnt;i++)
        InsertionSortOnce(i);
}

void MyLinklist::InsertionSort(int n)
{
    for(int i=0;i<n;i++)
        InsertionSortOnce(i);
}
