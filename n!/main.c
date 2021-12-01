    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        unsigned long long fac;
        int n,N;
        scanf("%d",&N);
        fac=1;
        n=1;


        if(N==0)
            printf("1");
        else
        {
          for(n=1;n<=N;++n)
            fac=fac*n;
            printf("%llu",fac);
        }



        return 0;
    }
