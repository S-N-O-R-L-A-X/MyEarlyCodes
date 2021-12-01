#include <iostream>
#include <stdlib.h>
using namespace std;
typedef int type;

struct node
{
    type x;
    node *next;
    node();
    node(type item,node *p=NULL);
};

node::node()
{
    x=0;
    next=NULL;
}

node::node(type item,node *p)
{
    x=item;
    next=NULL;
}

int main()
{
    int n;
    cin>>n;
    node *head=new node();
    node *tail=new node();
    head->next=tail;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        node *p=new node(a);
        tail->next=p;
        tail=p;
    }
    int sum=0;
    for(node *p=head->next;p;)
    {
        sum+=p->x;
        node *q=p->next;
        delete p;
        p=q;
    }

    cout<<sum;
    return 0;
}
