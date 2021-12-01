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
    node *back;
    node *next;
    node();
    node(element entry,node *p=NULL,node *q=NULL);
};

enum Error_code{underflow,overflow,rangeError,success};
class DoubleLinklist
{
public:
	~DoubleLinklist( );
	DoubleLinklist( );
	DoubleLinklist(const DoubleLinklist &copy);
	void operator = (const DoubleLinklist &copy);
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void (*visit)(element &));
	void Inverse_traverse(void (*visit)(element &));
	//Error_code retrieve(int pos,element &x) const;
	element easy_retrieve(int pos) const;
	Error_code replace(int pos,const element &x);
	Error_code remove(int pos,element &x);
	Error_code insert(int pos,const element &x);
	void findfront(int pos);
	void findrear(int pos);
protected:
	int cnt;
	node *head;
	mutable int cur_pos;
	mutable node *cur;
	void set_pos(int pos) const; //return the node at pos
};

int main()
{
    DoubleLinklist x;
    int a;
    int i=0;
    while(cin>>a&&a!=-1)
        x.insert(i++,a);
    for(int i=0;i<x.size();i++)
        x.findfront(i);
    cout<<endl;
    for(int i=0;i<x.size();i++)
        x.findrear(i);
    return 0;
}

node::node()
{
    next=NULL;
}

node::node(element entry,node *p,node *q)
{
    item=entry;
    back=p;
    next=q;
}

DoubleLinklist::DoubleLinklist()
{
    cnt=0;
    head=NULL;
}

DoubleLinklist::DoubleLinklist(const DoubleLinklist &copy)
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

void DoubleLinklist::operator=(const DoubleLinklist &copy)
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

DoubleLinklist::~DoubleLinklist()
{
    element a;
    while(!empty())
        remove(0,a);
}

bool DoubleLinklist::empty() const
{
    return cnt==0;
}

bool DoubleLinklist::full() const
{
    node *q=new node();
    if(q==NULL)
        return true;
    delete q;
    return false;
}

int DoubleLinklist::size() const
{
    return cnt;
}

void DoubleLinklist::clear()
{
    element a;
    while(!empty())
        remove(0,a);
}

void DoubleLinklist::set_pos(int pos) const
{
    if(cur_pos<=pos)
    {
        for(;cur_pos!=pos;cur_pos++)
            cur=cur->next;
    }
    else
    {
        for(;cur_pos!=pos;cur_pos--)
            cur=cur->back;
    }
}

void DoubleLinklist::traverse(void (*visit)(element &))
{
    for(node *p=head;p;p=p->next)
        (*visit)(p->item);
}

void DoubleLinklist::Inverse_traverse(void (*visit)(element &))
{
    set_pos(cnt-1);
    for(node *p=cur;p;p=p->back)
        (*visit)(p->item);
}
/*
Error_code DoubleLinklist::retrieve(int pos,element &x) const
{
    if(pos<0||pos>=cnt)
        return rangeError;
    set_pos(pos);
    x=cur->item;
    return success;
}*/

element DoubleLinklist::easy_retrieve(int pos) const
{
    set_pos(pos);
    return cur->item;
}

Error_code DoubleLinklist::insert(int pos,const element &x)
{
    if(pos<0||pos>cnt)
        return rangeError;
    node *pre,*now;
    if(pos==0)
    {
        if(cnt==0)
            now=NULL;
        else
        {
            set_pos(0);
            now=cur;
        }
        pre=NULL;
    }
    else
    {
        set_pos(pos-1);
        pre=cur;
        now=pre->next;
    }

    node *p=new node(x,pre,now);
    if(p==NULL)
        return overflow;
    if(pre!=NULL)
        pre->next=p;
    if(now!=NULL)
        now->back=p;
    if(pos==0)
        head=p;
    cur=p;
    cur_pos=pos;
	cnt++;
	return success;
}

Error_code DoubleLinklist::remove(int pos,element &x)
{
	if(pos<0||pos>=cnt)
		return rangeError;
	node *pre,*now;
	if(pos>0)
    {
		set_pos(pos-1);
		pre=cur;
		now=pre->next;
		pre->next=now->next;
		if(now->next)
            now->next->back=pre;
	}
	else
	{
		now=head;
		head=head->next;
		if(head)
            head->back=NULL;
        cur_pos=0;
        cur=head;
	}
    x=now->item;
	delete now;
    cnt--;
	return success;
}

Error_code DoubleLinklist::replace(int pos,const element &x)
{
    if(pos<0||pos>cnt)
        return rangeError;
    set_pos(pos);
    cur->item=x;
    return success;
}

void DoubleLinklist::findfront(int pos)
{
    set_pos(pos);
    if(cur==NULL)
    {
        cout<<"0 ";
        return ;
    }
    int tmp=cur->item;
    for(node *p=cur;p;p=p->back)
    {
        if(p->item<tmp)
        {
            cout<<p->item<<' ';
            return ;
        }
    }
    cout<<"0 ";
}

void DoubleLinklist::findrear(int pos)
{
    set_pos(pos);
    if(cur==NULL)
    {
        cout<<"0 ";
        return ;
    }
    int tmp=cur->item;
    for(node *p=cur;p;p=p->next)
    {
        if(p->item>tmp)
        {
            cout<<p->item<<' ';
            return ;
        }
    }
    cout<<"0 ";
}
