#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char comp[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int row_length[10]={0,0,3,3,3,3,3,4,3,4};

void getstr(string num,char str[][10])
{
    int j=0;
    for(int i=0;i<num.size();i++)
    {
        int index=num[i]-'0';
        strcpy(str[j++],comp[index]);
    }
}

void print(char str[][10],int len,int ans[],int r)
{
    if(r==len)
    {
        for(int i=0;i<r;i++)
        {
            int index=ans[i];
            cout<<str[i][index];
        }
        cout<<' ';
        return ;
    }

    for(ans[r]=0;ans[r]<strlen(str[r]);ans[r]++)
    {
        print(str,len,ans,r+1);
    }
}

int main()
{
    string s;
    cin>>s;
    char str[20][10];
    getstr(s,str);
    int ans[100];
    print(str,s.size(),ans,0);


    return 0;
}
