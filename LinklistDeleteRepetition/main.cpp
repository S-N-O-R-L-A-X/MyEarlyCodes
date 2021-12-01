#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node();
    node(const int x,node *p=NULL);
    int item;
    node *next;
};

void print(node *p);

int main()
{
    int n,x;
    cin>>n>>x;
    node *head=new node(x);
    node *cur=new node();
    cur=head;
    for(int i=1;i<n;i++)
    {
        cin>>x;
        node *p=new node(x);
        cur->next=p;
        cur=p;
    }

    node *comp=head;

    while(comp)
    {
        node *p=comp->next;
        node *pre=comp;
        while(p)
        {
            if(p->item==comp->item)
            {
                node *q=p->next;
                pre->next=q;
                if(q)
                {
                    delete p;
                    p=q;
                    continue;
                }
                else
                    break;
            }
            pre=pre->next;
            p=p->next;
        }
        comp=comp->next;
    }
    print(head);

    return 0;
}


node::node()
{

}

node::node(const int x,node *p)
{
    item=x;
    next=NULL;
}

void print(node *p)
{
    node *q=p;
    while(q)
    {
        cout<<q->item<<" ";
        q=q->next;
    }
}
