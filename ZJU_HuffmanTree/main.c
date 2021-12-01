#include <stdio.h>
#include <stdlib.h>

typedef struct _treenode
{
    int weight;
    struct _treenode left,right;
}treenode;

typedef struct _set
{
    int data;
    int parent;
}set;

int find(int x,set s[])
{
    int i,key;
    for(i=0;i<maxsize;i++)
    {
        if(s[i].data==x)
            break;
    }
    if(i>=maxsize)
        return -1;
    key=s[i].parent;
    return s[key];
}


void Union(set s[],int x1,int x2)
{
    int root1,root2;
    root1=find(x1,s);
    root2=find(x2,s);
    if(root1!=root2)
        s[root2].parent=root1;
}

int main()
{

    return 0;
}
