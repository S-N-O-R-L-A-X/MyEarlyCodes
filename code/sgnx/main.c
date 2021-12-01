#include <stdio.h>
#include <stdlib.h>

int main()
{
    int xxx,yyy;
    scanf("%d",&xxx);
    if (xxx>0)
        yyy=1;
    else if (0==xxx)
        yyy=0;
    else
        yyy=-1;

    printf("%d",yyy);
    return 0;
}
