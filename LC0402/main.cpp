#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int del=0;
        for(int i=0;i<num.size();i++)
        {
            while(!s.empty()&&del<k&&num[i]<s.top())
            {
                s.pop();
                del++;
            }
            s.push(num[i]);
        }

        while(!s.empty()&&del<k)
        {
            s.pop();
            del++;
        }

        string ans;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='0')
            {
                ans.erase(ans.begin()+i);
                i--;
            }
            else
                break;
        }
        if(ans.size()==0)
            return "0";
        return ans;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num = stringToString(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().removeKdigits(num, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
