#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> ans;
        int len=nums.size();
        if(len<2)
            return len;
        vector<int> direction(len,0);
        vector<int> length(len,0);

        for(int i=1;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]-nums[j])*direction[j]<0&&length[i]<length[j]+1)
                {
                    length[i]=length[j]+1;
                    direction[i]=nums[i]-nums[j];
                }
                else if(direction[j]==0&&length[i]<length[j]+1)
                {
                    if(nums[i]==nums[j])
                        continue;
                    length[i]=max(length[i],length[j]+1);
                    direction[i]=nums[i]-nums[j];
                }
            }
        }

        return *max_element(length.begin(),length.end())+1;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().wiggleMaxLength(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
