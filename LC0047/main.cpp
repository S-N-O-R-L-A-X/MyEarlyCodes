#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<bool> check;
    void recursion(const vector<int> &nums,int len)
    {
        if(tmp.size()==len)
        {
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]==tmp)
                    return ;
            }
            ans.push_back(tmp);
            return ;

        }
        for(int i=0;i<len;i++)
        {
            if(check[i])
            {
                check[i]=false;
                tmp.push_back(nums[i]);
                recursion(nums,len);
                check[i]=true;
                tmp.pop_back();
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len=nums.size();
        tmp.clear();
        check.resize(len,true);
        recursion(nums,len);
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> arr;
    int tmp;
    while(cin>>tmp)
        arr.push_back(tmp);

    vector<vector<int>> ans=s.permuteUnique(arr);
    for(int i=0;i<ans.size();i++)
    {
        vector<int> v=ans[i];
        for(int j=0;j<v.size();j++)
            cout<<v[j]<<' ';
        cout<<endl;
    }
    return 0;
}
