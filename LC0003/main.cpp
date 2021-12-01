#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int left=0;
        unordered_set<char> index;
        index.clear();
        for(int right=0;right<s.size();right++)
        {
            if(index.find(s[right])==index.end())//not find
            {
                index.insert(s[right]);
                if(right==s.size()-1)
                    maxlen=(maxlen<(right-left+1)?(right-left+1):maxlen);
            }
            else
            {
                maxlen=(maxlen<(right-left)?(right-left):maxlen);
                while(index.find(s[right])!=index.end())
                {
                    index.erase(s[left]);
                    left++;
                }
                index.insert(s[right]);
            }
        }
        return maxlen;
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
