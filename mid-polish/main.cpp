#include <iostream>
#include <stack>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <stdlib.h>

using namespace std;


stack<double> num;
stack<char> op;

int priority(char x);
bool calc(char ch);


int main()
{
    string input;
    cin >> input;
    char digit[20];
    for (int i = 0; i < input.length();)
    {
        if (isdigit(input[i]) || input[i] == '.')
        {
            int start = i;
            int j = 0;
            while (isdigit(input[i]) || input[i] == '.')
            {
                if (isdigit(input[i]))
                    digit[j++] = (input[start]);
                else
                    digit[j++] = '.';
                i++;
            }
            digit[j] = '\0';
            num.push(atof(digit));
        }
        else
        {
            if (op.size() == 0)
                op.push(input[i]);
            else
            {
                int p1 = priority(input[i]);
                int p2 = priority(op.top());
                if (p1 == 3)
                {
                    while (op.top()!='(')
                    {
                        calc(op.top());
                        op.pop();
                    }
                    op.pop();
                    continue;
                }
                else if (p1 == 0)
                {
                    op.push(input[i]);
                    continue;
                }
                if (p1 <= p2)
                    calc(op.top());
                else
                    op.push(input[i]);
            }
            i++;
        }
    }

    while (op.size() != 0)
    {
        char ch = op.top();
        op.pop();
        calc(ch);
    }
    cout << num.top();
    /*while(input.size()!=1)
    {
        char ch=input.top();
        input.pop();
        int p1=priority(ch);
        int p2=priority(input.top());
        if()
    }*/

    return 0;
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == ')')
        return 3;
    return 0;
}

bool calc(char ch)
{
    double a = num.top();
    num.pop();
    double b = num.top();
    num.pop();
    switch (ch)
    {
    case '+':num.push(a + b); break;
    case '-':num.push(b - a); break;
    case '*':num.push(a * b); break;
    default:if (a == 0)return false; num.push(b / a); break;
    }
    return true;
}
