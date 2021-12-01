#include <iostream>

using namespace std;

typedef int element;

struct node
{
    element item;
    node *next;
    node();
    node(element x,node *p=NULL);
};

void print(node *head)
{
    for(node *p=head;p;p=p->next)
        cout<<p->item<<' ';
}

void initialize(node **head)
{
    int x;
    cin>>x;
    if(x!=-1)
    {
        (*head)=new node(x);
        node *cur=(*head);
        while(cin>>x&&x!=-1)
        {
            node *p=new node(x);
            cur->next=p;
            cur=p;
        }
    }
}

void func(node *head1,node *head2)
{
    node *cur1=head1->next;
    node *pre1=head1;

    for(node *cur2=head2;cur2;cur2=cur2->next)
    {
        while(cur1)
        {
            if(cur1->item>cur2->item)
                break;
            pre1=cur1;
            cur1=cur1->next;
        }
        node *tmp=new node(cur2->item,cur1);
        pre1->next=tmp;
        pre1=tmp;
    }
    print(head1);
}

int main()
{
    node *La=NULL,*Lb=NULL;
    initialize(&La);
    initialize(&Lb);
    if(La&&Lb)
    {
        if(La->item<Lb->item)
            func(La,Lb);
        else
            func(Lb,La);
    }
    else
    {
        if(La==NULL)
            print(Lb);
        else
            print(La);
    }
    return 0;
}


node::node()
{
    next=NULL;
}

node::node(element x,node *p)
{
    item=x;
    next=p;
}
