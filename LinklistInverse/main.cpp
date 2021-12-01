#include <iostream>

using namespace std;
struct node
{
    node();
    node(int x,node *p=NULL);
    int item;
    node *next;
};

int main()
{
    int n;
    cin>>n;
    node *head=new node();
    node *cur=new node();
    head=cur;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        node *p=new node(a);
        cur->next=p;
        cur=p;
    }

    cur=head->next;
    node *follow=cur->next;
    cur->next=NULL;
    while(follow)
	{
	    node *p=follow->next;
		follow->next=cur;
		cur=follow;
		follow=p;
	}
    head=cur;
    node *p=head;
    while(p)
    {
        cout<<p->item<<" ";
        p=p->next;
    }
    return 0;
}

node::node()
{

}

node::node(int x,node *p)
{
    item=x;
    next=NULL;
}
