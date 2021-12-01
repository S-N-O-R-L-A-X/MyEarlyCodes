#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    double data[11][5];
    double a;
    a=2.0;
    for(i=0;i<=10;i++)
    {
        data[i][0]=a;
        data[i][1]=1/a;
        data[i][2]=a*a;
        data[i][3]=a*a*a;
        data[i][4]=a*a*a*a;
        a=a+0.1;
        for(j=0;j<=4;j++)
        {
           printf("%.4lf ",data[i][j]);
        }
        printf("\n");

    }


    return 0;
}
