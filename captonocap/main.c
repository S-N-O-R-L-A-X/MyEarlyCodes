#include <stdio.h>
#include <stdlib.h>

int main()
{
    char aaa,bbb;
    scanf("%c",&aaa);
    if (aaa >=65&&aaa <=90)
      {
          bbb=aaa+('a'-'A');
          printf("%c",bbb);
      }
    else
       printf("error");
    return 0;
}
