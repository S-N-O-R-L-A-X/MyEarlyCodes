#include <stdio.h>
#include <stdlib.h>

/*
char *i2a(char *p,int n)
{
    if(n>0)
    {
        *p=n%10+'0';
        return *i2a(p++,n/10);
    }
    else
        return *p;
}

int main()
{
    int n;
    char str[20]="";
    char *p=str;
    scanf("%d",&n);
    printf("%s",*i2a(p,n));
    return 0;
}
*/

char str[20];
int i=0;

int a2i(int n)
{

    if (n!=0)
    {
        str[i++]=n%10+'0';
        a2i(n/10);
    }
    return i;
}
int main(void)
{

    int n,j;
    scanf("%d",&n);
    char temp;
    j=a2i(n)-1;//eat '\0'
    for(i=0;i<=j/2;i++)
    {
        temp=str[i];
        str[i]=str[j-i];
        str[j-i]=temp;
    }
    str[j+1]='\0';
    printf("%s",str);
    return 0;
}
