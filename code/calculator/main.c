#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2;
    char ch1;
    scanf("%d%c%d=",&num1,&ch1,&num2);
    switch (ch1)
    {
    case '+':
        printf("%d",num1+num2);
        break;
    case '-':
        printf("%d",num1-num2);
        break;
    case '*':
        printf("%d",num1*num2);
        break;
    default:
        if(0==num2)
            printf("error");
        else
        printf("%d",(float)num1/num2);
    break;
    }

    return 0;
}
