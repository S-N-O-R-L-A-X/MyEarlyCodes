#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isConnected(const vector<int> &a,const vector<int> &b)
    {
        return a[0]==b[0]||a[0]==b[1]||a[1]==b[0]||a[1]==b[1];
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=pairs.size(),len=s.size();
        vector<char> ans(len);
        vector<bool> visited(n);
        queue<vector<int>> q;
        vector<int> changeidx(len,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                q.push(pairs[i]);

                while(!q.empty())
                {
                    vector<int> root=q.front();
                    q.pop();
                    visited[i]=true;
                    changeidx[root[0]]=1;
                    changeidx[root[1]]=1;
                    for(int j=0;j<n;j++)
                    {
                        if(!visited[j]&&isConnected(root,pairs[j]))
                        {
                            q.push(pairs[j]);
                            visited[j]=true;
                        }
                    }
                }

                string tmp="";
                for(int j=0;j<len;j++)
                {
                    if(changeidx[j])
                        tmp+=s[j];
                }

                sort(tmp.begin(),tmp.end());
                int k=0;
                for(int j=0;j<len;j++)//change
                {
                    if(changeidx[j])
                        ans[j]=tmp[k++];
                }
            }
            for(int j=0;j<len;j++)
                changeidx[j]=0;
        }
        string ret;
        for(int i=0;i<len;i++)
        {
            if(ans[i])
                ret+=ans[i];
            else
                ret+=s[i];
        }



        return ret;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> v;
    int x,y;
    while(cin>>x>>y&&x!=-1&&y!=-1)
    {
        v.push_back({x,y});
    }
    s.smallestStringWithSwaps("dcab",v);
    return 0;
}

/*
test:
"udyyek"
3 3 3 0 5 1 3 1 3 4 3 5 -1 -1
*/
