#include <stdio.h>
#include <stdlib.h>
#define Fire  1.09
#define Maple 4.50
#define Cedar 2.26
#define Pine  0.89
#define Oak  3.10
int main()
{
    double price,sum;
    int num,wid,hei,len;
    char a;
    sum=0;

    while(scanf(" %c",&a))
    {   if(a=='T')
            break;

        else
        {
            scanf("%d %d %d %d",&num,&wid,&hei,&len);
        switch(a)
        {
            case 'P':price=num*wid*hei*len/12.0*Pine;sum=price+sum;
            printf("%d %d*%d*%d Pine, Cost: $%.2llf\n",num,wid,hei,len,price);break;
            case 'F':price=num*wid*hei*len/12.0*Fire;sum=price+sum;
            printf("%d %d*%d*%d Fire, Cost: $%.2llf\n",num,wid,hei,len,price);break;
            case 'C':price=num*wid*hei*len/12.0*Cedar;sum=price+sum;
            printf("%d %d*%d*%d Cedar, Cost: $%.2llf\n",num,wid,hei,len,price);break;
            case 'M':price=num*wid*hei*len/12.0*Maple;sum=price+sum;
            printf("%d %d*%d*%d Maple, Cost: $%.2llf\n",num,wid,hei,len,price);break;
            default:price=num*wid*hei*len/12.0*Oak;sum=price+sum;
            printf("%d %d*%d*%d Oak, Cost: $%.2llf\n",num,wid,hei,len,price);break;
        }
        }

    }
    printf("Total cost: $%.2llf",sum);
    return 0;
}
