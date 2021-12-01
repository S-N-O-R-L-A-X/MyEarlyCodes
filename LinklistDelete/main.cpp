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

node* createLinklist(int n);


int main()
{
    int n;
    cin>>n;
    node *head=createLinklist(n);
    int del;
    cin>>del;
    node *p=head->next;
    while(p!=NULL&&p->item==del)
    {
        head->next=(head->next)->next;
        p=head;
    }
    node *pre=head;
    p=head->next;
    while(p!=NULL&&pre!=NULL)
    {
        if(p->item==del)
        {
            pre->next=p->next;
            p=p->next;
            continue;
        }
        pre=p;
        p=p->next;
    }

    p=head->next;
    while(p)
    {
        printf("%d ",p->item);
        p=p->next;
    }
    return 0;
}


node::node()
{
    next=NULL;
}

node::node(int x,node *p)
{
    item=x;
    next=NULL;
}

node* createLinklist(int n)
{
    node *head=new node();
    node *cur=new node();
    cur=head;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        node *p=new node(a);
        cur->next=p;
        cur=p;
    }
    return head;
}
