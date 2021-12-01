#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node();
    node(int x,node *p=NULL);
    int item;
    node *next;
};

node::node()
{
    next=NULL;
}

node::node(int x,node *p)
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

    for(int i=0;i<n;i++)
    {
        cin>>a;
        node *p=new node(a);
        cur->next=p;
        cur=p;
    }
    int post,ins;
    cin>>post>>ins;
    node *p=head->next;
    int cnt=1;
    while(p)
    {
        if(p->item==post)
        {
            node *now=new node(ins);
            now->next=p->next;
            p->next=now;
            printf("%d ",cnt);
        }
        p=p->next;
        cnt++;
    }

    return 0;
}
