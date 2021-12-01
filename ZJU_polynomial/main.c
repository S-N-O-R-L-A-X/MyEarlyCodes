#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int coef;
    int expon;
    struct _node *next;
}node;

int compare(node *p1,node *p2)
{
    if(p1->expon==p2->expon)
        return 0;
    else if(p1->expon>p2->expon)
        return 1;
    else
        return -1;
}

void attach(int c,int e,node **rear)//改变指针所指的东西时用指向指针的指针
{
    node *pn;
    pn=(node *)malloc(sizeof(node));
    pn->coef=c;
    pn->expon=e;
    (*rear)->next=pn;
    (*rear)=pn;
}

node *polinomialadd(node *p1,node *p2)
{
    node *front,*rear,*temp;
    int sum;
    rear=(node *)malloc(sizeof(node));
    front=rear;
    while(p1&&p2)
    {
        switch(compare(p1->expon,p2->expon))
        {
            case  0:sum=p1->coef+p2->coef;
                    if(sum)
                        attach(sum,p1->expon,&rear);
                    p1=p1->next;
                    p2=p2->next;
                    break;
            case  1:attach(p1->coef,p1->expon,&rear);
                    p1=p1->next;
                    break;
            case -1:attach(p2->coef,p2->expon,&rear);
                    p2=p2->next;
                    break;
        }
    }
    for(;p1;p1=p1->next)
        attach(p1->coef,p1->expon,&rear);
    for(;p2;p2=p2->next)
        attach(p2->next,p2->expon,&rear);
    rear->next=NULL;
    temp=front;
    front=front->next;
    free(temp);
    return front;
}

int main()
{

    return 0;
}
