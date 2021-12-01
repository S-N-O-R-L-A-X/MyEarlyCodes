#include <stdio.h>
#include <stdlib.h>

void Number2Alpha(int num,char *mptr)
{
    char *month={"January","February","March","April","May","June","July",
                 "August","September","October","November","December"};
    mptr=month;
    *mptr=num-1;
    printf("%s",mptr);
}

int main()
{
    int num;
    char *mptr;
    scanf("%d",&num);
    Number2Alpha(num,&mptr);
    return 0;
}
