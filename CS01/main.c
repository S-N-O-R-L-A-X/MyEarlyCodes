#include <stdio.h>
#include <stdlib.h>

int int_shifts_are_arithmetic()
{
    int x=-1;
    int y=x>>1;
    if(x^y)//judge whether x=y
        return 0;
    else
        return 1;
}

int bad_int_size_is_32()
{
    int set_msb=1<<31;
    int beyond_msb=1<<32;
    return set_msb&&!beyond_msb;
}

int main()
{
    printf("%d\n",!~0);
    int_shifts_are_arithmetic();
    return 0;
}
