#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void recursive(string ring,string key,int &ans)
    {
        int cnt=0,len=ring.size(),pointer=0;//pointer points the idx of ring at 12
        string str=ring;
        for(int i=0;i<key.size();i++)
        {
            int right=str.find(key[i]),left=str.rfind(key[i]);

            if(right<len-left)//right is nearer so turn left
            {
                cnt+=(right+1);
                string tmp1(str,0,right),tmp2(str,right,len);
                str=tmp2+tmp1;
//                reverse(str.begin(),str.end());
            }
            else if(right>len-left)
            {
                cnt+=(len-left+1);
                string tmp1(str,0,left),tmp2(str,left,len);
                str=tmp2+tmp1;
            }
            else
            {

            }
        }
    }

    int findRotateSteps(string ring, string key) {
        int cnt=0,len=ring.size(),pointer=0;//pointer points the idx of ring at 12
        string str=ring;
        for(int i=0;i<key.size();i++)
        {
            int right=str.find(key[i]),left=str.rfind(key[i]);

            if(right<len-left)//right is nearer so turn left
            {
                cnt+=(right+1);
                string tmp1(str,0,right),tmp2(str,right,len);
                str=tmp2+tmp1;
//                reverse(str.begin(),str.end());
            }
            else
            {
                cnt+=(len-left+1);
                string tmp1(str,0,left),tmp2(str,left,len);
                str=tmp2+tmp1;
            }
        }
        return cnt;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string ring = stringToString(line);
        getline(cin, line);
        string key = stringToString(line);

        int ret = Solution().findRotateSteps(ring, key);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
