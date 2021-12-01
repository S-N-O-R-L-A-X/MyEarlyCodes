#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_set<char>> v;
        int len=strs.size();
        vector<vector<string>> ans;
        for(int i=0;i<len;i++)
        {
            unordered_set<char> tmp(strs[i].begin(),strs[i].end());
            bool flag=true;
            for(int j=0;j<v.size();j++)
            {
                if(v[j]==tmp)
                {
                    ans[j].push_back(strs[i]);
                    flag=false;
                }

            }
            if(flag)
                ans.push_back({strs[i]});
        }
        return ans;
    }
};

int main()
{

    vector<string> v={"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> ans=s.groupAnagrams(v);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
