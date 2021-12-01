#include <stdio.h>
int main(){
    int n,x=0,y=0,index=1;
    int arr[100][100]={0};
    scanf("%d",&n);
    while(index<=n*n){
        while(x<n && arr[x][y]==0)arr[x++][y]=index++;
        x--;y++;
        while(y<n && arr[x][y]==0)arr[x][y++]=index++;
        x--;y--;
        while(x>=0 && arr[x][y]==0)arr[x--][y]=index++;
        x++;y--;
        while(y>=0 && arr[x][y]==0)arr[x][y--]=index++;
        x++;y++;
    }
    for(x=0; x<n; x++){
        for(y=0; y<n; y++){
            if(y==n-1)printf("%-5d\n",arr[x][y]);
            else printf("%-5d ",arr[x][y]);
        }
    }
    return 0;
}
