#include <stdio.h>
#include <stdlib.h>


int main()
{
    int num1,digit1,digit2,digit3;
        for(num1=100;num1<=999;num1++)
            {
            digit1=num1/100;
            digit1=digit1*digit1*digit1;
            digit2=num1/10%10;
            digit2=digit2*digit2*digit2;
            digit3=num1%10;
            digit3=digit3*digit3*digit3;
            if (digit1+digit2+digit3==num1)
                printf("%d ",num1);
            }



    return 0;
}
