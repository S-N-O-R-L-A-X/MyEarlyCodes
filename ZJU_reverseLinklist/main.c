#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
}node;

node *reverseLinklist(node *p,int n)
{
    node *old,*temp,*now;
    now=p->next;
    old=now->next;
    for(int i=1;i<=n;i++)
    {
        temp=old->next;
        old->next=now;
        now=old;
        old=temp;
    }
    p->next->next=old;
    return p;
}

int main()
{

    return 0;
}
