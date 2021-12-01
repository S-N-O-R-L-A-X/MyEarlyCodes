#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26]={0};
        for(const char &ch:s)
            cnt[ch-'a']++;
        vector<char> ans;
        for(auto ch:s)
        {

            while(!ans.empty()&&ch<ans.back()&&cnt[ans.back()-'a'])
            {
                ans.pop_back();
            }
            ans.emplace_back(ch);
            cnt[ch-'a']--;
        }
        string ret(ans.begin(),ans.end());
        return ret;
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
        string s = stringToString(line);

        string ret = Solution().removeDuplicateLetters(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
