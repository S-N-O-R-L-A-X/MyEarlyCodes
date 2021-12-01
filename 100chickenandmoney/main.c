#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    double money,rest;
    for(a=1;a<=100/7;a++)
        {
            money=100-7*a;
            for(b=1;b<=money/5;b++)
                {
                    rest=money-5*b;
                    c=rest*3;
                    if(100==a+b+c)
                        printf("%d %d %d\n",a,b,c);

                }
        }

    return 0;
}
