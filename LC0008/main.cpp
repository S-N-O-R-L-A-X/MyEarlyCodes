#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int find_head(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0')
                return i;
        }
        return s.size();
    }

    int find_end(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(!isdigit(s[i]))
                return i;
        }
        return s.size();
    }

    int transfer(string s,bool flag)
    {
        int ans=0;
        if(flag)
        {
            if(s.size()>10||(s>="2147483648"&&s.size()==10))
                return INT_MAX;
            for(int i=0;i<s.size();i++)
                ans=ans*10+(s[i]-'0');
            return ans;
        }
        else
        {
            if(s.size()>10||(s>"2147483648"&&s.size()==10))
                return INT_MIN;
            for(int i=0;i<s.size();i++)
                ans=ans*10-(s[i]-'0');
            return ans;
        }
    }

    int find_nonblank(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
                return i;
        }
        return s.size();
    }

    int myAtoi(string str) {
        int trim=find_nonblank(str);
        string trimmed_str(str,trim);
        if(trimmed_str[0]=='+'||trimmed_str[0]=='-')
        {
            string tmp(trimmed_str,1);
            int head=find_head(tmp);
            int last=find_end(tmp);
            string num(tmp,head,last-head);
            if(trimmed_str[0]=='+')
                return transfer(num,true);
            else
                return transfer(num,false);
        }
        else if(isdigit(trimmed_str[0]))
        {
            int head=find_head(trimmed_str);
            int last=find_end(trimmed_str);
            string num(trimmed_str,head,last-head);
            return transfer(num,true);
        }
        else
            return 0;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
