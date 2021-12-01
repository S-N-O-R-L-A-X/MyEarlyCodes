#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3,mid;
    scanf(" %d %d %d",&num1,&num2,&num3);
    if (num1>=num2)
    {
        if (num1<=num3)
            mid=num1;

        else
        {
            if (num2>=num3)
                mid=num2;
            else
                mid=num3;
        }

    }
    else
    {
        if (num2<=num3)
            mid=num2;
        else
           {
               if(num1>=num3)
                mid=num1;
               else
                mid=num3;
           }
    }
    printf("%d",mid);
    return 0;
}
