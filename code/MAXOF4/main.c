#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3,num4,max;
    scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
    if(num1>=num2)
        max=num1;
    else
        max=num2;
    if(max>=num3)
        max=max;
    else
        max=num3;
    if(max>=num4)
        max=max;
    else
        max=num4;

    printf("%d",max);
    return 0;
}
