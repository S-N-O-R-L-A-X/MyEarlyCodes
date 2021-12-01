#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct list
{
    int a[MAX_SIZE];
    int last;
}LinearList;

LinearList *initialize()
{
    LinearList *p;
    p=(LinearList *)malloc(sizeof(LinearList));
    p->last=-1;
    return p;
}

int search(int x,LinearList *p)
{
    for(int i=0;i<=p->last;i++)
    {
        if(p->a[i]==x)
            return i;
    }
    return -1;
}

void insert(LinearList *p,int place,int element)
{
    if(p->last==MAX_SIZE-1)
    {
        printf("full\n");
        return;
    }
    if(place>p->last+2||place<1)
    {
        printf("no such place\n");
        return;
    }
    for(int i=p->last;i>=place-1;i--)
    {
        p->a[i+1]=p->a[i];
    }
    p->a[place-1]=element;
    p->last++;
    return;
}

void del(LinearList *p,int place)
{
    if(place>p->last||place<1)
    {
        printf("no such element\n");
        return;
    }
    for(int i=place;i<=p->last-1;i++)
        p->a[i]=p->a[i+1];
    p->last--;
}

//--------------------------------------------------below the line is linklist
typedef struct  _node
{
    int data;
    struct _node *ptr;
}node;

int length(node *p)
{
    node *p1=p;
    int s=0;
    while(p1)
    {
        s++;
        p1=p1->ptr;
    }
    return s;
}

int llsearch(node *p,int key)
{
    int cnt=0;
    node *p1;
    for(p1=p;p1;p1=p1->ptr)
    {
        if(p1->data==key)
            return cnt;
        cnt++;
    }
}

node *nllsearch(node *p,int key)
{
    node *p1;
    for(p1=p;p1;p1=p1->ptr)
    {
        if(p1->data==key)
            return p1;
    }
}


node *check(node *p,int i)
{
    int j=0;
    node *p1=p;
    while(j<=i&&p1!=NULL)
    {
        p1=p1->ptr;
        j++;
    }
    return p1;
}

node * llinsert(node *p,int place,int x)
{
    node *p1,*p2,*ins;

    if(place==1)
    {
        p1=(node*)malloc(sizeof(node));
        p1->data=x;
        p1->ptr=p;
        return p1;
    }
    else
    {
        p2=check(p,place-1);
        if(p2)
        {
            ins=(node *)malloc(sizeof(node));
            ins->data=x;
            ins->ptr=p2->ptr;
            p2->ptr=ins;
            return p;
        }
        else
            return p;
    }
}

node *lldelete(node *p,int place)
{
    node *p1,*p2;
    if(i==0)
    {
        p1=p;
        if(p1)
            p=p->ptr;
        else
            return NULL;
        return p->ptr;
    }
    else
    {
        p1=check(p,place-1)
        p2=check(p,place);
        if(p1)
        {
            p1->ptr=p2->next;
            free(p2)
            return p;
        }
        else
            return p;
    }
}

int main()
{

    return 0;
}
