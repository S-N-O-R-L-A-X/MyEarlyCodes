#include <iostream>
#include <stack>
using namespace std;

class Record
{
public:
	Record(string x,string y="");
	Record();
	string the_key() const;
	string the_other() const;
private:
	string key;
	string other;
};

Record::Record()
{

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

bool operator == (const Record &x, const Record &y)
{
	return x.the_key()==y.the_key();
}

bool operator != (const Record &x, const Record &y)
{
	return x.the_key()!=y.the_key();
}

bool operator > (const Record &x, const Record &y)
{
	return x.the_key() > y.the_key();
}

bool operator < (const Record &x, const Record &y)
{
	return x.the_key() < y.the_key();
}

ostream & operator << (ostream &output, Record &x)
{
	output<<x.the_key();
	output<<' ';
	return output;
}

template <typename element>
struct node
{
    element item;
    node *next;
    node();
    node(element entry,node *p=NULL);
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
	void print(element &x);
	void traverse(void (*visit)(element &));
	//Error_code retrieve(int pos,element &x) const;
    element easy_retrieve(int pos) const;
	Error_code replace(int pos,const element &x);
	Error_code remove(int pos,element &x);
	Error_code insert(int pos,const element &x);
protected:
	int cnt;
	node<element> *head;
	node<element> *set_pos(int pos) const; //return the node at pos
};

template <typename element>
node<element>::node()
{
    next=NULL;
}

template <typename element>
node<element>::node(element entry,node *p)
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
    for(node<element> *q=copy.head;q;q=q->next)
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
	for(node<element> *q=copy.head;q;q=q->next)
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
    node<element> *q=new node<element>();
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
node<element> *Linklist<element>::set_pos(int pos) const
{
    node<element> *q=head;
    for(int i=0;i<pos;i++)
        q=q->next;
    return q;
}

template <typename element>
void Linklist<element>::traverse(void (*visit)(element &))
{
    for(node<element> *p=head;p;p=p->next)
        (*visit)(p->item);
}
/*
template <typename element>
Error_code Linklist<element>::retrieve(int pos,element &x) const
{
    if(pos<0||pos>=cnt)
        return rangeError;
    node<element> *p=set_pos(pos);
    x=p->item;
    return success;
}
*/
template <typename element>
element Linklist<element>::easy_retrieve(int pos)const
{
    node<element> *p=set_pos(pos);
    return p->item;
}

template <typename element>
Error_code Linklist<element>::insert(int pos,const element &x)
{
    if(pos<0||pos>cnt)
        return rangeError;
    node<element> *cur,*pre;
    if(pos>0)
    {
        pre=set_pos(pos-1);
        cur=pre->next;
    }
    else
        cur=head;
    node<element> *q=new node<element>(x,cur);
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
	node<element> *pre,*cur;
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
    node<element> *p=set_pos(pos);
    p->item=x;
    return success;
}


//----------------------------------------------------------------
template <typename element>
struct BinaryNode
{
    element data;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode();
    BinaryNode(const element &x);
};

class BalancedBinarySearchTree
{
public:
    BalancedBinarySearchTree();
    bool empty() const;
	void preorder(void (*visit)(Record &));
	void inorder(void (*visit)(Record &));
	void postorder(void (*visit)(Record &));
	BinaryNode<Record> *get_root();
	int size() const;
	int height() const;
	void insert(const Record &new_data);
	bool remove(const Record &target);
	void print(Record &x);
	void tree_search(Record &target /*out*/) const;
    void build_tree(const Linklist<Record> &supply/*in*/);
       //构建二叉查找树，supply为有序元素的组合。
protected:
    bool search_and_insert(BinaryNode<Record> **sub_root,const Record &new_data);
    void recursive_preorder(BinaryNode<Record> *sub_root,void (*visit)(Record &));
	void recursive_inorder(BinaryNode<Record> *sub_root,void (*visit)(Record &));
	void recursive_postorder(BinaryNode<Record> *sub_root,void (*visit)(Record &));
    BinaryNode<Record> *non_recur_search_for_node(BinaryNode<Record>* sub_root,const Record &target) const;
    BinaryNode<Record> *recur_search_for_node(BinaryNode<Record>* sub_root,const Record &target) const;
	bool remove_root(BinaryNode<Record> **sub_root/*inout*/);
    bool search_and_destroy(BinaryNode<Record>* &sub_root,const Record &target);
    void build_insert(int count, const Record &new_data);
       //count，插入节点的编号； new_data插入信息。
      // last_node 记录当前二叉查找树的每一层的最后一个节点的信息。
	BinaryNode<Record> * find_root();
       //插入结束，获得当前二叉查找树的根节点指针。
	void connect();
      //根据last_node中的信息调整每一层最后一个节点中，右孩子的信息。


	BinaryNode<Record> *root;
	Linklist <BinaryNode<Record>*> last_node;
	int cnt;
};

int main()
{
    int n;
    string key,other;
    BalancedBinarySearchTree a;
    Linklist<Record> b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key>>other;
        Record tmp(key,other);
        b.insert(i,tmp);
    }
    a.build_tree(b);
    for(int i=1;i<=2;i++)
    {
        cin>>key;
        Record target(key);
        a.tree_search(target);
    }

    return 0;
}

template <typename element>
BinaryNode<element>::BinaryNode()
{
    left=NULL;
    right=NULL;
}

template <typename element>
BinaryNode<element>::BinaryNode(const element &x)
{
    data=x;
    left=NULL;
    right=NULL;
}

BalancedBinarySearchTree::BalancedBinarySearchTree()
{
    root=NULL;
    cnt=0;
    last_node.clear();

}

bool BalancedBinarySearchTree::empty() const
{
    return root==NULL;
}

int BalancedBinarySearchTree::size() const
{
    return cnt;
}

BinaryNode<Record> *BalancedBinarySearchTree::get_root()
{
    return root;
}

void BalancedBinarySearchTree::preorder(void (*visit)(Record &))
{
	recursive_preorder(root,visit);
}


void BalancedBinarySearchTree::recursive_preorder(BinaryNode<Record> *sub_root,void (*visit)(Record &))
{
	if(sub_root!=NULL)
    {
		(*visit)(sub_root->data);
		recursive_preorder(sub_root->left,visit);
		recursive_preorder(sub_root->right,visit);
	}
}

void BalancedBinarySearchTree::inorder(void (*visit)(Record &))
{
	recursive_inorder(root,visit);
}


void BalancedBinarySearchTree::recursive_inorder(BinaryNode<Record> *sub_root, void (*visit)(Record &))
{
	if(sub_root!=NULL)
    {
		recursive_inorder(sub_root->left,visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right,visit);
	}
}

void BalancedBinarySearchTree::postorder(void (*visit)(Record &))
{
	recursive_postorder(root,visit);
}

void BalancedBinarySearchTree::recursive_postorder(BinaryNode<Record> *sub_root, void (*visit)(Record &))
{
	if(sub_root!=NULL)
    {
		recursive_postorder(sub_root->left,visit);
		recursive_postorder(sub_root->right,visit);
		(*visit)(sub_root->data);
	}
}

int BalancedBinarySearchTree::height() const
{
	if(cnt==0)
        return -1;
	int tmp=1,k;
	for(k=0;tmp<=cnt;k++)//log2size
        tmp*=2;
	return k-1;
};


BinaryNode<Record> *BalancedBinarySearchTree::recur_search_for_node
(BinaryNode<Record>* sub_root,const Record &target) const
{
	if(sub_root==NULL||sub_root->data==target)
		return sub_root;
	else if(sub_root->data<target)
		return recur_search_for_node(sub_root->right,target);
    return recur_search_for_node(sub_root->left,target);
}

BinaryNode<Record> *BalancedBinarySearchTree::non_recur_search_for_node
(BinaryNode<Record> *sub_root,const Record &target) const
{
    BinaryNode<Record> *tmpsub_root=sub_root;
	while(tmpsub_root!=NULL&&tmpsub_root->data!=target)
    {
        cout<<tmpsub_root->data.the_key()<<' ';
        if(tmpsub_root->data<target)
            tmpsub_root=tmpsub_root->right;
		else
            tmpsub_root=tmpsub_root->left;
    }
	return tmpsub_root;
}

void BalancedBinarySearchTree::tree_search(Record &target) const
{
	BinaryNode<Record> *found=non_recur_search_for_node(root,target);
	if(found==NULL)
        cout<<"NULL"<<endl;
	else
	{
	    target=found->data;
	    cout<<target.the_key()<<' '<<target.the_other()<<endl;
	}
}

void BalancedBinarySearchTree::print(Record &x)
{
    cout<<x.the_key();
}

void BalancedBinarySearchTree::insert(const Record &new_data)
{
	if(search_and_insert(&root,new_data))
        cnt++;
}

bool BalancedBinarySearchTree::
search_and_insert(BinaryNode<Record> **sub_root,const Record &new_data /*in*/)
{
	if((*sub_root)==NULL)
    {
		*sub_root=new BinaryNode<Record>;
		(*sub_root)->data=new_data;
		return true;
	}
	else if(new_data<(*sub_root)->data)
		return search_and_insert(&((*sub_root)->left),new_data);
	else if (new_data>(*sub_root)->data)
		return search_and_insert(&((*sub_root)->right),new_data);
    return false;
}

bool BalancedBinarySearchTree::remove(const Record &target)
/* Post: If a Record with a key matching that of target belongs to the Search tree
a code of success is returned and the corresponding node is removed from the
tree. Otherwise, a code of not present is returned.*/
{
	if(search_and_destroy(root,target))
    {
        cnt--;
        return true;
    }
    return false;
}

bool BalancedBinarySearchTree::remove_root(BinaryNode<Record> **sub_root)
{
    if(*sub_root==NULL)//not found!
        return false;
	BinaryNode<Record> *to_delete=*sub_root;// Remember node to delete at end.
	BinaryNode<Record> *tmpsub_root=*sub_root;//just for OCLint

    if(tmpsub_root->right==NULL)//one child or zero child
        tmpsub_root=tmpsub_root->left;
	else if(tmpsub_root->left==NULL)//one child
        tmpsub_root=tmpsub_root->right;
	else// Neither subtree is empty.
	{
		to_delete=tmpsub_root->left;// Move left to find predecessor. 记录待删除的节点
		BinaryNode<Record> *parent=tmpsub_root;// parent of to_delete
		while(to_delete->right!=NULL)//find the to delete
		{
			parent=to_delete;
			to_delete=to_delete->right;
		}
		tmpsub_root->data=to_delete->data;//backup
		if(parent==tmpsub_root)
            tmpsub_root->left=to_delete->left;
		else
            parent->right=to_delete->left;
	}
	delete to_delete;
	(*sub_root)=tmpsub_root;
	return true;
}


bool BalancedBinarySearchTree::search_and_destroy(BinaryNode<Record>* &sub_root,const Record &target)
//find the node to be deleted
{
	if(sub_root==NULL||sub_root->data==target)
		return remove_root(&sub_root);
	else if(target<sub_root->data)
		return search_and_destroy(sub_root->left,target);
    return search_and_destroy(sub_root->right,target);
}

void BalancedBinarySearchTree::build_tree(const Linklist<Record> &supply)
{
	//remove it for our Binary_tree int count
	int count = 0; // number of entries inserted so far
	Record x, last_x;

	// pointers to last nodes on each level
	BinaryNode<Record> *none=NULL;
	last_node.insert(0,none); // permanently NULL (for children of leaves)

	while(count<supply.size())
    {
        x=supply.easy_retrieve(count);
		if(count>0&&last_x>x)
            break;
		build_insert(++count,x);
		last_x = x;
	}
	root = find_root();
	connect();
}

void BalancedBinarySearchTree::build_insert(int count, const Record &new_data)
{
	int level; //level of new node above the leaves, counting inclusively
	for(level=1;count%2==0;level++)//count=k*2^level
		count/=2;
	BinaryNode<Record>*next_node=new BinaryNode<Record>(new_data),*parent; // one level higher in last node
	next_node->left=last_node.easy_retrieve(level-1);
	if(last_node.size()<=level) //it means a new 2^level is inserted
		last_node.insert(level,next_node);
	else
		last_node.replace(level,next_node);
    if(level+1<last_node.size())
    {
        parent=last_node.easy_retrieve(level+1);
        if(parent->right==NULL)
            parent->right=next_node;//update the parent node
    }

}

void BalancedBinarySearchTree::connect()
{
	BinaryNode<Record> *high_node,// from last node with NULL right child
		*low_node; // candidate for right child of high node
	int high_level=last_node.size()-1,low_level;
	while(high_level>2)// nodes on levels 1 and 2 are already OK.
    {
		high_node=last_node.easy_retrieve(high_level);
		if(high_node->right==NULL)//undefined right tree
		{
			low_level=high_level;
            low_node=last_node.easy_retrieve(--low_level);
			while(low_node!=NULL&&low_node->data<high_node->data)
                low_node=last_node.easy_retrieve(--low_level);
            // Find the highest entry not in the left subtree.

			high_node->right=low_node;
			high_level=low_level;
		}
		else
			high_level--; // Search down for highest dangling node.
	}
}

BinaryNode<Record> *BalancedBinarySearchTree::find_root()
{
	return last_node.easy_retrieve(last_node.size()-1);
	// Find root in the highest occupied level in last node .
}

