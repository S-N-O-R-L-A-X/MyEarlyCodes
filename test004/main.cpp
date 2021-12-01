#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>

struct goods
{
  int num;
  char name[20];
  char type[20];
  float price;
  char place[20];
  int have;
  int buy;
  }g[20];

void read(struct goods g[])
 {
    FILE *fp;
    int i=0;
    fp=fopen("goods.txt","r");
    if (fp==NULL)
    {
        printf("无法打开goods文件\n");
        exit(0);
    }
    while (!feof(fp))
    {
    fscanf (fp," %d %s %s %f %s %d %d",&g[i].num,g[i].name,g[i].type,&g[i].price,g[i].place,&g[i].have,&g[i].buy);
    printf("%d %s %s %.2f %s %d %d\n",g[i].num,g[i].name,g[i].type,g[i].price,g[i].place,g[i].have,g[i].buy);
    i++;
    }
    fclose(fp);

    }

int main()
{
    read(g);
    return 0;
}


/*
typedef struct student
{
    char ch;
    struct student *next;
}node;

node *create()
{
    node *head=NULL,*p1,*p2;
    int size=sizeof(node *);
    p1=p2=(node *)malloc(size);
    int cnt=0;
    while(scanf(" %c",&(p1->ch)))
    {
        cnt++;
        if(cnt==1)
            head=p1;
        else
            p2->next=p1;
        p2=p1;
        p1=(node *)malloc(size);
        scanf(" %d",&(p1->ch));
        p2->next=NULL;
        return head;
    }
}

void print(node *head)
{
    for(node *p=head;p;p=p->next)
        printf("%c ",p->ch);
}


struct thing
{
    int no;
    char name[30];
    char type[30];
    float price;
    char place[30];
    int have;
    int buy;
};

int main()
{
    thing goods[10];
    for(int i=0;i<10;i++)
    {
        scanf(" %d %s %s %f %s %d %d",&goods[i].no,goods[i].name,goods[i].type,&goods[i].price,goods[i].place,&goods[i].have,&goods[i].buy);
        //scanf(" %f %s %d %d",&goods[i].price,goods[i].place,&goods[i].have,&goods[i].buy);
        printf("%d %s %s %.2f %s %d %d\n",goods[i].no,goods[i].name,goods[i].type,goods[i].price,goods[i].place,goods[i].have,goods[i].buy);
        //printf("%.2f %s %d %d\n",goods[i].price,goods[i].place,goods[i].have,goods[i].buy);
    }
}
*/
