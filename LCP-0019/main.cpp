#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        /*
        dp[i][0] means leaf i is in former red.
        dp[i][1] means leaf i is yellow.
        dp[i][2] means leaf i is in latter red.
        */
        int n=leaves.size();
        vector<vector<int>> dp(n,vector<int>(3));
        dp[0][0]=(leaves[0]=='y');
        dp[0][1]=dp[0][2]=dp[1][2]=n+1;
        for (int i=1;i<n;++i)
        {
            int isRed=(leaves[i]=='r');
            int isYellow=(leaves[i]=='y');
            dp[i][0]=dp[i-1][0]+isYellow;//dp[i][0] needs dp[i-1][0] to be red
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+isRed;
            if(i>=2)
                dp[i][2]=min(dp[i-1][1],dp[i-1][2])+isYellow;
        }
        return dp[n-1][2];
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
        string leaves = stringToString(line);

        int ret = Solution().minimumOperations(leaves);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
