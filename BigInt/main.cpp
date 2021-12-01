#include <iostream>
#include <string>
#define maxsize 400
using namespace std;

struct BigInt
{
    int num[maxsize];//store in reverse
    int length;
    int sign;
    BigInt();
};

ostream & operator <<(ostream & output,BigInt x)
{
    if(x.length==0)
    {
        output<<'0';
        return output;
    }
    if(x.sign==-1)
        cout<<'-';
    for(int i=x.length-1;i>=0;i--)
        output<<x.num[i];
	return output;
}

BigInt::BigInt()
{
    for(int i=0;i<maxsize;i++)
        num[i]=0;
    length=0;
    sign=1;
}

void transfer(string s,BigInt &x)
{
    for(int i=s.size()-1;i>=1;i--)
        x.num[x.length++]=s[i]-'0';
    if(s[0]=='-')
        x.sign=-1;
    else
        x.num[x.length++]=s[0]-'0';
}

void set_len(BigInt *x)
{
    int i;
    for(i=maxsize-1;i>=0;i--)
    {
        if(x->num[i]!=0)
            break;
    }
    x->length=i+1;
}

bool BigIntAbsCmp(BigInt a,BigInt b)
{
    if(a.length>b.length)
        return true;
    else if(a.length<b.length)
        return false;
    for(int i=a.length-1;i>=0;i--)
    {
        if(a.num[i]>b.num[i])
            return true;
        else if(a.num[i]<b.num[i])
            return false;
    }
    return true;
}

bool BigIntCmp(BigInt a,BigInt b)
{
    if(a.sign*b.sign==1)//same sign
    {
        if(a.sign==1)
            return BigIntAbsCmp(a,b);
        return !BigIntAbsCmp(a,b);
    }
    //different sign
    if(a.sign==-1)
        return false;
    return true;
}
void rightshift(BigInt *x,int p)
{
    for(int i=x->length-1;i>=0;i--)
        x->num[i+p]=x->num[i];
    for(int i=0;i<p;i++)
        x->num[i]=0;
    set_len(x);
}

void leftshift(BigInt *x,int p)
{
    for(int i=0;i<x->length-p;i++)
        x->num[i]=x->num[i+p];
    for(int i=x->length-p;i<x->length;i++)
        x->num[i]=0;
    set_len(x);
}


void BigIntDivideF1(BigInt &c,BigInt &d,BigInt *ans,int p);
void BigIntDivideF2(BigInt &c,BigInt &d,BigInt *ans);
void BigIntPlus(BigInt &a,BigInt &b,BigInt *ans);
void BigIntMinus(BigInt &a,BigInt &b,BigInt *ans);
void BigIntMultiply(BigInt &a,BigInt &b,BigInt *ans);
void BigIntDivide(BigInt &a,BigInt &b,BigInt *ans);

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    char op;
    cin>>op;
    BigInt a,b,ans;
    transfer(str1,a);
    transfer(str2,b);
    if(op=='+')
    {
        BigIntPlus(a,b,&ans);
        cout<<ans;
    }
    else if(op=='-')
    {
        BigIntMinus(a,b,&ans);
        cout<<ans;
    }
    else if(op=='*')
    {
        BigIntMultiply(a,b,&ans);
        cout<<ans;
    }
    else
    {
        BigIntDivide(a,b,&ans);
        cout<<ans;
    }
    return 0;
}

void BigIntPlus(BigInt &a,BigInt &b,BigInt *ans)
{
    int i,j=0;
    if(a.sign*b.sign==1)
    {
        for(i=0;i<maxsize;i++)
        {
            ans->num[j]+=a.num[i]+b.num[i];
            if(ans->num[j]>=10)
            {
                ans->num[j]-=10;
                ans->num[j+1]++;
            }
            j++;
        }
        if(a.sign==-1)//set the sign of ans
            ans->sign=-1;
    }
    else
    {
        if(a.sign==-1)
        {
            BigInt tmp=a;
            tmp.sign=1;
            BigIntMinus(tmp,b,ans);
        }
        else
        {
            BigInt tmp=b;
            tmp.sign=1;
            BigIntMinus(a,tmp,ans);
        }
        if(BigIntAbsCmp(a,b))//modify the sign
            ans->sign=-1;
        else
            ans->sign=1;
    }
    set_len(ans);
}

void BigIntMinus(BigInt &a,BigInt &b,BigInt *ans)
{
    int i;
    if((a.sign)*(b.sign)==1)
    {
        if(BigIntAbsCmp(a,b))//a>b
        {
            for(i=0;i<maxsize;i++)
            {
                ans->num[i]+=(a.num[i]-b.num[i]);
                if(ans->num[i]<0)
                {
                    ans->num[i+1]--;
                    ans->num[i]+=10;
                }
            }
            if(!BigIntCmp(a,b))
                ans->sign=-1;
        }
        else
        {
            if(!BigIntCmp(a,b))
                ans->sign=-1;
            for(i=0;i<maxsize;i++)
            {
                ans->num[i]+=(b.num[i]-a.num[i]);
                if(ans->num[i]<0)
                {
                    ans->num[i+1]--;
                    ans->num[i]+=10;
                }
            }
        }
    }
    else
    {
        if(a.sign==-1)//a<0,b>=0,a-b
        {
            BigInt tmp=b;
            tmp.sign=-1;
            BigIntPlus(a,tmp,ans);
        }
        else//a>=0,b<0,a-b
        {
            BigInt tmp=b;
            tmp.sign=1;
            BigIntPlus(a,tmp,ans);
        }
    }
    set_len(ans);
}

void BigIntMultiply(BigInt &a,BigInt &b,BigInt *ans)
{
    int idx,sum;
    for(int i=0;i<b.length;i++)
    {
        int carry=0;
        for(int j=0;j<a.length;j++)
        {
            idx=i+j;
            sum=a.num[j]*b.num[i]+ans->num[idx]+carry;
            carry=sum/10;
            ans->num[idx]=sum%10;
        }
        while(carry!=0)
        {
            ans->num[++idx]=carry%10;
            carry/=10;
        }
    }
    set_len(ans);
    if(a.sign*b.sign==-1)
        ans->sign=-1;
}

void BigIntDivideF1(BigInt &c,BigInt &d,BigInt *ans,int p)
{
    int cnt=0;
    BigInt tmp=d;
    rightshift(&tmp,p);
    while(true)
    {
        if(!BigIntAbsCmp(c,tmp))//c>tmp
        {
            leftshift(&tmp,1);
            ans->num[p]=cnt;
            cnt=0;
            p--;
        }
        if(!BigIntAbsCmp(c,d)&&cnt==0)
            break;
        if(!BigIntAbsCmp(c,tmp))
            continue;
        for(int i=0;i<c.length;i++)
        {
            c.num[i]-=tmp.num[i];
            if(c.num[i]<0)
            {
                c.num[i+1]--;
                c.num[i]+=10;
            }
        }
        set_len(&c);//c-tmp
        cnt++;
    }
}

void BigIntDivideF2(BigInt &c,BigInt &d,BigInt *ans)
{
    while(BigIntAbsCmp(c,d))
    {
        for(int i=0;i<c.length;i++)
        {
            c.num[i]-=d.num[i];
            if(c.num[i]<0)
            {
                c.num[i+1]--;
                c.num[i]+=10;
            }
        }
        set_len(&c);//c-d
        ans->num[0]++;
        for(int i=0;i<10;i++)
        {
            if(ans->num[i]>=10)
            {
                ans->num[i+1]++;
                ans->num[i]%=10;
            }
            else
                break;
        }
    }
}

void BigIntDivide(BigInt &a,BigInt &b,BigInt *ans)
{
    BigInt c=a,d=b;
    c.sign=1;
    d.sign=1;
    int p=c.length-d.length-1;
    if(p>0)//need moving
        BigIntDivideF1(c,d,ans,p);
    else
        BigIntDivideF2(c,d,ans);
    set_len(ans);
    if(a.sign*b.sign==-1)
        ans->sign=-1;
}

/*
test:
1 9999 +
9999 1 +
-9999 -1 +
-1 -9999 +
5 -5 +
-5 5 +
4 -3 +
3 -4 +
-3 4 +
-4 5 +
999 -1 -
73 -27 -
-10 -1 -
-1 -10 -
10 -1 -
-1 10 -
-10 1 -
1 -10 -
0 0 *
0 -17 *
0 17 *
123456789 987654321  *
4320943 3124130 *
10 3 /
12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
33333
/
*/
