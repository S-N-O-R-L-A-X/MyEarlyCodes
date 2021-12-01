#include <iostream>

using namespace std;

typedef int type;

void print(type &x)
{
    cout<<x<<' ';
}

struct node
{
    type item;
    node *next;
    node();
    node(type entry,node *p=NULL);
};

enum Error_code{underflow,overflow,rangeError,success};

template <typename element>
class Linklist
{
public:
	~Linklist( );
	Linklist( );
	Linklist(const Linklist &copy);
	void operator = (const Linklist &copy);
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
protected:
	int cnt;
	node *head;
	node *set_pos(int pos) const; //return the node at pos
};

int main()
{

    return 0;
}

node::node()
{
    next=NULL;
}

node::node(type entry,node *p)
{
    item=entry;
    next=p;
}

template <typename element>
Linklist <element>::Linklist()
{
    cnt=0;
    head=NULL;
}

template <typename element>
Linklist <element>::Linklist(const Linklist &copy)
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

template <typename element>
void Linklist<element>::operator=(const Linklist &copy)
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

template <typename element>
Linklist<element>::~Linklist()
{
    element a;
    while(!empty())
        remove(0,a);
}

template <typename element>
bool Linklist<element>::empty() const
{
    return cnt==0;
}

template <typename element>
bool Linklist<element>::full() const
{
    node *q=new node();
    if(q==NULL)
        return true;
    delete q;
    return false;
}

template <typename element>
int Linklist<element>::size() const
{
    return cnt;
}

template <typename element>
void Linklist<element>::clear()
{
    element a;
    while(!empty())
        remove(0,a);
}

template <typename element>
node *Linklist<element>::set_pos(int pos) const
{
    node *q=head;
    for(int i=0;i<pos;i++)
        q=q->next;
    return q;
}

template <typename element>
void Linklist<element>::traverse(void (*visit)(element &))
{
    for(node *p=head;p;p=p->next)
        (*visit)(p->item);
}

template <typename element>
Error_code Linklist<element>::retrieve(int pos,element &x) const
{
    if(pos<0||pos>=cnt)
        return rangeError;
    node *p=set_pos(pos);
    x=p->item;
    return success;
}

template <typename element>
element Linklist<element>::easy_retrieve(int pos)const
{
    node *p=set_pos(pos);
    return p->item;
}

template <typename element>
Error_code Linklist<element>::insert(int pos,const element &x)
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

template <typename element>
Error_code Linklist<element>::remove(int pos,element &x)
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
    x=cur->item;
	delete cur;
    	cnt--;
	return success;
}

template <typename element>
Error_code Linklist<element>::replace(int pos,const element &x)
{
    if(pos<0||pos>cnt)
        return rangeError;
    node *p=set_pos(pos);
    p->item=x;
    return success;
}


