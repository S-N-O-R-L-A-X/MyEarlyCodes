#include <stdio.h>
#include<stdlib.h>
int find_min(int a[],int num){

	int min,i,j,k,m;
	int b[1000]={0};//��ʱ���һ���ľ���ֵ
	for(i=0;i<num;i++)
	scanf("%d",&a[i]);

	for(j=0;j<num;++j){
		for(k=0;k<num;++k){
		b[j]+=abs(a[j]-a[k]);
		}
	}//���Ƕ����Ϊ�˱������еľ���ֵ֮�͵�ÿһ�������
	min=b[0];
	for(m=0;m<num;++m){
	if(b[m]<min) min=b[m];
	}
	printf("%d\n",min);
}




int main()
{
int num,amo,a[1000]={0};
scanf("%d",&num);
for(int i=0;i<num;++i)
{scanf("%d",&amo);//���м������ѣ�
find_min(a,amo);

}}
