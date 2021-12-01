#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fahr;
    scanf("%d",&fahr);
    printf("celsius = %d",(5*(fahr-32)/9+0.5)/1);
    return 0;
}
