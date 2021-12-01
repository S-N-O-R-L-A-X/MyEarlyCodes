#include <stdio.h>
#include <stdlib.h>
#define maxtree 10
#define elementType char

typedef struct
{
    int data[101];//data[0] is the guard
    int length;
}LinearList;

typedef struct _treenode
{
    int data;
    struct _treenode *left;
    struct _treenode *right;
}treenode;


int binary_search(LinearList *p,int key)
{
    int left,right,mid;
    left=1;
    right=p->length;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(p->data[mid]==key)
            return mid;
        else if(p->data[mid]>key)
            right=mid-1;
        else
            left=mid+1;
    }
    return -1;//mean not found
}

void PreOrderTraversal(treenode *p)
{
    if(p)
    {
        printf("%d\n",p->data);
        PreOrderTraversal(p->left);
        PreOrderTraversal(p->right);
    }
}

void InOrderTraversal(treenode *p)
{
    if(p)
    {
        InOrderTraversal(p->left);
        printf("%d\n",p->data);
        InOrderTraversal(p->right);
    }
}

void PostOrderTraversal(treenode *p)
{
    if(p)
    {
        PostOrderTraversal(p->left);
        PostOrderTraversal(p->right);
        printf("%d\n",p->data);
    }
}


void printleave(treenode *p)
{
    if(p)
    {
        if(!p->left&&!p->right)
            printf("%d\n",p->data);
        PreOrderTraversal(p->left);
        PreOrderTraversal(p->right);
    }
}

int treeHeight(treenode *p)
{
    int hmax,hl,hr;
    if(p)
    {
        hl=treeHeight(p->left);
        hr=treeHeight(p->right);
        hmax=(hl>hr)?hl:hr;
        return (hmax+1);
    }
    else
        return 0;
}

typedef struct _treearray
{
    elementType data;
    int left;
    int right;
}treearray;

int createTree(treearray p[])
{
    int root;
    int n,i;
    char cl,cr;
    int check[n];
    scanf("%d",&n);
    getchar();
    if(n)
    {
        for(i=0;i<=n-1;i++)
            check[i]=0;
        for(i=0;i<=n-1;i++)
        {
            scanf("%c %c %c",&p[i].data,&cl,&cr);
            if(cl!='-')
            {
                p[i].left=cl-'0';
                check[p[i].left]=1;
            }
            else
                p[i].left=-1;
            if(cr!='-')
            {
                p[i].right=cr-'0';
                check[p[i].right]=1;
            }
            else
                p[i].right=-1;
            getchar();
        }
        for(i=0;i<=n-1;i++)
        {
            if(!check[i])
                break;
        }
        root=i;
    }
    return root;
}
/*
int ismorphic(int root1,int root2,treearray *tree1,treearray *tree2)
{
    if(root1==-1&&root2==-1)
        return 1;
    if((root1!=-1&&root2==-1)||(root1==-1&root2!=-1))
        return 0;
    if(tree1[root1].data!=tree2[root2].data)
        return 0;
    if(tree1[root1].left==-1&&tree2[root2].left==-1)
        return ismorphic(tree1[root1].right,tree2[root2].right,);

}
*/
treenode *find(int key,treenode *tree)
{
    if(!tree)
        return -1;
    else
    {
        if(key>tree->data)
            return find(key,tree->right);
        else if(key<tree->data)
            return find(key,tree->left);
        else
            return tree;
    }
}

treenode *while_find(int key,treenode *tree)
{
    while(tree)
    {
        if(key>tree->data)
            tree=tree->right;
        else if(key<tree->data)
            tree=tree->left;
        else
            return tree;
    }
    return NULL;
}

treenode *findmin(treenode *p)
{
    if(!p)
        return -1;
    while(p->left)
        p=p->left;
    return p;
}

treenode *insert(int key,treenode *tree)
{
    while(tree)
    {
        if(key>tree->data)
        {
            if(tree->right)
                tree=tree->right;
            else
            {
                treenode *q=(treenode *)malloc(sizeof(treenode));

                q=tree->right;
                q->data=key;
            }
        }
        else if(key<tree->data)
        {
            if(tree->left)
                tree=tree->left;
            else
            {
                treenode *q=(treenode *)malloc(sizeof(treenode))
                q=tree->left;
                q->data=key;
            }
        }
        else
            return tree;
    }
    return NULL;
}

treenode *recur_insert(int key,treenode *tree)
{
    if(!tree)
    {
        tree=(tree *)malloc(sizeof(tree));
        tree->data=key;
        tree->left=tree->right=NULL;
    }
    else
    {
        if(key>tree->data)
            return tree->right=recur_insert(key,tree->right);
        else if(key<tree->data)
            return tree->left=recur_insert(key,tree->left);
    }
    return tree;
}

void del(treenode *p,int data)
{
    treenode *position;
    if(!p)
        printf("notfound!\n");
    else if(x<p->data)
        p->left=del(p->left,data);
    else if(x>p->data)
        p->right=del(p->right,data);
    else
    {
        if(p->left&&p->right)
        {
            position=findmin(p);
            p->data=position->data;
            p->right=del(p->right,p->data);
        }
        else
        {
            position=p;
            if(!p->left)
                p=p->right;
            else if(!p->right)
                p=p->left;
            free(position);
        }

    }
    return p;
}

typedef struct _searchtree
{
    int v;
    struct _searchtree *left,*right;
    int flag;
}searchtree;

searchtree *createSearchTree(int n)
{
    searchtree *p;
    int i,v;
    scanf(" %d",&v);
    p=createTreeNode(p,v);
    for(i=1;i<=n;i++)
    {
        scanf(" %d",&v);
        p=insert(p,v);
    }
}

searchtree *createTreeNode(searchtree *p,int v)
{
    p->v=v;
    p->flag=0;
    p->left=p->right=NULL;
}

searchtree *searchtreeInsert(searchtree *p,int x)
{
    if(!p)
        p=createTreeNode(p,x);
    else
    {
        if(x>p->v)
            return searchtreeInsert(p->right,x);
        else
            return searchtreeInsert(p->left,x);
    }
    return p;
}

int issame(searchtree *p,int x)
{
    if(p->flag)
    {
        if(x<p->v)
            return issame(p->left,x);
        else if(x>p->v)
            return issame(p->right,x);
        else
            return 0;
    }
    else
    {
        if(x==p->v)
        {
            p->flag=1;
            return 1;
        }
        else
            return 0;
    }

}

int judge(searchtree *p,int n)
{
    int i,x,tag;
    scanf(" %d",&x);
    if(x==p->v)
        tag=1;
    else
        tag=0;
    for(i=1;i<=n-1;i++)
    {
        scanf(" %d",&x);
        if(tag==1&&(!issame(p,x)))
            tag=0;
    }
    if(tag)
        return 1;//same
    else
        return 0;//different
}

searchtree *resetflag(searchtree *p)
{
    if(p->left)
        return resetflag(p->left)
    if(p->right)
        return resetflag(p->right);
    p->flag=0;
}


int main()
{

    treearray a[maxtree],b[maxtree];
    return 0;
}
