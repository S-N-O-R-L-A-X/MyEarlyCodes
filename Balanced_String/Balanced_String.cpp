#include <iostream>
#define maxsize 100

using namespace std;

enum Error_code { underflow, overflow, success };
typedef int type;


class CirQueue
{
public:
    CirQueue();
    bool empty();
    Error_code serve();
    Error_code append(type x);
    //Error_code retrieve(type &y);
    //Error_code serve_retrieve(type &y);
    type serve_retrieve();
    bool full() const;
    int size();
    void clear();

private:
    int front;
    int rear;
    int cnt;
    type queue[maxsize];
};

int main()
{
    int x;
    CirQueue a;
    cout << sizeof(int*);
}

CirQueue::CirQueue()
{
    front = 0;
    rear = maxsize - 1;
    cnt = 0;
}

Error_code CirQueue::append(type x)
{
    if (full())
        return overflow;

    cnt++;
    rear = ((rear + 1) == maxsize) ? 0 : (rear + 1);
    queue[rear] = x;
    return success;
}


Error_code CirQueue::serve()
{
    if (empty())
        return underflow;
    cnt--;
    front = ((front + 1) == maxsize) ? 0 : (front + 1);
    return success;
}

/*
Error_code CirQueue::retrieve(type &y)
{
    if (empty())
        return underflow;
    y = queue[front];
    return success;
}

Error_code CirQueue::serve_retrieve(type& y)
{
    if (empty())
        return underflow;
    cnt--;
    y = queue[front];
    front = ((front + 1) == maxsize) ? 0 : (front + 1);
}*/

int CirQueue::serve_retrieve()
{
    if (empty())
        return -1;
    cnt--;
    int y = queue[front];
    front = ((front + 1) == maxsize) ? 0 : front + 1;
    return y;
}

int CirQueue::size()
{
    return cnt;
}

bool CirQueue::full() const
{
    return cnt == maxsize;
}

bool CirQueue::empty()
{
    return cnt == 0;
}

void CirQueue::clear()
{
    front = 0;
    cnt = 0;
    rear = maxsize - 1;
}
