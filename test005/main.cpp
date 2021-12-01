int height(Binary_node *root);

//returns the of the height of the Binarytree

//the class Binary_node is like below, it is also for question 6.

struct Binary_node {

// data members:

       int data;

       Binary_node  *left;

       Binary_node  *right;

// constructors:

       Binary_node( );

       Binary_node(const int &x);

};

int main()
{
    return 0 ;
}

int height(Binary_node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
}

int Sortable_list::partition(int low,int high,double mean,double mean1,double mean2)
{
	Record pivot;
	int i,last_small;
	pivot = mean; // First entry is now pivot .
	last_small = low; //初始化为最小的位置
	for(i = low; i <= high; i++)
    {
        if (entry[i] < pivot)
        {
			last_small ++; //从low+1开始放置。
			swap(last_small,i); // Move large entry to right and small to left.
		}
    }

	return last_small;
}
