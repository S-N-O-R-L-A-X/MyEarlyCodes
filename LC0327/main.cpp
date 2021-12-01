#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        unordered_set<int> s;
        for(int len=1;len<=nums.size();len++)//control len
        {
            for(int j=0;j<=nums.size()-len;j++)//control start
            {
                int sum=0;
                for(int k=j;k<j+len;k++)
                {
                    sum+=nums[k];
                }
                if(sum>=lower&&sum<=upper)
                    s.insert(sum);
            }
        }
        return s.size();
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int lower = stringToInteger(line);
        getline(cin, line);
        int upper = stringToInteger(line);

        int ret = Solution().countRangeSum(nums, lower, upper);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
