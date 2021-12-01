#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c,d,e,f,g,h,i,j,k,l,x,y,z;
    a=7/4;
    b=7%4;
    c=(-7)/4;
    d=(-7)%4;
    e=(-7)/(-4);
    f=(-7)%(-4);
    g=7/(-4);
    h=7%(-4);
    i=1&&0;
    j=2&&1;
    k=2&&3;
    l=1&&-1;
    x=3;
    y=8;

    printf("7/4= 7mod4= (-7)/4= (-7)mod4= (-7)/(-4)= (-7)mod(-4)= 7/(-4)= 7mod(-4)= \n");
    printf("%d     %d     %d        %d       %d        %d            %d      %d",a,b,c,d,e,f,g,h);

    printf("\n\n\n%d   %d   %d   %d",j,k,l,i);


    printf("\n\n\n++x*y=%d      x++*y=%d     ",++x*y,x++*y);



    return 0;
}
