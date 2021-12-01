#include <iostream>

using namespace std;
struct node
{
    node();
    node(int x,node *p=NULL);
    int item;
    node *next;
//    node *pre;
};

int main()
{
    int n,m;
    cin>>n>>m;
    node *head=new node(1);
    node *cur=new node();
    cur=head;
    node *pre;
    for(int i=2;i<=n;i++)
    {
        node *p=new node(i);
        cur->next=p;
//        p->pre=cur;
        cur=p;
        if(i==n)
        {
            p->next=head;
            pre=p;
        }
    }
    node *p=head;

    int k=1;//because the head doesn't count
    int cnt=1;
    while(cnt!=n)
    {
        if(k==m)
        {
            pre->next=p->next;
            delete p;
            p=pre->next;
            k=1;
            cnt++;
        }
        else
        {
            pre=pre->next;
            p=p->next;
            k++;
        }
    }
    cout<<p->item;
    return 0;
}

node::node()
{
//    pre=NULL;
    next=NULL;
}

node::node(int x,node *p)
{
    item=x;
//    pre=NULL;
    next=NULL;
}
