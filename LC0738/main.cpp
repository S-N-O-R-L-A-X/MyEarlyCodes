#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> v;
        if(N<10)
            return N;
        while(N)
        {
            v.emplace_back(N%10);
            N/=10;
        }

        bool unchanged=true;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]>v[i-1])
            {
                if(!unchanged||i==v.size()-1)
                {
                    v[i]--;
                    for(int j=0;j<i;j++)
                        v[j]=9;
                }
                else
                {
                    unchanged=false;
                    v[i]--;
                    for(int j=0;j<i;j++)
                        v[j]=9;
                }
            }
        }
        int ans=0;
        for(int i=v.size()-1;i>=0;i--)
            ans=ans*10+v[i];

        return ans;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = stringToInteger(line);

        int ret = Solution().monotoneIncreasingDigits(N);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
