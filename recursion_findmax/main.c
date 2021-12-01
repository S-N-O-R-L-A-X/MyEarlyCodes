#include <stdio.h>
#include <stdlib.h>

int findmax(int array[],int left,int right)
{
    int a,b;
    if(left==right)
        return array[right];
    else
    {
        a=array[left];
        b=findmax(array,left+1,right);
        if(a<b)
            return b;
        else
            return a;
    }


}


int main()
{
    int a[]={10,2,4,3,1,7,5,0,6,8};
    int out =findmax(a,0,9);
    printf("%d",out);
    return 0;

}
