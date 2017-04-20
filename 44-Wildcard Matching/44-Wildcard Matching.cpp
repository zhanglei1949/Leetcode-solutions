#include<iostream>

using namespace std;

bool isMatch(string s, string p)
{
    int ls = s.size();
    int lp = p.size();
    int str_p = 0;
    int pat_p = 0;
    int star = -1;
    int ss = 0;
    while (str_p < s.size()){
//        for (int i = str_p; i < ls; ++i) cout<<s[i]<<" ";
//        cout<<endl;
//        for (int j = pat_p; j < lp; ++j) cout<<p[j]<<" ";
//        cout<<endl;
//        cout<<pat_p<<" "<<endl;
//        cout<<"--------------------------------------------"<<endl;
        if ((p[pat_p]=='?') || (p[pat_p]==s[str_p])){
            str_p++;
            pat_p++;
        }
        else if (p[pat_p]=='*'){
            star = pat_p++;
            ss = str_p;
        }
        else if (star!=-1){
            pat_p = star+1;
            str_p = ++ss;
        }
        else return false;
    }
    while (pat_p < lp && p[pat_p]=='*') pat_p++;
    return pat_p==lp;
}

int main()
{
    string s,p;
    cin>>s>>p;
    cout<<isMatch(s,p);
}
