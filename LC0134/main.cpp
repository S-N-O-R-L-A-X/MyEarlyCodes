#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len=gas.size();
        for(int start=0;start<len;start++)
        {
            int gasoline=gas[start];
            int now=start;
            bool flag=true;
            for(int cnt=0;cnt<len;cnt++)
            {
                gasoline-=cost[now];
                if(gasoline<0)
                {
                    flag=false;
                    break;
                }

                now=(now+1)%len;//move
                gasoline+=gas[now];//add
            }
            if(flag)
                return start;
        }
        return -1;
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
        vector<int> gas = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> cost = stringToIntegerVector(line);

        int ret = Solution().canCompleteCircuit(gas, cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
