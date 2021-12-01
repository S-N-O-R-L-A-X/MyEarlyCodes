#include <stdio.h>
#include <stdlib.h>


typedef struct
    {
        char name[91]="";
        double price;
        char press[31]="";
    }book;

int main()
{
    book paper;
    p=(book*)malloc(sizeof(book));
    gets(x.name);
    scanf("%lf ",&x.price);
    gets(x.press);
    printf("name is \"%s\"",x.name);
    printf(", price is $%lf",x.price);
    printf(", press is \"%s\""),x.press);
    return 0;
}
