#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        string ans;
        char small='z'+1,big='a'-1;
        int idxs,idxb;
        while(s.size()!=0)
        {
            char smaller='a'-2,bigger='z'+2;
            while(s.size()!=0)
            {
                small='z'+1;
                idxs=-1;
                for(int i=0;i<s.size();i++)
                {
                    if(small>s[i]&&s[i]>smaller)
                    {
                        small=s[i];
                        idxs=i;
                    }
                }
                if(idxs==-1)
                    break;
                else
                {
                    smaller=small;
                    ans+=small;
                    s.erase(s.begin()+idxs);
                }
            }

            while(s.size()!=0)
            {
                big='a'-1;
                idxb=-1;
                for(int i=0;i<s.size();i++)
                {
                    if(big<s[i]&&s[i]<bigger)
                    {
                        big=s[i];
                        idxb=i;
                    }
                }
                if(idxb==-1)
                    break;
                else
                {
                    bigger=big;
                    ans+=big;
                    s.erase(s.begin()+idxb);
                }
            }

        }
        return ans;
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
        string s = stringToString(line);

        string ret = Solution().sortString(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
