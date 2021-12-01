#include <stdio.h>
#include <stdlib.h>

void Find ( ListNode *f ) {
    if ( f →link == NULL )
        cout << f →data << endl;
    else Find ( f →link );
}

void Find ( ListNode *f ) {
    if ( f →link != NULL )
        Find ( f →link );
    else cout << f →data << endl;
}


int bang(int x) {
	int y=~x+1;//y=-x
	int z=(x|y)>>31;//extract the first place
	return !(z&1);
}

int isPositive(int x) {
  return !((x>>31)&1|(!x));
}

int isLessOrEqual(int x, int y) {
	/*int z=~y+1;//z=-y
	int sign=(x+z)>>31;
	return (sign&1)|(!sign);*/
	int signx=(x>>31);
	int signy=(y>>31);
	int a=(x+~y)>>31;//judge the sign of (x-y)
	int b=!(signx^signy);//judge whether signx=signy
	int same=signx&(!signy);//signx!=signy
	return (a&b)|same;
}

unsigned float_i2f(int x)
{
	unsigned y,z,left=0,sign=0,flag;
	if(x==0)
		return x;
	else if(x<0){
		y=-x;
		sign=0x80000000;
	}
	else
		y=x;
	while(1){
		z=y;
		y<<=1;
		left++;//count the amount of the left of the highest 1
	if(z&0x80000000)//the highest 1 determines the exponent   
		break;
	}
	if((y&0x01ff)>0x0100)
		flag=1;
	else if((y&0x03ff)==0x0300)
		flag=1;
	else
		flag=0;
    unsigned a=y>>9;
    unsigned b=(159-left)<<23;//bias=2^7-1=127 right=32-left
    unsigned s=sign+a+b+flag;
	return s;
}


int Num_of_1(int n)
{
    /*
    0xAAAAAAAA=1010 1010 1010 1010 1010 1010 1010 1010
    In this case we will divide n by 2 bits.
    n&0xAAAAAAAA means extract 1 in odd place
    and then >>1 means moving the number to even place
    0x55555555=0101 0101 0101 0101 0101 0101 0101 0101
    n&0x55555555 means extracting 1 in even place
    then + means we divide n by 2 bits and use 2 bits to store how many
    1s the two bits have
    then we get a new n

    0xCCCCCCCC=1100 1100 1100 1100 1100 1100 1100 1100
    In this case we will divide n by 4 bits.
    n&0xCCCCCCCC means extracting 1s in the first and second place
    and then >>2 means moving the number to the third and fourth place
    0x33333333=0011 0011 0011 0011 0011 0011 0011 0011
    n&0x33333333 means extracting 1s in the third and fourth place
    then + means we divide n by 4 bits and use 4 bits to store how many
    1s the four bits have
    then we get a new n

    0xF0F0F0F0=1111 0000 1111 0000 1111 0000 1111 0000
    In this case we will divide n by 8 bits.
    n&0xF0F0F0 means extracting 1s in the first half
    and then >>4 means moving the number to the second half
    0x0F0F0F0F=0000 1111 0000 1111 0000 1111 0000 1111
    n&0x0F0F0F0F means extracting 1s in the second half
    then + means we divide n by 8 bits and use 8 bits to store how many
    1s the eight bits have
    then we get a new n



	n=((n&0xAAAAAAAA)>>1)+(n&0x55555555);
	n=((n&0xCCCCCCCC)>>2)+(n&0x33333333);
    n=((n&0xF0F0F0F0)>>4)+(n&0x0F0F0F0F);
    n=((n&0xFFFF0000)>>16)+(n&0x0000FFFF);*/


    /*
    First we will divide n by 2 bits.
    0x55555555=0101 0101 0101 0101 0101 0101 0101 0101
    n&0x55555555 means extracting 1 in even place
    and (n>>1)&0x55555555 means extracting 1 in odd place
    then + means we divide n by 2 bits and use 2 bits to store how many
    1s the 2 bits have
    then we get a new n

    Second we will divide n by 4 bits.
    0x33333333=0011 0011 0011 0011 0011 0011 0011 0011
    n&0x33333333 means extracting 1s in the third and fourth place
    and (n>>2)&0x33333333 means extracting 1 in the first and second place
    then + means we divide n by 4 bits and use 4 bits to store how many
    1s the 4 bits have(the first place +the third place,the second place+
    the fourth place)
    then we get a new n

    Third we will divide n by 8 bits.
    0x0F0F0F0F=0000 1111 0000 1111 0000 1111 0000 1111
    n&0x0F0F0F0F means extracting 1s in the second half
    and (n>>4)&0x0F0F0F0F means extracting 1 in the first half
    then + means we divide n by 8 bits and use 8 bits to store how many
    1s the 8 bits have(the first place + the fifth place,the second place+
    the sixth place,the third place+ the seventh place,the fourth place +
    the eighth place)
    then we get a new n

    now n can be expressed as 0x0a0b0c0d  a,b,c,d separately shows how
    many 1s it has in each byte.

    n=(n*0x01010101>>24) means a+b+c+d
    */

    n=(n&0x55555555)+((n>>1)&0x55555555);
    n=(n&0x33333333)+((n>>2)&0x33333333);
    n=(n&0x0F0F0F0F)+((n>>4)&0x0F0F0F0F);
    n=(n*0x01010101>>24);
    return n;
}

/*
int ilog2(int x) {
	int cnt=0;
	while(((x&0x80000000)>>31)!=1)
	{
		cnt++;
		x<<=1;
	}
	return 31-cnt;
}*/


int ilog2(int x)
{
    //binary judge
    int result=0;
    result=(!!(x>>16))<<4;//judge whether >2^16 if<2^16 result=0 else result=16
    result=result+((!!(x>>(result+8)))<<3);//according to the former line,continue binary judge
    result=result+((!!(x>>(result+4)))<<2);
    result=result+((!!(x>>(result+2)))<<1);
    result=result+(!!(x>>(result+1)));
//    int last=!(1^x);//judge the last place
//    result=result+(!!result)+(~0)+last;
    return result;
}


int main()
{
    int x,y;
    while(scanf("%d",&x)!=EOF)
        printf("%d\n",Num_of_1(x));
//    while(scanf(" %d %d",&x,&y)!=EOF)
//        printf("%\n",isLessOrEqual(x,y));
    return 0;
}
