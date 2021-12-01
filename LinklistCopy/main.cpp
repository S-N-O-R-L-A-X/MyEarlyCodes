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
    int n,a;
    cin>>n>>a;
    node *head=new node(a);
    node *cur=new node();
    cur=head;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        node *p=new node(a);
        cur->next=p;
        cur=p;
    }

    node *head2=new node(head->item);
    node *cur2=new node();
    cur2=head2;
    cur=head;
    for(int i=0;i<n;i++)
    {
        node *p=new node(cur->item);
        cur=cur->next;
        cur2->next=p;
        cur2=p;
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
