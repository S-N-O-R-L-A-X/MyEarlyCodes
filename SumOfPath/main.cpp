#include <iostream>
#include <stack>
using namespace std;

typedef int element;

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
	int size() const;
	int height() const;
	void insert(element &x);
	bool sum_of_path(int s);
protected:
    void recursive_preorder(BinaryNode<element> *sub_root, void (*visit)(element &));
	void recursive_inorder(BinaryNode<element> *sub_root, void (*visit)(element &));
	void recursive_postorder(BinaryNode<element> *sub_root, void (*visit)(element &));
    bool recursive_sum_of_path(BinaryNode<element> *p,int tmp,int s);
	BinaryNode<element> *root;
	int cnt;
};

int main()
{
    int n,s;
    cin>>n;
    BinaryTree<int> a;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        a.insert(tmp);
    }
    cin>>s;
    cout<<a.height();
    if(a.sum_of_path(s))
        cout<<" true";
    else
        cout<<" false";
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

template <typename element>
bool BinaryTree<element>::sum_of_path(int s)
{
    int tmp=0;
    return recursive_sum_of_path(root,tmp,s);
}

template <typename element>
bool BinaryTree<element>::recursive_sum_of_path(BinaryNode<element> *p,int tmp,int s)
{
    if(p==NULL)
    {
        if(tmp==s)
            return true;
        return false;
    }
    return recursive_sum_of_path(p->left,tmp+p->data,s)||recursive_sum_of_path(p->right,tmp+p->data,s);
}
