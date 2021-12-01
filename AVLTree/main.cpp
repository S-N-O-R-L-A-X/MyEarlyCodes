#include <iostream>

using namespace std;

enum Balance_factor { left_higher, equal_height, right_higher};
enum Error_code{success,duplicate_error,not_present};

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
bool operator <(const Record &x,const Record &y);
bool operator >(const Record &x,const Record &y);

struct AVLNode
{
// additional data member:
	Balance_factor balance;
    Record data;
	AVLNode *left;
	AVLNode *right;
// constructors:
	AVLNode( );
	AVLNode(const Record &x);
//factor
	void set_balance(Balance_factor b);
	Balance_factor get_balance() const;
};

class AVLTree
{
public:
    AVLTree();
	Error_code insert(const Record &new_data);
	Error_code remove(Record &old_data);
   //查找
    Error_code tree_search(Record &target) const;
private: // Add auxiliary function prototypes here.
	Error_code avl_insert(AVLNode **sub_root,const Record &new_data, bool *taller);
    void modify_balance_left_insert(AVLNode **sub_root,bool *taller);
    void modify_balance_right_insert(AVLNode **sub_root,bool *taller);

	void rotate_left(AVLNode **sub_root);
	void rotate_right(AVLNode **sub_root);
	void right_balance(AVLNode **sub_root);
	void left_balance(AVLNode **sub_root);
    AVLNode *non_recur_search(AVLNode *sub_root,const Record &target) const;

	Error_code avl_remove(AVLNode *&sub_root,Record &old_data, bool *shorter);
    bool delete_node(AVLNode **sub_root,AVLNode **to_delete,bool *shorter,Record &old_data,Record &sub_record);
    void modify_balance_left_remove(AVLNode **sub_root,bool *shorter);
    void modify_balance_right_remove(AVLNode **sub_root,bool *shorter);


    void right_sub_tree_modify_balance
    (AVLNode *&sub_root,AVLNode *&sub_tree,AVLNode *&right_tree);
    void left_sub_tree_modify_balance
    (AVLNode *&sub_root,AVLNode *&sub_tree,AVLNode *&left_tree);
    bool right_balance2(AVLNode *&sub_root);
	bool left_balance2(AVLNode *&sub_root);

    AVLNode * root;
};

int main()
{
    int n;
    AVLTree a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string tmpkey,tmpother;
        cin>>tmpkey>>tmpother;
        Record tmp(tmpkey,tmpother);
        a.insert(tmp);
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string del;
        cin>>del;
        Record tmp(del);
        a.remove(tmp);
    }
    string idx,idx2;
    cin>>idx;
    Record tmp(idx);
    a.tree_search(tmp);
    cin>>idx2;
    Record tmp2(idx2);
    a.tree_search(tmp2);
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

bool operator < (const Record &x,const Record &y)
{
	return x.the_key()<y.the_key();
}

bool operator > (const Record &x,const Record &y)
{
	return x.the_key()>y.the_key();
}

AVLNode::AVLNode()
{
	left = NULL;
	right = NULL;
	balance = equal_height;
}


AVLNode::AVLNode(const Record &x)
{
	data = x;
	left = NULL;
	right = NULL;
	balance = equal_height;
}

void AVLNode::set_balance(Balance_factor b)
{
	balance = b;
}


Balance_factor AVLNode::get_balance() const
{
	return balance;
}

AVLTree::AVLTree()
{
    root=NULL;
}

Error_code AVLTree::insert(const Record &new_data)
{
	bool taller; // Has the tree grown in height?
	return avl_insert(&root,new_data,&taller);
    //taller records whether the tree will become taller
}

void AVLTree::modify_balance_left_insert(AVLNode **sub_root,bool *taller)
{
    switch((*sub_root)->get_balance())
    { // Change balance factors.
        case left_higher:
            left_balance(sub_root);
            *taller=false;//Rebalancing always shortens the tree.
            break;
        case equal_height:
            (*sub_root)->set_balance(left_higher);
            break;
        case right_higher:
            (*sub_root)->set_balance(equal_height);
            *taller=false;
            break;
    }
}

void AVLTree::modify_balance_right_insert(AVLNode **sub_root,bool *taller)
{
    switch((*sub_root)->get_balance())
    {
        case left_higher:
            (*sub_root)->set_balance(equal_height);
            *taller = false;
            break;
        case equal_height:
            (*sub_root)->set_balance(right_higher);
            break;
        case right_higher:
            right_balance(sub_root);
            *taller = false; // Rebalancing always shortens the tree.
            break;
    }
}

Error_code AVLTree::avl_insert(AVLNode **sub_root,const Record &new_data,bool *taller)
{
	Error_code result=success;
	if(*sub_root==NULL)
    {
		*sub_root=new AVLNode(new_data);
		*taller=true;
	}
	else if(new_data==(*sub_root)->data)
    {
		result=duplicate_error;
		*taller=false;
	}
    else if(new_data<(*sub_root)->data)// Insert in left subtree.
    {
		result=avl_insert(&((*sub_root)->left),new_data,taller);
		if(*taller==true)
            modify_balance_left_insert(sub_root,taller);
	}
    else
    { // Insert in right subtree.
		result=avl_insert(&((*sub_root)->right),new_data,taller);
		if(*taller==true)
            modify_balance_right_insert(sub_root,taller);
	}
	return result;
}

void AVLTree::rotate_left(AVLNode **sub_root)
/*
the sub_root will be reset to point to its former right child,
and the former sub_root node is the left child of the new sub_root node.
*/
{
	if(*sub_root==NULL||(*sub_root)->right==NULL) // impossible cases
		cout << "WARNING: program error detected in rotate left" << endl;
	else
    {
		AVLNode *right_tree=(*sub_root)->right;
		(*sub_root)->right=right_tree->left;
		right_tree->left=*sub_root;
		*sub_root=right_tree;
	}
}

void AVLTree::rotate_right(AVLNode **sub_root)
/* Pre: sub_root points to a subtree of the AVL tree . This subtree has a nonempty
left subtree.
Post: sub_root is reset to point to its former left child, and the former sub_root
node is the right child of the new sub_root node. */
{
	if (*sub_root==NULL||(*sub_root)->left==NULL) // impossible cases
		cout<<"WARNING: program error detected in rotate right" << endl;
	else
    {
		AVLNode *left_tree=(*sub_root)->left;
		(*sub_root)->left=left_tree->right;
		left_tree->right=*sub_root;
		*sub_root=left_tree;
	}
}

void AVLTree::right_balance(AVLNode **sub_root)//right is 2 layers high than left
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the right.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
	AVLNode *&right_tree=(*sub_root)->right;
	switch(right_tree->get_balance())
	{
        case right_higher: // single rotation left
            (*sub_root)->set_balance(equal_height);
            right_tree->set_balance(equal_height);
            rotate_left(sub_root);
            break;
        case equal_height: // impossible case because taller == true
            cout << "WARNING: program error in right balance" << endl;
            break;
        case left_higher: // double rotation left
            AVLNode *sub_tree = right_tree->left;
            switch (sub_tree->get_balance( ))
            {
                case equal_height:
                    (*sub_root)->set_balance(equal_height);
                    right_tree->set_balance(equal_height);
                    break;
                case left_higher: //T2 is h, T3 is h-1
                    (*sub_root)->set_balance(equal_height);
                    right_tree->set_balance(right_higher);
                    break;
                case right_higher: //T2 is h-1, T3 is h
                    (*sub_root)->set_balance(left_higher);
                    right_tree->set_balance(equal_height);
                    break;
            }
            sub_tree->set_balance(equal_height);
            rotate_right(&right_tree);
            rotate_left(sub_root);
            break;
	}
}

void AVLTree::left_balance(AVLNode **sub_root)//left is 2 layers higher than right
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the left.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
	AVLNode * &left_tree = (*sub_root)->left;
	switch (left_tree->get_balance( )) {
	case left_higher: // single rotation left
		(*sub_root)->set_balance(equal_height);
		left_tree->set_balance(equal_height);
		rotate_right(sub_root);
		break;
	case equal_height: // impossible case
		cout << "WARNING: program error in right balance" << endl;
        break;
	case right_higher: // double rotation left
		AVLNode *sub_tree = left_tree->right;
		switch (sub_tree->get_balance( )) {
		case equal_height:
			(*sub_root)->set_balance(equal_height);
			left_tree->set_balance(equal_height);
			break;
		case right_higher:
			(*sub_root)->set_balance(equal_height);
			left_tree->set_balance(left_higher);
			break;
		case left_higher:
			(*sub_root)->set_balance(right_higher);
			left_tree->set_balance(equal_height);
			break;
		}
		sub_tree->set_balance(equal_height);
		rotate_left(&left_tree);
		rotate_right(sub_root);
		break;
	}
}

Error_code AVLTree::remove(Record &new_data)
{
	bool shorter=true;//shorter records whether the tree will become shorter
	return avl_remove(root,new_data,&shorter);
}

void AVLTree::modify_balance_left_remove(AVLNode **sub_root,bool *shorter)
{
    switch((*sub_root)->get_balance())
    { // Change balance factors.
        case left_higher:
            (*sub_root)->set_balance(equal_height);
            break;
        case equal_height:
            (*sub_root)->set_balance(right_higher);
            *shorter = false;
            break;
        case right_higher:
            *shorter = right_balance2(*sub_root);
            break;
    }
}

void AVLTree::modify_balance_right_remove(AVLNode **sub_root,bool *shorter)
{
    switch((*sub_root)->get_balance())// Change balance factors.
    {
        case left_higher:
            *shorter=left_balance2(*sub_root);
            break;
        case equal_height:
            (*sub_root)->set_balance(left_higher);
            *shorter=false;
            break;
        case right_higher:
            (*sub_root)->set_balance(equal_height);
            break;
    }
}

bool AVLTree::delete_node(AVLNode **sub_root,AVLNode **to_delete,bool *shorter,Record &old_data,Record &sub_record)
{
    AVLNode *p=*sub_root;
    if(p->right==NULL)
    {
        p=p->left;
        *shorter=true;
        *sub_root=p;
        delete *to_delete; // Remove to_delete from tree.
        return true;
    }
    else if(p->left==NULL)
    {
        p=p->right;
        *shorter=true;
        *sub_root=p;
        delete *to_delete;// Remove to_delete from tree.
        return true;
    }

    // Neither subtree is empty.
    p=(*sub_root)->left;// Move left to find predecessor.
    AVLNode *parent=*sub_root;// parent of to_delete
    while(p->right!=NULL)
    {
        // to_delete is not the predecessor.
        parent=p;
        p=p->right;
    }
    old_data=p->data;
    sub_record=old_data; //record delete
    *to_delete=p;
    return false;
}

Error_code AVLTree::avl_remove(AVLNode*&sub_root,Record &old_data,bool *shorter)
//function:delete predecessor
{
	Error_code result=success;
    Record sub_record;
	if(sub_root==NULL)
    {
		*shorter=false;
		return not_present;
	}
    else if(old_data==sub_root->data)//delete the node,the same as binary search tree
    {
		AVLNode *to_delete=sub_root;// Remember node to delete at end.
		if(delete_node(&sub_root,&to_delete,shorter,old_data,sub_record))
            return success;
	}
    if(old_data<sub_root->data)//the node is in left subtree.
    {
		result=avl_remove(sub_root->left,old_data,shorter);
		if(sub_record.the_other()!="NULL")// Move data from to_delete to root.
            sub_root->data=sub_record;

		if(*shorter==true)
            modify_balance_left_remove(&sub_root,shorter);
	}
	if(old_data>sub_root->data)//the node is in right subtree.
    {
		result=avl_remove(sub_root->right,old_data,shorter);
		if(sub_record.the_other()!="NULL")
            sub_root->data=sub_record;// Move data from to_delete to root.
		if(*shorter==true)
            modify_balance_right_remove(&sub_root,shorter);
	}
	return result;
}

void AVLTree::right_sub_tree_modify_balance
(AVLNode *&sub_root,AVLNode *&sub_tree,AVLNode *&right_tree)
{
    switch(sub_tree->get_balance())
    {
        case equal_height:
            sub_root->set_balance(equal_height);
            right_tree->set_balance(equal_height);
            break;
        case left_higher:
            sub_root->set_balance(equal_height);
            right_tree->set_balance(right_higher);
            break;
        case right_higher:
            sub_root->set_balance(left_higher);
            right_tree->set_balance(equal_height);
            break;
    }
}

bool AVLTree::right_balance2(AVLNode * &sub_root)
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the right.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
	bool shorter;
	AVLNode *&right_tree=sub_root->right;
	switch(right_tree->get_balance())
	{
        case right_higher: // single rotation left
            sub_root->set_balance(equal_height);
            right_tree->set_balance(equal_height);
            rotate_left(&sub_root);
            shorter=true;
            break;
        case equal_height:// single rotation left  R-型，左转后高度不变
            right_tree->set_balance(left_higher);
            rotate_left(&sub_root);
            shorter = false;
            break;

        case left_higher: // double rotation left
            AVLNode *sub_tree=right_tree->left;
            right_sub_tree_modify_balance(sub_root,sub_tree,right_tree);
            sub_tree->set_balance(equal_height);
            rotate_right(&right_tree);
            rotate_left(&sub_root);
            shorter = true;
            break;
	}
	return shorter;
}

void AVLTree::left_sub_tree_modify_balance
(AVLNode *&sub_root,AVLNode *&sub_tree,AVLNode *&left_tree)
{
    switch(sub_tree->get_balance())
    {
        case equal_height:
            sub_root->set_balance(equal_height);
            left_tree->set_balance(equal_height);
            break;
        case left_higher:
            sub_root->set_balance(equal_height);
            left_tree->set_balance(left_higher);
            break;
        case right_higher:
            sub_root->set_balance(right_higher);
            left_tree->set_balance(equal_height);
            break;
    }
}

bool AVLTree::left_balance2(AVLNode *&sub_root)
/* Pre: sub root points to a subtree of an AVL tree , doubly unbalanced on the right.
Post: The AVL properties have been restored to the subtree.
Uses: Methods of struct AVL node ; functions rotate_right ,rotate_left . */
{
	bool shorter;
	AVLNode *&left_tree=sub_root->left;
	switch(left_tree->get_balance())
	{
         case left_higher://single rotation left
            sub_root->set_balance(equal_height);
            left_tree->set_balance(equal_height);
            rotate_right(&sub_root);
            shorter=true;
            break;

        case equal_height://single rotation left  L-型，左转后高度不变
            left_tree->set_balance(left_higher);
            rotate_right(&sub_root);
            shorter=false;
            break;

        case right_higher://double rotation right
            AVLNode *sub_tree=left_tree->left;
            left_sub_tree_modify_balance(sub_root,sub_tree,left_tree);
            sub_tree->set_balance(equal_height);
            rotate_left(&left_tree);
            rotate_right(&sub_root);
            shorter=true;
            break;
	}
	return shorter;
}

Error_code AVLTree::tree_search(Record &target) const
{
	AVLNode *found=non_recur_search(root,target);
	if(found==NULL)
        cout<<"NULL"<<endl;
	else
	    cout<<found->data.the_key()<<' '<<found->data.the_other()<<endl;
    return success;
}

AVLNode * AVLTree::non_recur_search(AVLNode *sub_root,const Record &target) const
{
    AVLNode *tmpsub_root=sub_root;
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

/*
test:
6 computer 电脑 eye 眼睛 hello 你好 train 火车 wait 等待 zebra 斑马
1 eye
hello
eye
*/
