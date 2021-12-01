#include <iostream>
#include <stack>
using namespace std;

class Record
{
public:
	Record(string x,string y);
	string the_key() const;
private:
	string key;
	string other;
};

Record::Record(string x,string y)
{
	key=x;
	other=y;
}


string Record::the_key() const
{
	return key;
}

bool operator == (const Record &x, const Record &y)
{
	return x.the_key()==y.the_key();
}

bool operator > (const Record &x, const Record &y)
{
	return x.the_key( ) > y.the_key( );
}

bool operator < (const Record &x, const Record &y)
{
	return x.the_key( ) < y.the_key( );
}

ostream & operator << (ostream &output, Record &x)
{
	output<<x.the_key();
	output<<" ";
	return output;
}


typedef Record element;


void print(element &x)
{
    cout<<x<<' ';
}

template <typename element>
struct BinaryNode
{
    element data;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode();
    BinaryNode(const element &x);
};

template <typename element>
class BinaryTree
{
public:
    BinaryTree();
    bool empty() const;
	void preorder(void (*visit)(element &));
	void inorder(void (*visit)(element &));
	void postorder(void (*visit)(element &));
	BinaryNode<element> get_root();
	int size() const;
	int height() const;
	void insert(element &x);
protected:
    void recursive_preorder(BinaryNode<element> *sub_root, void (*visit)(element &));
	void recursive_inorder(BinaryNode<element> *sub_root, void (*visit)(element &));
	void recursive_postorder(BinaryNode<element> *sub_root, void (*visit)(element &));
	BinaryNode<element> *root;
	int cnt;
};

template <typename Record>
class BinarySearchTree:public BinaryTree<Record>
{
public:
	void insert(const Record &new_data);
	void remove(const Record &target);
	void tree_search(Record &target /*out*/) const;
private: // Add auxiliary function prototypes here.
     BinaryNode<Record> *non_recur_search_for_node(BinaryNode<Record>*  sub_root, const Record &target) const;
     BinaryNode<Record> *recur_search_for_node(BinaryNode<Record>*  sub_root, const Record &target) const;
};

int main()
{

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

template <typename element>
BinaryTree<element>::BinaryTree()
{
    root=NULL;
    cnt=0;
}

template <typename element>
bool BinaryTree<element>::empty() const
{
    return root==NULL;
}

template <typename element>
int BinaryTree<element>::size() const
{
    return cnt;
}

template <typename element>
BinaryNode<element> BinaryTree<element>::get_root()
{
    return root;
}

template <typename element>
void BinaryTree<element>::preorder(void (*visit)(element &))
{
	recursive_preorder(root,visit);
}

template <typename element>
void BinaryTree<element>::recursive_preorder(BinaryNode<element> *sub_root,void (*visit)(element &))
{
	if(sub_root!=NULL)
    {
		(*visit)(sub_root->data);
		recursive_preorder(sub_root->left,visit);
		recursive_preorder(sub_root->right,visit);
	}
}

template <typename element>
void BinaryTree<element>::inorder(void (*visit)(element &))
{
	recursive_inorder(root,visit);
}

template <class element>
void BinaryTree<element>::recursive_inorder(BinaryNode<element> *sub_root, void (*visit)(element &))
{
	if(sub_root!=NULL)
    {
		recursive_inorder(sub_root->left,visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right,visit);
	}
}

template <typename element>
void BinaryTree<element>::postorder(void (*visit)(element &))
{
	recursive_postorder(root,visit);
}

template <typename element>
void BinaryTree<element>::recursive_postorder(BinaryNode<element> *sub_root, void (*visit)(element &))
{
	if(sub_root!=NULL)
    {
		recursive_postorder(sub_root->left,visit);
		recursive_postorder(sub_root->right,visit);
		(*visit)(sub_root->data);
	}
}

template <typename element>
void BinaryTree<element>::insert(element &x)
{
    if(empty())
    {
		root=new BinaryNode<element>(x);
		cnt++;
		return ;
	}
    stack<int> numbers;//store the path to the parent of the current node
    int item,tmpcnt=cnt;//tmpcnt shows the current node
    while(tmpcnt>0)//find the path
    {
	    if(tmpcnt%2==0)//the node is right child
		   numbers.push(2);//2 stand for right child
	    else//the node is left child
		   numbers.push(1);//1 stand for left child
	    tmpcnt=(tmpcnt-1)/2;//get to the parent
	}
	BinaryNode<element> *current=root;
	while (numbers.size()>1)//trace back to the parent
    { //pop until there is only one node in stack--the parent of current node
		item=numbers.top();
        if(item==1)current=current->left;
		if(item==2)current=current->right;
       	numbers.pop();
	}
	item=numbers.top();
	if(item==1)current->left=new BinaryNode<element> (x);
	if(item==2)current->right=new BinaryNode<element> (x);
	cnt++;
}

template <typename element>
int BinaryTree<element>::height() const
{
	if(cnt==0)
        return -1;
	int tmp=1,k;
	for(k=0;tmp<=cnt;k++)//log2size
        tmp*=2;
	return k-1;
};


template <typename Record>
BinaryNode<Record> *BinarySearchTree<Record>::recur_search_for_node
(BinaryNode<Record>* sub_root,const Record &target) const
{
	if(sub_root==NULL||sub_root->data==target)
		return sub_root;
	else if(sub_root->data<target)
		return search_for_node(sub_root->right,target);
	else
        return search_for_node(sub_root->left,target);
}

template <typename Record>
BinaryNode<Record> *BinarySearchTree<Record>::non_recur_search_for_node
(BinaryNode<Record> *sub_root,const Record &target) const
{
	while(sub_root!=NULL&&sub_root->data!=target)
    {
        if(sub_root->data<target)
            sub_root=sub_root->right;
		else
            sub_root=sub_root->left;
    }
	return sub_root;
}

template <typename Record>
void BinarySearchTree<Record>::tree_search(Record &target) const
{
    BinaryNode<Record> *tmproot=get_root()
	BinaryNode<Record> *found=non_recur_search_for_node(tmproot,target);
	if(found!=NULL)
		target=found->data;
}

template <class Record>
void BinarySearchTree<Record>::insert(const Record &new_data)
{//插入成功返回 success
	if(search_and_insert(root,new_data))
        cnt++;
}

template <class Record>
Error_code Search_tree<Record>::
search_and_insert(Binary_node<Record> * &sub_root /*inout*/, const Record &new_data /*in*/)
{
	if(sub_root==NULL)
    {
		sub_root=new Binary_node<Record>(new_data);
		return true;
	}
	else if(new_data<sub_root->data)
		return search_and_insert(sub_root->left,new_data);
	else if (new_data>sub_root->data)
		return search_and_insert(sub_root->right, new_data);
	else
        return false;
}

