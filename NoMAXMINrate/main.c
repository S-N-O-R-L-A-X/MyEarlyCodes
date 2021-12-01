#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    double score[n],max,min,average;
    average=0.0;
    for(i=0;i<=n-1;i++)
    {
        scanf("%lf",&score[i]);
    }
    max=score[0];
    min=score[0];

    for(i=0;i<=n-1;i++)
        {
            average=average+score[i];
            if(score[i]>max)
                max=score[i];
            if(score[i]<min)
                min=score[i];

        }
        average=(average-max-min)/(n-2);
        printf("%.2lf",average);


    return 0;
}
