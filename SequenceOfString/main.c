#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    char str[n][31];
    int a[n];
    for(i=0;i<=n-1;i++)
    {
        a[i]=i;
    }
    for (i=0;i<=n-1;i++)
    {
        gets(str[i]);
        if (strcmp(str[i+1],str[i])>0)
        {

        }
    }
    for(i=0;i<=n-1;i++)
    {
        printf("%s",str[i]);
    }
    return 0;
}
