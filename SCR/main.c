#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ALI,BOB;
    scanf("%c %c",&ALI,&BOB);

    if(ALI==BOB)
        printf("Tie");
    else if(ALI=='S'&&BOB=='R')
        printf("Bob");
    else if(ALI=='R'&&BOB=='C')
        printf("Bob");
    else if(ALI=='C'&&BOB=='S')
        printf("Bob");
    else if(ALI=='S'&&BOB=='C')
        printf("Alice");
    else if(ALI=='R'&&BOB=='S')
        printf("Alice");
    else
        printf("Alice");

    return 0;
}
