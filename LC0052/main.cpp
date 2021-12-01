#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> col;
    vector<int> tmp;//tmp[i] means col,i means row

    bool check(int num)
    {
        if(!col[num])
            return false;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]-i==num-tmp.size())
                return false;
            else if(tmp[i]+i==num+tmp.size())
                return false;
        }
        return true;
    }

    void queen(int n,int &ans)
    {
        if(tmp.size()==n)
        {
            ans++;
//            for(int j=0;j<n;j++)
//                cout<<tmp[j];
//            cout<<endl;
            return ;
        }

        for(int i=0;i<n;i++)//control column
        {
            if(check(i))
            {
                col[i]=false;
                tmp.push_back(i);
                queen(n,ans);
                tmp.pop_back();
                col[i]=true;
            }
        }
    }
    int totalNQueens(int n) {
        col.resize(n,true);
        int ans=0;
        queen(n,ans);
        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().totalNQueens(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
