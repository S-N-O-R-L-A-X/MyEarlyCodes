#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n1,n2,i,j,temp,out;
    char str1[1001]="";
    char str2[1001]="";
    out=0;
    while(scanf("%s",str1)&&str1[0]!='#')
    {
        scanf("%s",str2);
        n1=strlen(str1);
        n2=strlen(str2);
        for(i=0;i<=n1-1;i++)
        {
            temp=i;
            for(j=0;j<=n2-1;j++)
            {
                if(str1[temp]==str2[j])
                    {
                        temp++;
                    }
                else
                    break;
                if(j==n2-1)
                {
                    i=i+n2-1;
                    out++;
                }
            }
        }
        printf("%d\n",out);
        out=0;
        str1[1001]="";
        str2[1001]="";
    }
    return 0;
}
