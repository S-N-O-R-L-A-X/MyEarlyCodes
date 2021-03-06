#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        int len=s.size();
        vector<vector<int>> arr;
        arr.clear();
        arr.resize(numRows);
        int x=0,cnt=0;
        bool up=false;
        while(true)
        {
            if(cnt==len)
                break;
            arr[x].push_back(cnt++);
            if(up)
                x--;
            else
                x++;
            if(x==numRows)
            {
                x-=2;
                up=true;
            }
            if(x<0)
            {
                x+=2;
                up=false;
            }

        }
        char ans[len+1];
        int pos=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                ans[pos++]=s[arr[i][j]];
            }
        }
        ans[len]='\0';
        string str(ans);
        return str;
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
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
