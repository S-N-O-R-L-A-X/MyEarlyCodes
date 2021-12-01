#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for(i=6;i<=100;i=i+10)
    {
        if(i%3==0)
            printf("%d ",i);
    }
    return 0;
}
