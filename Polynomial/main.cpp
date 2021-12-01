#include <iostream>

using namespace std;

struct _term
{
    int coef;
    int exp;
};

struct node
{
    _term term;
    node *next;
    node();
    node(int a,int x,node *p=NULL);
};

void append(node **p,const int a,const int x);
void createLinklist(node *cur);
bool PlusTailDeal(node **cur,node *cur1,node *cur2);
bool MinusTailDeal(node **cur,node *cur1,node *cur2);
void nodeInsert(node *head,node *cur1,node *cur2);
node *Pplus(node *head1,node *head2);
node *Pminus(node *head1,node *head2);
node *Pmul(node *head1,node *head2);
void printNegative(node *cur);
void printPositive(node *cur);
void print(node *cur,bool flag);
void printP(node *head);
void del(node *head);


int main()
{
    char op;
    cin>>op;
    int a,x;
    cin>>a>>x;
    node *head1=new node(a,x);
    node *cur1=head1;
    createLinklist(cur1);
    cin>>a>>x;
    node *head2=new node(a,x);
    node *cur2=head2;
    createLinklist(cur2);
    //finish polynomial creating
    node *head;
    if(op=='+')
        head=Pplus(head1,head2);
    else if(op=='-')
        head=Pminus(head1,head2);
    else
        head=Pmul(head1,head2);

    printP(head);
    del(head1);
    del(head2);
    del(head);
    return 0;
}

node::node()
{
    next=NULL;
}

node::node(int a,int x,node *p)
{
    term.coef=a;
    term.exp=x;
    next=p;
}

void createLinklist(node *cur)
{
    int a,x;
    while(cin>>a>>x)
    {
        if(a==0&&x==0)
            break;
        append(&cur,a,x);
    }
}

void append(node **p,int a,int x)
{
    node *q=new node(a,x);
    (*p)->next=q;
    (*p)=q;
}

bool PlusTailDeal(node **cur,node *cur1,node *cur2)
{
    node *q1=cur1;
    node *q2=cur2;
    if(q1==NULL)
    {
        if(q2==NULL)
            return true;
        while(q2)
        {
            append(cur,q2->term.coef,q2->term.exp);
            q2=q2->next;
        }
    }
    if(q2==NULL)
    {
        while(q1)
        {
            append(cur,q1->term.coef,cur1->term.exp);
            q1=q1->next;
        }
        return true;
    }
    return false;
}

bool MinusTailDeal(node **cur,node *cur1,node *cur2)
{
    node *q1=cur1;
    node *q2=cur2;
    if(q1==NULL)
    {
        if(q2==NULL)
            return true;
        while(q2)
        {
            append(cur,-(q2->term.coef),q2->term.exp);
            q2=q2->next;
        }
    }
    if(q2==NULL)
    {
        while(q1)
        {
            append(cur,q1->term.coef,q1->term.exp);
            q1=q1->next;
        }
        return true;
    }
    return false;
}

void nodeInsert(node *head,node *cur1,node *cur2)
{
    int a=(cur1->term.coef)*(cur2->term.coef);
    int x=(cur1->term.exp)+(cur2->term.exp);
    node *p=head->next;
    node *pre=head;
    while(true)
    {
        if(p->term.exp<x)
        {
            node *q=new node(a,x);
            q->next=p;
            pre->next=q;
            break;
        }
        else if(p->term.exp==x)
        {
            if(a+(p->term.coef)==0)
            {
                node *q=p->next;
                delete p;
                pre->next=q;
            }
            else
                (p->term.coef)+=a;
            break;
        }
        pre=pre->next;
        p=p->next;
        if(p==NULL)
        {
            append(&pre,a,x);
            break;
        }
    }
}

node *Pplus(node *head1,node *head2)
{
    node *cur1=head1;
    node *cur2=head2;
    node *head =new node();
    node *cur=head;
    while(true)
    {
        if(cur1->term.exp>cur2->term.exp)
        {
            append(&cur,cur1->term.coef,cur1->term.exp);
            cur1=cur1->next;
        }
        else if(cur1->term.exp<cur2->term.exp)
        {
            append(&cur,cur2->term.coef,cur2->term.exp);
            cur2=cur2->next;
        }
        else
        {
            if((cur1->term.coef)+(cur2->term.coef)!=0)
                append(&cur,(cur1->term.coef)+(cur2->term.coef),cur1->term.exp);
            cur1=cur1->next;
            cur2=cur2->next;
        }
        if(PlusTailDeal(&cur,cur1,cur2))
            break;
    }
    return head;
}

node *Pminus(node *head1,node *head2)
{
    node *cur1=head1;
    node *cur2=head2;
    node *head =new node();
    node *cur=head;
    while(true)
    {
        if(cur1->term.exp>cur2->term.exp)
        {
            append(&cur,cur1->term.coef,cur1->term.exp);
            cur1=cur1->next;
        }
        else if(cur1->term.exp<cur2->term.exp)
        {
            append(&cur,-(cur2->term.coef),cur2->term.exp);
            cur2=cur2->next;
        }
        else
        {
            if((cur1->term.coef)-(cur2->term.coef)!=0)
                append(&cur,(cur1->term.coef)-(cur2->term.coef),cur2->term.exp);
            cur1=cur1->next;
            cur2=cur2->next;
        }
        if(MinusTailDeal(&cur,cur1,cur2))
            break;
    }
    return head;
}

node *Pmul(node *head1,node *head2)
{
    node *cur1=head1;
    node *cur2=head2;
    node *head=new node();
    node *cur=head;
    while(cur1)
    {
        append(&cur,(cur1->term.coef)*(cur2->term.coef),(cur1->term.exp)+(cur2->term.exp));
        cur1=cur1->next;
    }
    cur2=head2->next;
    while(cur2)
    {
        cur1=head1;
        while(cur1)
        {
            nodeInsert(head,cur1,cur2);
            cur1=cur1->next;
        }
        cur2=cur2->next;
    }
    return head;
}

void printNegative(node *cur)
{
    if(cur->term.coef==-1)
    {
        if(cur->term.exp==0)
            cout<<cur->term.coef;
        else
            cout<<'-';
    }
    else
        cout<<cur->term.coef;

    if(cur->term.exp==1)
        cout<<"X";
    else if(cur->term.exp!=0)
        cout<<"X^"<<cur->term.exp;
}

void printPositive(node *cur)
{
    if(cur->term.coef==1)
    {
        if(cur->term.exp==0)
            cout<<'1';
    }
    else
        cout<<cur->term.coef;

    if(cur->term.exp==1)
        cout<<"X";
    else if(cur->term.exp!=0)
        cout<<"X^"<<cur->term.exp;
}

void print(node *cur,bool flag)
{
    if(cur->term.coef<0)
        printNegative(cur);
    else
    {
        if(flag)
            cout<<'+';
        printPositive(cur);
    }
}

void printP(node *head)
{
    node *cur=head->next;
    bool flag=false;//control the output of the sign of the first term
    if(cur==NULL)
    {
        cout<<'0';
        return ;
    }
    while(cur)
    {
        /*
        if(cur->term.exp==0)
        {
            if(flag)
            {
                if(cur->term.coef>0)
                    cout<<'+'<<cur->term.coef;
                else
                    cout<<cur->term.coef;
            }
            else
            {
                if(cur->term.coef>0)
                    cout<<'+'<<cur->term.coef;
                else
                    cout<<cur->term.coef;
            }
        }
        */
        print(cur,flag);
        flag=true;
        cur=cur->next;
    }
}

void del(node *head)
{
    node *p=head->next;
    while(p)
    {
        node *q=p->next;
        delete p;
        p=q;
    }
}


