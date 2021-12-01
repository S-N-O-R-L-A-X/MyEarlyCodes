#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fahr;
    scanf("%f",&fahr);
    printf("celsius = %.0f",5*(fahr-32)/9.0);
    return 0;
}
