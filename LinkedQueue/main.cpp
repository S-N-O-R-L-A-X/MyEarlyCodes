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

class LinkedQueue
{
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue &origin);
    bool isempty() const;
    Error_code append(const int x);
    Error_code serve();
    int retrieve();
    void operator =(const LinkedQueue &origin);
    ~LinkedQueue();
protected:
    node *front;
    node *rear;
};

int main()
{
    int x;
    LinkedQueue a;
    while(cin>>x&&x!=-1)
        a.append(x);
    while(!a.isempty())
    {
        cout<<a.retrieve()<<" ";
        a.serve();
    }
    return 0;
}

node::node()
{

}

node::node(int x,node *p)
{
    item=x;
    next=p;
}

LinkedQueue::LinkedQueue()
{
    front=NULL;
    rear=NULL;
}

bool LinkedQueue::isempty() const
{
    if(rear==NULL)
        return true;
    return false;
}

Error_code LinkedQueue::append(const int x)
{
    node *p=new node(x);
    if(p==NULL)
        return overflow;
    if(rear==NULL)
    {
        front=p;
        rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
    return success;
}

Error_code LinkedQueue::serve()
{
    if(isempty())
        return underflow;
    node *q=front;
    delete front;
    front=q->next;
    if(front==NULL)
        rear=NULL;
    return success;
}

int LinkedQueue::retrieve()
{
    if(isempty())
        return underflow;
    return front->item;
}

LinkedQueue::~LinkedQueue()
{
    while(!isempty())
        serve();
}


