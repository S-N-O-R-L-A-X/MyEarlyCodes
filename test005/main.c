#include <stdio.h>

#include <stdlib.h>

const int max = 10001;//���ͳ���10001 ��ʾ������������10000����//

int transform(long long int n){

    if(n<0) n=-n;//����������

    while(n>=10){//ע���ǵ�n>=10

        n/=10;    }//ȡ�����λ����

    return n;}

typedef struct{//����һ���ṹ�� �������λ���� �����������

    long long first_num;

    long long num;}

element;
int cmp(const void *a,const void *b){

  element *s1=(element *)a;//�ṹ��ָ��

    element *s2=(element *)b;

    if(s1->first_num==s2->first_num)

        return (s1->num)>(s2->num)?1:-1;//������λ��� ���������ִ�С����

    else return (s2->first_num-s1->first_num);//���� �����ǰ}
int main(){

    int T;

    scanf("%d",&T);

    int t=0;

  while(T--){

      int n;

      scanf("%d",&n);//����

      element a[max];//����һ���ṹ��..

    for(int i=0;i<n;i++) {

          scanf("%lld",&a[i].num);//��������
          }
        for(int i=0;i<n;i++)            a[i].first_num=transform(a[i].num);//���λ����


        qsort(a,n,sizeof(a[0]),cmp);//����qsort

        printf("case #%d:\n",t);        t++;//case+1

        for(int j=0;j<n-1;j++)

            printf("%lld ",a[j].num);

      printf("%lld\n",a[n-1].num);//���һ�� ����    }

    return 0;
    }

