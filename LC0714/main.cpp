#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size();
        vector<int> delta;
        for(int i=1;i<len;i++)
            delta.emplace_back(prices[i]-prices[i-1]);
        int sum=0,tmp=0,origin=0;
        for(int i=0;i<len-1;i++)
        {
            if(delta[i]>0)
                tmp+=delta[i];
            else
            {
                if(fee+delta[i]<0||tmp+delta[i]<0)//should be sold
                {
                    int m=max(origin,tmp);
                    if(m-fee>0)
                        sum=sum+m-fee;
                    origin=0;
                    tmp=0;
                }
                else
                {

                    if(origin==0)
                        origin=tmp;
                    tmp+=delta[i];
                }
            }

            if(origin-tmp>fee)//lose too much
            {
                if(origin-fee>0)
                    sum+=(origin-fee);
                origin=0;
                tmp=0;
            }
            int m=max(origin,tmp);
            if(m-fee>0&&i==len-2)
                sum+=(m-fee);
        }
        return sum;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);
        getline(cin, line);
        int fee = stringToInteger(line);

        int ret = Solution().maxProfit(prices, fee);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
