#include<iostream>

using namespace std;
bool work(string s, string p, int i, int j);
bool isMatch(string s, string p)
{
    if (p==".*") return true;
    return work(s,p,0,0);
}
bool work(string s, string p, int i, int j)
{
    if (i==s.size() && j==p.size()) return true; //already out of rage.
    if (j < p.size()-1 && p[j+1]=='*'){
        while (s[i]==p[j] || (p[j]=='.' && i < s.size())){
            if (work(s,p,i++,j+2)){
                return true;
            }
        }
        return work(s,p,i,j+2);
    }
    else {
        if (s[i]==p[j] || (p[j]=='.' && i < s.size())){
            return work(s,p,i+1,j+1);
        }
        return  false;
    }
}
int main()
{
    string str, pattern;
    cin>>str>>pattern;
    cout<<isMatch(str, pattern);
}
