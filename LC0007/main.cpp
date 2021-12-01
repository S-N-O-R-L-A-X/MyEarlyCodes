#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ans=0;
        bool SF=true;
        if(x==-2147483648)
            return 0;
        if(x<0)
        {
            SF=false;
            x=-x;
        }

        while(x)
        {
            int tmp=x%10;
            ans=ans*10+tmp;
            if(ans>=2147483648||ans<-2147483648)
                return 0;
            x/=10;
        }
        if(!SF)
            ans=-ans;
        return ans;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
