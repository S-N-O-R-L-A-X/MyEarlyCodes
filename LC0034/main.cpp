#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        int left=0,right=nums.size()-1;
        int ans=-1;
        while(ans==-1)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                ans=mid;
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
            if(left>right&&ans==-1)
                return {-1,-1};
        }

        int ansL=ans,ansR=ans;
        left=0;
        right=ans;

        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
            {
                ansL=mid;
                right=mid-1;
            }
            else if(nums[mid]<target)
                left=mid+1;
        }

        left=ans;
        right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
            {
                ansR=mid;
                left=mid+1;
            }
            else if(nums[mid]>target)
                right=mid-1;
        }
        return {ansL,ansR};
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
