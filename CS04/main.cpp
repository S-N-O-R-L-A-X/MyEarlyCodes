#include <iostream>

using namespace std;

long switch_prob(long x,long n)
{
    long result=x;
    switch(n)//x-0x3c(x-60)
    {
    case 60:
    case 62:
        result=8*x;break;
    case 63:result>>=3;break;
    case 64:result<<=4;result-=x;x=result;
    case 65:x*=x;
    default :result=x+75;break;//x+0x4b

    }
    return result;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
