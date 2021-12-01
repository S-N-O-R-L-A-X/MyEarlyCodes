#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int front;
    int rear;
    int a[MAXSIZE];
}queue;
/*
It could be found that the queue has MAXSIZE+1 kinds of situations but
the distance between front and rear is MAXSIZE,so the array should be
diminished one.
*/
void  qadd(queue *p,int x)
{
    if((p->rear+1)%MAXSIZE==p->front)
        printf("full\n");
    else
    {
        p->rear=(p->rear+1)%MAXSIZE;
        p->a[p->rear]=x;
    }
}

int qout(queue *q)
{
    if(q->front==q->rear)
    {
        printf("empty\n");
        return -250;
    }
    else
        q->front=(q->front+1)%MAXSIZE;
    return q->a[q->front];

}

//-----------------------------------------

typedef struct _node
{
    int data;
    struct _node *next;
}node;

typedef struct _llqueue
{
    node *front;
    node *rear;
}llqueue;

int llqout(llqueue *p)
{
    node *pn=p->front;
    int x;
    if(p->front==NULL)
    {
        printf("empty\n");
        return -250;
    }
    else
    {
        if(p->front==p->rear)
            p->front=p->rear=NULL;
        else
            p->front=p->front->next;
        x=pn->data;
        free(pn);
        return x;
    }
}

int main()
{

    return 0;
}
