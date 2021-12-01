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
bool pushNum(char *digit, bool flag);
void Fop(char ch);
void finalCalc();
void print(bool output);

int main()
{
    string input;
    cin >> input;
    char digit[20];
    bool flag = true;
    bool output=true;//judge whether the input has float number
    for (int i = 0; i < input.length();)
    {
        if (i==0&&input[i] == '-')
        {
            flag = false;
            i++;
        }//a wrong but effective method :just judge whether the first number is <0  
        
        if (isdigit(input[i]) || input[i] == '.')
        {
            int j = 0;
            while (isdigit(input[i]) || input[i] == '.')
            {
                if (isdigit(input[i]))
                    digit[j++] = input[i];
                else
                {
                    digit[j++] = '.';
                    output = false;
                }
                i++;
            }
            digit[j] = '\0';
            char *p = digit;
            flag=pushNum(p, flag);
        }//read in numbers
        else
        {
            if (op.size() == 0)
                op.push(input[i++]);
            else
                Fop(input[i++]);
        }
    }
    finalCalc();//deal with the rest in the stack
    print(output);
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

bool pushNum(char *digit,bool flag)
{
    if (flag)
        num.push(atof(digit));
    else
        num.push(-atof(digit));
    return true;
}

void Fop(char ch)
{
    int p1 = priority(ch);
    if (p1 == 3)
    {
        while (op.top() != '(')
        {
            calc(op.top());
            op.pop();
        }
        op.pop();
    }
    else if (p1 == 0)
        op.push(ch);
    else
    {
        while (!op.empty() && p1 <= priority(op.top()))
        {
            calc(op.top());
            op.pop();
        }
        op.push(ch);
    }
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

void finalCalc()
{
    while (op.size() != 0)
    {
        char ch = op.top();
        op.pop();
        calc(ch);
    }
}

void print(bool output)
{
    double ans = num.top();
    if (ans - (int)ans < 1E-7 && output)
        printf("%.0lf", ans);
    else
        printf("%.3lf", ans);
}


/*origin all passed code
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
    bool flag = true;
    bool output=true;//judge whether the input has float number
    for (int i = 0; i < input.length();)
    {
        if (i==0&&input[i] == '-')
        {
            flag = false;
            i++;
        }

        if (isdigit(input[i]) || input[i] == '.')
        {
            //int start = i;
            int j = 0;
            while (isdigit(input[i]) || input[i] == '.')
            {
                if (isdigit(input[i]))
                    digit[j++] = input[i];
                else
                {
                    digit[j++] = '.';
                    output = false;
                }
                i++;
            }
            digit[j] = '\0';
            if(flag)
                num.push(atof(digit));
            else
            {
                num.push(-atof(digit));
                flag = true;
            }
        }
        else
        {
            if (op.size() == 0)
                op.push(input[i]);
            else
            {
                int p1 = priority(input[i]);

                if (p1 == 3)
                {
                    while (op.top() != '(')
                    {
                        calc(op.top());
                        op.pop();
                    }
                    op.pop();
                    i++;
                    continue;
                }
                else if (p1 == 0)
                {
                    op.push(input[i++]);
                    continue;
                }

                while (!op.empty() && p1 <= priority(op.top()))
                {
                    calc(op.top());
                    op.pop();
                }
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
    double ans = num.top();
    if (ans - (int)ans < 1E-7&&output)
        printf("%.0lf", ans);
    else
        printf("%.3lf", ans);



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
    {
    case '+':num.push(a + b); break;
    case '-':num.push(b - a); break;
    case '*':num.push(a * b); break;
    default:if (a == 0)return false; num.push(b / a); break;
    }
    return true;
}
*/