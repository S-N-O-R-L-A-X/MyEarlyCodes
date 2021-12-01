#include <iostream>
#include <stdio.h>
using namespace std;

typedef int type;

struct node
{
    node();
    node(type x,node *p=NULL);
    type item;
    node *next;
};

node::node()
{
    next=NULL;
}

node::node(type x,node *p)
{
    item=x;
    next=NULL;
}

int main()
{
    int n,a;
    cin>>n;
    node *head=new node();
    node *cur=new node();
    cur=head;
    for(int k=0;k<n;k++)
    {
        cin>>a;
        node *p=new node(a);
        cur->next=p;
        cur=p;
    }
    delete cur;
    int i,j;
    cin>>i>>j;

    int k=-1;
    node *p=head;
    while(p)
    {
        if(k>=i&&k<=j)
            printf("%d ",p->item);
        k++;
        node *q=p->next;
        delete p;
        p=q;
    }

    return 0;
}
