#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if (strs.size()==0) return "";
    else if (strs.size()==1) return strs[0];
    string prefix = strs[0];
    int index = 0;
    for (int i = 1; i < strs.size(); ++i){
        index = 0;
        while (index < prefix.size() && index < strs[i].size()){
            if (prefix[index] == strs[i][index])
                index++;
            else break;
        }
        prefix = strs[0].substr(0,index);
    }
    return prefix;
}
int main()
{
    vector<string> strs;
    int n;
    cin>>n;
    string tmp;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        strs.push_back(tmp);
    }
    cout<<longestCommonPrefix(strs);
}
