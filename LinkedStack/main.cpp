#include <iostream>

using namespace std;

enum Error_code{underflow,overflow,success};

struct node
{
    int item;
    node *next;
    node();
    node(int x,node *p=NULL);
};

class LinkedStack
{
public:
    LinkedStack();
    bool isempty();
//    bool isfull();
    Error_code push(const int x);
    Error_code pop();
    int top();
    ~LinkedStack();
protected:
    node *head;
};


int main()
{
    LinkedStack a;
    int x;
    while(cin>>x&&x!=-1)
    {
        a.push(x);
    }

    while(!a.isempty())
    {
        cout<<a.top()<<" ";
        a.pop();
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
    next=p;
}

LinkedStack::LinkedStack()
{
    head=NULL;
}

bool LinkedStack::isempty()
{
    if(head==NULL)
        return true;
    return false;
}


Error_code LinkedStack::push(const int x)
{

    node *p=new node(x,head);
    if(p==NULL)
        return overflow;
    head=p;
    return success;
}

Error_code LinkedStack::pop()
{
    if(isempty())
        return underflow;
    node *q=head->next;
    delete head;
    head=q;
}

int LinkedStack::top()
{
    if(isempty())
        return -1;
    return head->item;
}

LinkedStack::~LinkedStack()
{
    while(!isempty())
        pop();
}





