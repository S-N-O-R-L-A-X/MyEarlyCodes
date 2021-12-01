#include <iostream>

using namespace std;

int P358(long x,long y,long z)
{
    y=y-z;
    x=(y-z)*x;
    long a=y;
    a<<=63;
    a>>=63;
    a=a^x;
    return a;
}

int P360()
{
    A.rcx:n  rdx:mask  rax:result
    B.result=0 mask=1
    C.mask!=0
    D.mask<<=n
    E.result|=(x&mask)
    F.
    long result=0;
    long mask;
    for(mask=1;mask!=0;mask<<=n)
    {
        result|=(x&mask) ;
    }
    return result;
}


int main()
{


    return 0;
}
