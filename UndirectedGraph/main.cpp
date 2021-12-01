#include <iostream>
#include <queue>
#define maxsize 501
using namespace std;

typedef int type;

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
	Error_code Ordered_insert(const element &x);
protected:
	int cnt;
	node *head;
	node *set_pos(int pos) const; //return the node at pos
};


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
    node *cur,*pre=NULL;
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
Error_code Linklist<element>::Ordered_insert(const element &x)
{
    node *cur=NULL,*pre=NULL;
    node *q=new node(x,cur);
    if(q==NULL)
        return overflow;
    if(cnt==0)
        head=q;
    else if(x<head->item)
    {
        q->next=head;
        head=q;
    }
    else if(cnt==1)
        head->next=q;
    else
    {
        for(cur=head->next,pre=head;cur;cur=cur->next,pre=pre->next)
        {
            if(x<cur->item)
            {
                pre->next=q;
                q->next=cur;
                cnt++;
                return success;
            }
        }
        pre->next=q;
    }
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

typedef int Vertex;

class graph
{
public:
    void dfs();
    void bfs();
    void insert(int start,int end);
    graph(int n=0);
private:

	void initialize();
	void traverse(Vertex v);
	int cnt; //number of vertices
    bool visited[maxsize];
	Linklist<Vertex> neighbour[maxsize];
};



int main()
{
    int n,m;
    cin>>n>>m;
    graph g(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g.insert(a,b);
    }
    g.dfs();
    printf("\n");
    g.bfs();
    return 0;
}

graph::graph(int n)
{
    cnt=n;
    initialize();
}

void graph::traverse(Vertex v)
{
    visited[v]=true;
    cout<<v<<' ';
    int len=neighbour[v].size();
    for(int j=0;j<len;j++)
    {
        Vertex next=neighbour[v].easy_retrieve(j);
        if(!visited[next])
            traverse(next);
    }
}


void graph::dfs()
{
    for(int i=0;i<cnt;i++)
    {
        if(!visited[i])
            traverse(i);
    }
};

void graph::bfs()
{
    initialize();
    queue<Vertex> q;
    for(int i=0;i<cnt;i++)
    {
        if(!visited[i])
        {
            q.push(i);
            visited[i]=true;
            while(!q.empty())
            {
                Vertex now=q.front();
                cout<<now<<' ';
                for(int j=0;j<neighbour[now].size();j++)
                {
                    Vertex next=neighbour[now].easy_retrieve(j);
                    if(!visited[next])
                    {
                        q.push(next);
                        visited[next]=true;
                    }
                }
                q.pop();
            }
        }
    }
    initialize();
};

void graph::initialize()
{
    for(int i=0;i<cnt;i++)
        visited[i]=false;
}

void graph::insert(int start,int end)
{
    int len=neighbour[start].size();
    neighbour[start].Ordered_insert(end);
    neighbour[end].Ordered_insert(start);
};


/*
test1
5 5
0 3 0 2 4 2 4 1 3 1


test2
7 9
0 1 3 5 4 0 3 4 3 1 6 4 6 5 5 2 2 0


test3
9 10
4 1 4 5 6 5 1 6 8 1 3 8 2 3 7 2 7 0 0 4
*/
