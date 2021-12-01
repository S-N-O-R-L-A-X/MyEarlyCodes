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

class BinarySearchTree
{
public:
    BinarySearchTree();
    bool empty() const;
	void preorder(void (*visit)(Record &));
	void inorder(void (*visit)(Record &));
	void postorder(void (*visit)(Record &));
	BinaryNode<Record> *get_root();
	int size() const;
	int height() const;
	void insert(const Record &new_data);
	bool remove(const Record &target);
	void tree_search(Record &target /*out*/) const;

protected:
    bool search_and_insert(BinaryNode<Record> **sub_root,const Record &new_data);
    void recursive_preorder(BinaryNode<Record> *sub_root,void (*visit)(Record &));
	void recursive_inorder(BinaryNode<Record> *sub_root,void (*visit)(Record &));
	void recursive_postorder(BinaryNode<Record> *sub_root,void (*visit)(Record &));
    BinaryNode<Record> *non_recur_search_for_node(BinaryNode<Record>* sub_root,const Record &target) const;
    BinaryNode<Record> *recur_search_for_node(BinaryNode<Record>* sub_root,const Record &target) const;
	bool remove_root(BinaryNode<Record> **sub_root/*inout*/);
    bool search_and_destroy(BinaryNode<Record>* &sub_root,const Record &target);

	BinaryNode<Record> *root;
	int cnt;
};

int main()
{
    int n;
    string key,other;
    BinarySearchTree a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key>>other;
        Record tmp(key,other);
        a.insert(tmp);
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        Record del(key);
        a.remove(del);
    }
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
    //data=x;
    left=NULL;
    right=NULL;
}

BinarySearchTree::BinarySearchTree()
{
    root=NULL;
    cnt=0;
}

bool BinarySearchTree::empty() const
{
    return root==NULL;
}

int BinarySearchTree::size() const
{
    return cnt;
}

BinaryNode<Record> *BinarySearchTree::get_root()
{
    return root;
}

void BinarySearchTree::preorder(void (*visit)(element &))
{
	recursive_preorder(root,visit);
}


void BinarySearchTree::recursive_preorder(BinaryNode<element> *sub_root,void (*visit)(element &))
{
	if(sub_root!=NULL)
    {
		(*visit)(sub_root->data);
		recursive_preorder(sub_root->left,visit);
		recursive_preorder(sub_root->right,visit);
	}
}

void BinarySearchTree::inorder(void (*visit)(element &))
{
	recursive_inorder(root,visit);
}


void BinarySearchTree::recursive_inorder(BinaryNode<element> *sub_root, void (*visit)(element &))
{
	if(sub_root!=NULL)
    {
		recursive_inorder(sub_root->left,visit);
		(*visit)(sub_root->data);
		recursive_inorder(sub_root->right,visit);
	}
}

void BinarySearchTree::postorder(void (*visit)(element &))
{
	recursive_postorder(root,visit);
}

void BinarySearchTree::recursive_postorder(BinaryNode<element> *sub_root, void (*visit)(element &))
{
	if(sub_root!=NULL)
    {
		recursive_postorder(sub_root->left,visit);
		recursive_postorder(sub_root->right,visit);
		(*visit)(sub_root->data);
	}
}

int BinarySearchTree::height() const
{
	if(cnt==0)
        return -1;
	int tmp=1,k;
	for(k=0;tmp<=cnt;k++)//log2size
        tmp*=2;
	return k-1;
};


BinaryNode<Record> *BinarySearchTree::recur_search_for_node
(BinaryNode<Record>* sub_root,const Record &target) const
{
	if(sub_root==NULL||sub_root->data==target)
		return sub_root;
	else if(sub_root->data<target)
		return recur_search_for_node(sub_root->right,target);
    return recur_search_for_node(sub_root->left,target);
}

BinaryNode<Record> *BinarySearchTree::non_recur_search_for_node
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

void BinarySearchTree::tree_search(Record &target) const
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

void BinarySearchTree::insert(const Record &new_data)
{
	if(search_and_insert(&root,new_data))
        cnt++;
}

bool BinarySearchTree::
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

bool BinarySearchTree::remove(const Record &target)
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

bool BinarySearchTree::remove_root(BinaryNode<Record> **sub_root)
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


bool BinarySearchTree::search_and_destroy(BinaryNode<Record>* &sub_root,const Record &target)
//find the node to be deleted
{
	if(sub_root==NULL||sub_root->data==target)
		return remove_root(&sub_root);
	else if(target<sub_root->data)
		return search_and_destroy(sub_root->left,target);
    return search_and_destroy(sub_root->right,target);
}

