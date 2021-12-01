#include <iostream>
#define maxsize 100

using namespace std;
typedef char type;

enum Error_code{underflow,overflow,success};

class deque
{
public:
    deque();
    Error_code append_rear(type x);
    Error_code append_front(type x);
    type Rserve_retrieve();
    type Fserve_retrieve();
private:
    int front;
    int rear;
    int cnt;
    type arr[maxsize];
};

int main()
{
    int n;
    deque a;
    cin >> n;
    char ch;
    while (cin >> ch)
    {
        a.append_rear(ch);
        if (cin.get() == '\n')
            break;
    }
        
    for (int i = 0; i < n; i++)
        cout << a.Rserve_retrieve()<<' ';
}

deque::deque()
{
    front = 0;
    rear = maxsize - 1;
    cnt = 0;
}

Error_code deque::append_front(type x)
{
    if (cnt == maxsize)
        return overflow;
    cnt++;
    front = (front - 1 + maxsize) % maxsize;
    arr[front] = x;
    return success;
}

Error_code deque::append_rear(type x)
{
    if (cnt == maxsize)
        return overflow;
    cnt++;
    rear = (rear + 1) % maxsize;
    arr[rear] = x;
    return success;
}

type deque::Rserve_retrieve()
{
    if (cnt == 0)
        return -1;
    cnt--;
    char ch = arr[rear];
    rear = (rear - 1 + maxsize) % maxsize;
    return ch;
}

type deque::Fserve_retrieve()
{
    if (cnt == 0)
        return -1;
    cnt--;
    char ch = arr[front];
    front = (front + 1) % maxsize;
    return ch;
}