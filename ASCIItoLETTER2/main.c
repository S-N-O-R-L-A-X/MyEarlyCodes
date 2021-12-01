#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void ToLetter(int b,int c)
{   int i;char a;
    for(i=b;i<=c;i++)
    {
        if(isgraph(i))
        {

            a=i;
            printf("%-10d     %c",i,a);

            if(i!=c)
            printf("\n");
        }
        else
        {
           printf("NONE");
           break;
        }
    }
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    ToLetter(a,b);
    return 0;
}
