#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<bool> check;
    vector<vector<int>> arr;
    vector<int> tmp;
    void recursion(vector<int> nums,int len)
    {
        if(tmp.size()==len)
        {
            arr.push_back(tmp);
            return ;
        }

        for(int i=0;i<len;i++)
        {
            if(check[i])
            {
                check[i]=false;
                tmp.push_back(nums[i]);
                recursion(nums,len);
                tmp.pop_back();
                check[i]=true;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        arr.clear();
        check.resize(len,true);
        recursion(nums,len);
        return arr;
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    for(int i=0;i<3;i++)
    {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    vector<vector<int>> ans=s.permute(arr);
    for(int i=0;i<ans.size();i++)
    {
        vector<int> v=ans[i];
        for(int j=0;j<v.size();j++)
            cout<<v[j]<<' ';
        cout<<endl;
    }
    return 0;
}
