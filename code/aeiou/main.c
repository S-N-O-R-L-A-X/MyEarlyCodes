#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char ch1;
    scanf("%c",&ch1);
    if ('a'<=ch1&&ch1<='z')
    {

    switch(ch1)
    {
    case 'a':
        printf("vowel");
        break;
    case 'e':
        printf("vowel");
        break;
    case 'i':
        printf("vowel");
        break;
    case 'o':
        printf("vowel");
        break;
    case 'u':
        printf("vowel");
        break;
    default:

        printf("consonant");
        break;
    }
    }
    else
    printf("error");
    return 0;

}
