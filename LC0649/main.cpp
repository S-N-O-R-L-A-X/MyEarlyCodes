#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        while(true)
        {
            for(int i=0;i<senate.size();i++)
            {
                if(senate[i]=='R')
                {
                    string tmp(senate,i+1);
                    if(tmp.find('D')==tmp.npos)
                    {
                        if(senate.find('D')==senate.npos)
                            return "Radiant";
                        else
                            senate.erase(senate.begin()+senate.find('D'));
                    }
                    else
                        senate.erase(senate.begin()+tmp.find('D')+i+1);

                    if(senate.size()==1)
                        return "Radiant";
                }
                else
                {
                    string tmp(senate,i+1);
                    if(tmp.find('R')==tmp.npos)
                    {
                        if(senate.find('R')==senate.npos)
                            return "Dire";
                        else
                            senate.erase(senate.begin()+senate.find('R'));
                    }
                    else
                        senate.erase(senate.begin()+tmp.find('R')+i+1);

                    if(senate.size()==1)
                        return "Dire";
                }
            }
        }

        /*
        int len=senate.size();
        //bool ban[len];
        //memset(ban,false,sizeof(bool)*len);
        int Rban=-1,Dban=-1;
        while(true)
        {
            for(int i=0;i<len;i++)
            {
                if(senate[i]=='R')
                {
                    if(i>Rban)//senate[i] hasn't been banned
                    {
                        string tmp(senate,i+1);//ban the senate after i priorly
                        if(tmp.find('D')==tmp.npos)
                        {
                            string tmp2(senate,Dban+1);
                            if(tmp2.find('D')==tmp2.npos)
                                return "Radiant";
                            else
                                Dban=tmp2.find('D')+Dban+1;
                        }
                        else
                        {
                            instring tmp(senate,i+1);
                    if(tmp.find('D')==tmp.npos)
                    {
                        if(senate.find('D')==senate.npos)
                            return "Radiant";
                        else
                            senate.erase(senate.find('D'));
                    }
                    else
                        senate.erase(tmp.find('D')+i+1);t u=Dban;
                            Dban=tmp.find('D')+i+1;
                            if(u==Dban)
                                return "Radiant";
                        }

                    }
                }
                else
                {
                    if(i>Dban)//senate[i] hasn't been banned
                    {
                        string tmp(senate,i+1);
                        if(tmp.find('R')==tmp.npos)
                        {
                            string tmp2(senate,Rban+1);
                            if(tmp2.find('R')==tmp2.npos)
                                return "Dire";
                            else
                                Rban=tmp2.find('R')+Rban+1;
                        }
                        else
                        {
                            int u=Rban;
                            Rban=tmp.find('R')+i+1;
                            if(u==Rban)
                                return "Dire";
                        }
                    }
                }
            }
        }
        */

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
        string senate = stringToString(line);

        string ret = Solution().predictPartyVictory(senate);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
