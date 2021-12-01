#include <stdio.h>
#include <stdlib.h>


int main()
{
    int ms,hour,minute,i;
    int bus[]={410,510,710,830,1010,1080,1250};
    scanf("%d:%d",&hour,&minute);
    ms=60*hour+minute;
    for(i=0;i<=6;i++)
    {
        if(ms<=bus[i])
        {
            printf("%d",bus[i]-ms);
            break;
        }
        if(i==6)
            printf("-1");
    }

    return 0;
}
