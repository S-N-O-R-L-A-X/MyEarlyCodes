#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void ToLetter(int b,int c)
{   int i;char a;
    for(i=b;i<=c;i++)
    {
        if(isgraph(i))
        {
            printf("%d     ",i);
            if(i<100)
                printf(" ");
            a=i;
            printf("%c",a);
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
