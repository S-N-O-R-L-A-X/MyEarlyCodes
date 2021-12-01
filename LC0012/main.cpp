#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int m=0,c=0,d=0,l=0,x=0,v=0,i=0;
        int h=0,t=0,g=0,n=0,f=0;
        //while(num)
        //{
            m=num/1000;
            num%=1000;
            h=num/100;
            num%=100;
            t=num/10;
            num%=10;
            g=num;
            string ans="";
            for(int i=0;i<m;i++)//>1000
                ans+='M';

            if(h==9||h==4)//>100
            {
                if(h==9)
                    ans+="CM";
                else
                    ans+="CD";
            }
            else
            {
                if(h>=5)
                {
                    ans+='D';
                    h-=5;
                }
                for(int i=0;i<h;i++)
                    ans+='C';
            }

            if(t==9||t==4)//>10
            {
                if(t==9)
                    ans+="XC";
                else
                    ans+="XL";
            }
            else
            {
                if(t>=5)
                {
                    ans+='L';
                    t-=5;
                }
                for(int i=0;i<t;i++)
                    ans+='X';
            }

            if(g==9||g==4)
            {
                if(g==9)
                    ans+="IX";
                else
                    ans+="IV";
            }
            else
            {
                if(g>=5)
                {
                    ans+='V';
                    g-=5;
                }
                for(int i=0;i<g;i++)
                    ans+='I';
            }
            return ans;
        //}
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
