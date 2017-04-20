#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs)
{
    vector<vector<string> > res;
    map<string, multiset<string> > m;
    map<string, multiset<string> >::iterator iter;
    for (int i = 0; i < strs.size(); ++i){
        string t = strs[i];
        sort(t.begin(), t.end());
        cout<<t<<endl;
        m[t].insert(strs[i]);
    }
    for (iter = m.begin(); iter != m.end(); ++iter){
        vector<string> tmp(iter->second.begin(), iter->second.end());
        res.push_back(tmp);
    }
    return res;
}
int main()
{
    vector<string> strs;
    string str;
    strs.push_back("eat");
    strs.push_back("eta");
    strs.push_back("tan");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string> > res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            string s = res[i][j];
            cout<<s<<" ";
        }
        cout<<endl;
    }
}
