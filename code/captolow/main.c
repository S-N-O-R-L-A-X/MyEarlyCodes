#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1 ="";
    printf("please input a capitalized char\n");
    scanf("%c",&ch1);

    ch1=ch1 +32;

    printf("ch1=%d ch1=%c\n",ch1,ch1);


    return 0;
}
