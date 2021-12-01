#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int len=nums.size();
        for(int i=0;i<len-3;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
                break;//be careful that it is reasonable that nums[i] can be bigger than target
            if(nums[i]+nums[len-1]+nums[len-2]+nums[len-3]<target)
                continue;
            for(int j=i+1;j<len-2;j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1])
                    continue;
                int tmp2=nums[i]+nums[j];
                int left=j+1,right=len-1;
                while(left<right)
                {
                    int tmp4=tmp2+nums[left]+nums[right];
                    if(tmp4==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        //the following steps skip the repeated answers
                        while(nums[left]==nums[left+1])
                            left++;
                        left++;
                        while(nums[right]==nums[right-1])
                            right--;
                        right++;
                    }
                    else if(tmp4<target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    int n;
    while(cin>>n)
    {
        nums.push_back(n);
    }
    Solution s;
    vector<vector<int>> ans=s.fourSum(nums,2);
    for(int i=0;i<ans.size();i++)
    {
        vector<int> tmp=ans[i];
        for(int j=0;j<tmp.size();j++)
        {
            cout<<tmp[j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
