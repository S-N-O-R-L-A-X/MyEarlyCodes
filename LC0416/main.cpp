#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    vector<bool> check;
    void dfs(vector<int> nums,int s,int a,bool &flag)
    {
        if(flag)
            return ;
        if(s>a)
            return ;
        else if(s==a)
        {
            flag=true;
            return ;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(check[i])
            {
                check[i]=false;
                dfs(nums,s+nums[i],a,flag);
                check[i]=true;
            }
        }

    }
    */


    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        sum/=2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>sum)
                return false;
            else if(nums[i]==sum)
                return true;
        }

        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        //true means can get the num by choosing number from 0 to i
        for(int i=0;i<n;i++)
            dp[i][0]=true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=nums[i])
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-nums[i]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        /*
        check.resize(nums.size(),true);
        bool flag=false;
        dfs(nums,0,sum,flag);
        */
        return dp[n-1][sum];
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().canPartition(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
