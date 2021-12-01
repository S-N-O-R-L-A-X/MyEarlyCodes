#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &clip1,vector<int> &clip2)
    {
        if(clip1[0]!=clip2[0])
            return clip1[0]<clip2[0];
        return clip1[1]>clip2[1];
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end(),cmp);
        vector<int> dp;
        dp.resize(T+1,-1);
        if(clips[0][0]==0)
            dp[0]=1;
        else
            return -1;
        for(int i=0;i<clips.size();i++)
        {
            int start=clips[i][0],last=clips[i][1];
            if(start>=T)
                break;

            int m=dp[start];

            if(dp[start]==-1)
                return -1;
            for(int j=start+1;j<=last&&j<=T;j++)
            {
                if(dp[j]==-1)
                {
                    if(start==0)
                        dp[j]=1;
                    else
                       dp[j]=m+1;
                }
                else
                {
                    dp[j]=min(m+1,dp[j]);
                    m=min(dp[j],m);
                }

            }
        }
        return dp[T];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr;
    int x,y,t;
    while(cin>>x>>y)
    {
        if(x==-1&&y==-1)
            break;
        vector<int> tmp={x,y};
        arr.push_back(tmp);
    }
    cin>>t;
    cout<<s.videoStitching(arr,t);

}

/*
test 1:
0 2 4 6 8 10 1 9 1 5 5 9 -1 -1
10

test 2:
0 4 2 8 -1 -1
5

test 3:
5 7 1 8 0 0 2 3 4 5 0 6 5 10 7 10 -1 -1
5

test 4:
3 12 7 14 9 14 12 15 0 9 4 14 2 7 1 11 -1 -1
10

*/

