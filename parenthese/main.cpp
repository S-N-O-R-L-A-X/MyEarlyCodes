#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class MYSTACK
{
public:
    MYSTACK();
    void judgement(char in,char next,bool flag1,bool flag2,bool flag3);
//    bool judgeOut();
//    int cntOut();
//    int stacksizeOut();
    void print();
private:
    stack<char> s;
    int cnt;
    bool judge;
};

int main()
{
    MYSTACK a;
    bool flag1=false;//show whether it is in ""
    bool flag2=false;//show whether it is in paragraph comments
    bool flag3=false;//show whether it is in line comments
    char in=cin.get();
    while(in!=EOF)
    {
        char next=cin.get();
        if(next==EOF)
            break;
//        std::getline(std::cin,str);
        if(in=='/'&&next=='/'&&!flag1)
            flag2=true;
        else if(in=='/'&&next=='*'&&!flag1)
            flag3=true;
        else if(in=='*'&&next=='/'&&!flag1&&!flag2)
            flag3=false;
        else if(in=='"')
            flag1=!flag1;
        else if(in=='\n')
            flag2=false;
        else
            a.judgement(in,next,flag1,flag2,flag3);
        in=next;
    }

//    bool tag=a.judgeOut();
//    int amount=a.cntOut();
//    int stackCNT=a.stacksizeOut();

    return 0;
}

MYSTACK::MYSTACK()
{
    cnt=0;
    judge=true;
}


void MYSTACK::judgement(char in,char next,bool flag1,bool flag2,bool flag3)
{
    if((in=='('||in=='['||in=='{')&&!flag2&&!flag3)
    {
        cnt++;
        s.push(in);
    }
    else if(in==')'&&!flag2&&!flag3)
    {
        cnt++;
        char ch=s.top();
        if(ch=='(')
            s.pop();
        else
            judge=false;
    }
    else if((in==']'||in=='}')&&!flag2&&!flag3)
    {
        cnt++;
        char ch=s.top();
        if(ch==in-2)//ascii ]-[=2 }-{=2
            s.pop();
        else
            judge=false;
    }
}

//bool MYSTACK::judgeOut()
//{
//    return judge;
//}
//
//int MYSTACK::cntOut()
//{
//    return cnt;
//}
//
//int MYSTACK::stacksizeOut()
//{
//    return s.size();
//}

void MYSTACK::print()
{
    if(judge&&s.size()==0)
        cout<<cnt<<" yes";
    else
        cout<<cnt<<" no";
}
