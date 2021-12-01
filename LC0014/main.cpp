#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        bool out=true,flag=true;//out shows whether reaches the min len of one of strings
        int cnt=0;
        for(int i=0;i<strs[0].size()&&flag;i++)
        {
            char ch=strs[0][i];
            for(int j=0;j<strs.size();j++)
            {
                if(i>strs[j].size())
                {
                    out=false;
                    break;
                }

                if(strs[j][i]!=ch)
                {
                    flag=false;

                    break;
                }
            }
            if(flag&&out)
                cnt++;
        }
        string ans(strs[0],0,cnt);
        return ans;
    }
};

int main()
{
    Solution u;
    string
    cout << "Hello world!" << endl;
    return 0;
}
