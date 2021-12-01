#include <stdio.h>
#include <stdlib.h>


void inSCORE(int m,int *p)
{
    int i=1;
    while(i<=m)
    {
        scanf("%d ",*p);
        p++;
        i++;
    }
}

int main()
{
    int n,m,g,i,j;
    scanf("%d %d %d",&n,&m,&g);
    int standard[m];
    int *p=standard;
    inSCORE(m,*p);
    int amount,number;
    int sum=0;int pass=0;
    int score[n];
    char student[n][21];
    for(i=0;i<=n-1;i++)
    {
        scanf("%s",student[i]);
        scanf("%d ",&amount);
        for(j=1;j<=amount;j++)
        {
            scanf("%d ",&number);
            sum=sum+standard[number];
            if(j==amount)
                {
                    if(sum>=g)
                        {
                            pass++;
                        }
                        score[i]=sum;//store the score of student i
                }
        }
    }
    printf("%d",pass);

    return 0;
}
