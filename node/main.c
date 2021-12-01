#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int a;
    struct link *next;
}node;

typedef struct list
{
    node *head;
//    node *last;
}ll;


void addnode(ll *plist,int num);
void printlinklist(ll *linklist);
void find(ll *linklist,int search);

int main()
{
    ll linklist;
    linklist.head=NULL;
//    linklist.last=NULL;
    int num,search;

    while(scanf(" %d",&num))
    {
        if(num==-1)
            break;
        else
        {
            addnode(&linklist,num);
            /*if(linklist.last)
            {
                last->next=p;
            }
            else
                linklist.head=p;*/
        }
    }
    scanf(" %d",&search);
    find(&linklist,search);
    printf("\n");
    printlinklist(&linklist);
    return 0;
}





void addnode(ll *plist,int num)
{
    node *p=(node *)malloc(sizeof(node));
    p->a=num;
    p->next=NULL;
    node *last=plist->head;
    if(last)
    {
        while(last->next)
            last=last->next;
        last->next=p;
    }
    else
        plist->head=p;
}

void printlinklist(ll *linklist)
{
    node *p;
    for(p=linklist->head;p;p=p->next)
        printf("%d\n",p->a);
}

void find(ll *linklist,int search)
{
    node *p;
    int flag=0;
    for(p=linklist->head;p;p=p->next)
    {
        if(p->a==search)
        {
            flag=1;
            printf("found\n");
            break;
        }
    }
    if(flag==0)
        printf("not found\n");
}

void del(ll *linklist,int search)
{
    node *p,*q;
    for(q=NULL,p=linklist->head;p,q;q=p,p=p->next)
    {
        if(p->a==search)
        {
            if(q)
                p->next=linklist->head;
            else
                q->next=p->next;
            free(p);
            break;
        }
    }
}
