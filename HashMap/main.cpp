#include <iostream>
#include <string>
#define maxsize 3000
using namespace std;

enum Error_code{not_present,overflow,duplicate_error,success,underflow,rangeError};

class Key
{
	string key;
public:
	Key(string x="NULL");
	string the_key() const;
};

bool operator == (const Key &x, const Key &y);


class Record
{
public:
	operator Key();// implicit conversion from Record to Key .
	Record(string x="NULL",string y="NULL");
	string the_key() const;
	string the_other() const;
private:
	string key;
	string other;
};

bool operator !=(const Record &x,const Record &y);
bool operator ==(const Record &x,const Record &y);

typedef Record type;
/*
void print(type &x)
{
    cout<<x<<' ';
}
*/

struct node
{
    type item;
    node *next;
    node();
    node(type entry,node *p=NULL);
};

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
	//Error_code retrieve(int pos,element &x) const;
    element easy_retrieve(int pos) const;
	Error_code replace(int pos,const element &x);
	Error_code remove(int pos,element &x);
	Error_code insert(int pos,const element &x);
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

/*
template <typename element>
Error_code Linklist<element>::retrieve(int pos,element &x) const
{
    if(pos<0||pos>=cnt)
        return rangeError;
    node *p=set_pos(pos);
    x=p->item;
    return success;
}
*/


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
    //x=cur->item;
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

class LinkedHash_table
{
public:
    LinkedHash_table(int size=0);
	void clear();
	Error_code insert(const Record &new_entry,bool showcode);
	Error_code retrieve(const Key &target,Record &found) const;
	void search(const Key &target) const;
	void change(const Record &target);
	Error_code remove(const Key &target, Record &found);
	int Hash(const Record &new_entry) const;
    int Hash(const Key &new_entry) const;
    unsigned int BKDRHash(char *str) const;
private:
	Linklist<Record> table[maxsize];//table的每一个元素为一个列表
    int hash_size;
};



int main()
{
    int n,m;
    cin>>n>>m;
    LinkedHash_table x(n);
    string a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        Record tmp(a,b);
        x.insert(tmp,false);
    }
    cin>>a>>b;
    Record tmp(a,b);
    x.insert(tmp,true);
    cin>>a>>b;
    Key key1(a);
    Record ans;
    x.remove(key1,ans);
    Key key2(b);
    x.search(key2);
    return 0;
}

Key::Key(string x)
{
    key=x;
}

string Key::the_key() const
{
	return key;
}

bool operator == (const Key &x,const Key &y)
{
	return x.the_key()==y.the_key();
}

Record::Record(string x,string y)
{
	key=x;
	other=y;
}



string Record::the_key() const
{
	return key;
}



string Record::the_other() const
{
	return other;
}

Record::operator Key()
{
	Key tmp(key);
	return tmp;
}

bool operator != (const Record &x,const Record &y)
{
	return x.the_key()!=y.the_key();
}

bool operator == (const Record &x,const Record &y)
{
	return x.the_key()==y.the_key();
}

LinkedHash_table::LinkedHash_table(int size)
{
    hash_size=size;
}

void LinkedHash_table::clear()
{
	for(int i=0;i<hash_size;i++)
		table[i].clear();
}


int LinkedHash_table::Hash(const Record &new_entry) const
{

	return (int)BKDRHash((char *)new_entry.the_key().c_str())%hash_size;
}


int LinkedHash_table::Hash(const Key &new_entry) const
{
	return (int)BKDRHash((char *)new_entry.the_key().c_str())%hash_size;
}

Error_code LinkedHash_table::insert(const Record &new_entry,bool showcode)
{
	int probe;
	probe=Hash(new_entry);
	if(showcode)
        cout<<probe<<endl;
	for(int i=0;i<table[probe].size();i++)
    {
		Record tmp;
		tmp=table[probe].easy_retrieve(i);
		if(tmp==new_entry)
        {
            table[probe].replace(i,new_entry);
            return success;
        }
	}
	table[probe].insert(0,new_entry);
	return success;
}

Error_code LinkedHash_table::retrieve(const Key &target, Record &found) const
{
	int probe;
	probe=Hash(target);
	for(int i=0;i<table[probe].size();i++)
    {
		Record tmp;
		tmp=table[probe].easy_retrieve(i);
		if(target==tmp)
        {
			found=tmp;
			return success;
		}
	}
	return not_present;
}

Error_code LinkedHash_table::remove(const Key &target, Record &found)
{
	int probe;
	probe=Hash(target);
    cout<<probe<<' ';
	for(int i=0;i<table[probe].size();i++)
    {
		Record tmp;
		tmp=table[probe].easy_retrieve(i);
        cout<<tmp.the_key()<<' ';
		if(target==tmp)
		{//存在的话直接删除。
		    cout<<tmp.the_other()<<endl;
			table[probe].remove(i,found);
			return success;
		}

	}
	cout<<target.the_key()<<" NULL"<<endl;
	return not_present;//不存在的话，删除失败。
}

void LinkedHash_table::search(const Key &target) const
{
    int probe;
	probe=Hash(target);
	cout<<probe<<' ';
	for(int i=0;i<table[probe].size();i++)
    {
		Record tmp;
		tmp=table[probe].easy_retrieve(i);
		cout<<tmp.the_key()<<' ';
		if(target==tmp)
		{
		    cout<<tmp.the_other();
            return ;
		}
	}
	cout<<target.the_key()<<' '<<"NULL";
}

void LinkedHash_table::change(const Record &target)
{
    int probe=Hash(target);
    cout<<probe<<endl;
    table[probe].replace(0,target);
}

// BKDR Hash Function
unsigned int LinkedHash_table::BKDRHash(char *str) const
{
    unsigned int seed = 31; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while(*str)
        hash=(hash*seed+(*str++))%hash_size;
    return hash%hash_size; //使hash函数返回值在hash表的有效地址范围
}
