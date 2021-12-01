#ifndef _STDIO_H
#include <stdio.h>
#endif

#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int a[MAXSIZE];
    int top;
}stack;

void push(stack *p,int x)
{
    int i=p->top;
    if(i==MAXSIZE-1)
        printf("full\n");
    else
    {
        (p->top)++;
        i=p->top;
        p->a[i]=x;
    }
}

int pop(stack *p)
{
    if(p->top==-1)
    {
        printf("empty\n");
        //return ERROR;
    }
    else
        return p->a[(p->top)--];
}

typedef struct
{
    int a[MAXSIZE];
    int top1;
    int top2;
}DStack;

void bothpush(DStack *p,int item,int tag)
{
    if(p->top2-p->top1==1)
    {
        printf("full\n");
        return;
    }
    if(tag==1)
        p->a[++(p->top1)]=item;
    else
        p->a[--(p->top2)]=item;
}

int bothpop(DStack *p,int tag)
{
    if(tag==1)
    {
        if(p->top1==-1)
        {
            printf("empty\n");
            return NULL;
        }
        else
            return p->a[(p->top1)--];
    }
    else
    {
        if(p->top2==MAXSIZE)
        {
            printf("empty\n");
            return NULL;
        }
        else
            return p->a[(p->top2)++];

    }
}

typedef struct _node
{
    int data;
    struct _node *next;
}node;

node *createStack()
{
    node *s;
    s=(node *)malloc(sizeof(node));
    s->next=NULL;
    return s;
}

int isempty(node *p)
{
    return (p->next==NULL)
}

void llpush(node *p,int x)
{
    node *pn;
    pn=(node *)malloc(sizeof(node));
    pn->data=x;
    pn->next=p->next;
    p->next=pn->next;
}

int llpop(node *p)
{
    node *p1,*p2;
    int out;
    if(isempty(p))
    {
        printf("empty\n");
        return NULL;
    }
    else
    {
        p1=p->next;
        p->next=p1->next;
        out=p1->data;
        free(p1);
        return out;
    }
}





int main()
{

    return 0;
}
