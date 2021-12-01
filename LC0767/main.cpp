#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct alphabet
    {
        int cnt;
        char c;
    };
    string reorganizeString(string S) {
        int len=S.size();
        int ans[len];
        for(int i=0;i<len;i++)
            ans[i]=0;

        alphabet arr[26];
        for(int i=0;i<26;i++)
        {
            arr[i].c='a'+i;
            arr[i].cnt=0;
        }

        for(int i=0;i<S.size();i++)
        {
            arr[S[i]-'a'].cnt++;
            if(arr[S[i]-'a'].cnt>(len+1)/2)
                return "";
        }



        sort(arr,arr+26,[](alphabet a,alphabet b)
        {
            return a.cnt>b.cnt;
        });
        int place=0;
        for(int i=0;i<26;i++)
        {

            while(arr[i].cnt)
            {
                place%=len;
                if(ans[place]==0)//ans[place] is vacant
                {
                    ans[place]=arr[i].c;
                    arr[i].cnt--;
                    place+=2;
                }
                else
                    place++;
            }
        }
        string r;
        for(int i=0;i<len;i++)
            r+=(char)ans[i];
        return r;
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
        string S = stringToString(line);

        string ret = Solution().reorganizeString(S);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
