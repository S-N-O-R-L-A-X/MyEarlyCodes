#include <stdio.h>
#include <stdlib.h>
#define MAXN 1001
#define MINH -10001


typedef struct _heap
{
    int arr[MAXN];
    int size;
    int capacity;
}heap;

 create()
{
    size=0;

}

heap *createHeap(int maxsize)
{
    heap *h=malloc(sizeof(heap));
    h->arr=malloc((maxsize+1)*sizeof(int));
    h->size=0;
    h->capacity=maxsize;
    h->arr[0]=10000000;
    return h;
}

void heapInsert(heap *p,int item)
{
    int i;
    if(isfull(p))
    {
        printf("full\n")
        return ;
    }
    i=++p->size;
    for(;p->arr[i/2]<item;i/=2)
        p->arr[i]=p->arr[i/2];
    p->arr[i]=item;

}

int deletemax(heap *p)
{
    int parent,child;
    int max,temp;
    if(isempty(p))
    {
        printf("empty!\n");
        return ;
    }
    max=p->arr[i];
    temp=p->arr[p->size--];
    for(parent=1;parent*2<=p->size;parent=child)//判断条件：是否有儿子节点
    {
        child=parent*2;
        if((child!=p->size)&&(p->arr[child]<p->arr[child+1]))
            child++;//找出左右儿子中较大的那个
        if(temp>=p->arr[child])
            break;
        else
            p->arr[parent]=p->arr[child];
    }
    p->arr[parent]=temp;
    return max;
}

int main()
{

    return 0;
}
