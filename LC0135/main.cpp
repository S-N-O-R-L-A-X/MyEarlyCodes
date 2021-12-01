#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int delim=0,len=ratings.size();
        if(len==0)
            return 0;
        else if(len==1)
            return 1;
        int m=ratings[0];
        for(int i=1;i<len;i++)
        {
            if(ratings[i]<m)
            {
                delim=i;
                m=ratings[i];
            }
        }

        vector<int> ans(len,1);

        for(int i=delim-1;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                ans[i]=ans[i+1]+1;
            else if(ratings[i]<ratings[i+1]&&ans[i+1]==1)
            {
                for(int j=i+1;j<=delim-1;j++)
                {
                    if(ratings[j]<=ratings[j+1])
                    {
                        ans[j]++;
                        if(ans[j]<ans[j+1])
                            break;
                    }
                    else
                    {
                        ans[j]++;
                        break;
                    }
                }
            }
        }

        for(int i=delim+1;i<len;i++)
        {
            if(ratings[i]>ratings[i-1])
                ans[i]=ans[i-1]+1;
            else if(ratings[i]<ratings[i-1]&&ans[i-1]==1)
            {
                for(int j=i-1;j>=delim+1;j--)
                {
                    if(ratings[j]<=ratings[j-1])
                    {
                        ans[j]++;
                        if(ans[j]<ans[j-1])
                            break;
                    }
                    else
                    {
                        ans[j]++;
                        break;
                    }
                }
            }
        }

        return accumulate(ans.begin(),ans.end(),0);

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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> ratings = stringToIntegerVector(line);

        int ret = Solution().candy(ratings);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
