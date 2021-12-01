#include <iostream>

using namespace std;

int main()
{
    int left=0,right;
    string s,t;
    cin>>s>>t;
    int ansr=s.size()-1,ansl=-1;//ansl checks if there is no answer
    int hashS[150]={0};//use ascii to construct hash table
    int hashT[150]={0};//can't use alphabet because tests have both capitalized and uncapitalized
    int minlen=999999;
    int cnt=0;//count how many alphas are matched
    for(int i=0;i<t.size();i++)
        hashT[t[i]]++;
    for(right=0;right<s.size();right++)
    {
        hashS[s[right]]++;
        if(hashS[s[right]]<=hashT[s[right]])//ensure that the char is needed
            cnt++;
        if(cnt==t.size())
        {
            while(left<right&&hashS[s[left]]>hashT[s[left]])
                hashS[s[left++]]--;//beginning shift right 1
            if(right-left<minlen)
            {
                minlen=right-left;
                ansr=right;
                ansl=left;
            }
            hashS[s[left++]]--;//beginning shift right 1 and search for the next window
            cnt--;
        }
    }
    if(ansl==-1)
        cout<<"NULL";
    else
    {
        for(int i=ansl;i<=ansr;i++)
            cout<<s[i];
    }
    return 0;
}
