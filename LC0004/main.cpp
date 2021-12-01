#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double find_MID(vector<int> &nums1)
    {
        double a;
        if(nums1.size()%2)
            a=(double)nums1[nums1.size()/2];
        else
        {
            int tmp1=nums1[nums1.size()/2-1];
            int tmp2=nums1[nums1.size()/2];
            a=(double)(tmp1+tmp2)/2;
        }

        return a;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double a=find_MID(nums1),b=find_MID(nums2);
        return 0.5*(a+b);
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
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
