#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char input[10000]="0";
    gets(input);
    for(i=0;i<=9999;i++)
    {
        if((input[i]-'a')*(input[i]-'A')*(input[i]-'e')*(input[i]-'E')*(input[i]-'i')*
           (input[i]-'I')*(input[i]-'o')*(input[i]-'O')*(input[i]-'u')*(input[i]-'U')==0)
        {printf("yes");break;}

        if(i==9999)
            printf("no");
    }
    return 0;
}
