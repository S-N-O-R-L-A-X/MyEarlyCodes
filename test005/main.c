#include <stdio.h>

#include <stdlib.h>

const int max = 10001;//整型常量10001 表示数组最多可容纳10000个数//

int transform(long long int n){

    if(n<0) n=-n;//负数变正数

    while(n>=10){//注意是当n>=10

        n/=10;    }//取到最高位整数

    return n;}

typedef struct{//定义一个结构体 包含最高位整数 和这个数本身

    long long first_num;

    long long num;}

element;
int cmp(const void *a,const void *b){

  element *s1=(element *)a;//结构体指针

    element *s2=(element *)b;

    if(s1->first_num==s2->first_num)

        return (s1->num)>(s2->num)?1:-1;//如果最高位相等 按本身数字大小排列

    else return (s2->first_num-s1->first_num);//降序 大的在前}
int main(){

    int T;

    scanf("%d",&T);

    int t=0;

  while(T--){

      int n;

      scanf("%d",&n);//个数

      element a[max];//声明一个结构体..

    for(int i=0;i<n;i++) {

          scanf("%lld",&a[i].num);//输入数字
          }
        for(int i=0;i<n;i++)            a[i].first_num=transform(a[i].num);//最高位整数


        qsort(a,n,sizeof(a[0]),cmp);//调用qsort

        printf("case #%d:\n",t);        t++;//case+1

        for(int j=0;j<n-1;j++)

            printf("%lld ",a[j].num);

      printf("%lld\n",a[n-1].num);//最后一个 换行    }

    return 0;
    }

