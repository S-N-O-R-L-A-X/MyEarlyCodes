#include <stdio.h>
int a[10],n,c=0;
void dfs(int b){
    if(b==-1){
        printf("{");
        for(int i=0;i<n;++i)
            if(a[i]){
                if(c==1)
                    printf(",");
                else
                    c=1;
                printf("%d",i);
                }
        printf("}\n");
        c=0;
        return ;
    }
    a[b]=0;
    dfs(b-1);
    a[b]=1;
    dfs(b-1);
    return ;
}
int main(){
    scanf("%d",&n);
    dfs(n-1);
    return 0;
}
