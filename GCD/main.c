#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n,a,num1,num2;
    scanf("%d %d",&num1,&num2);


    for(n=1;n<=num1;n++)
    {
        if(num1%n==0&&num2%n==0)
            a=n;
    }
    printf("%ld",a);
    return 0;
}
