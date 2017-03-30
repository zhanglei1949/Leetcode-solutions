#include<iostream>
#include<vector>
using namespace std;

vector<string> letterCombinations(string digits)
{
    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if (digits.size()==0){
        return res;
    }
    res.push_back("");
    int index;
    for (int i = 0; i < digits.size(); ++i){
        index = digits[i]-'0';
        int formerSize = res.size();
        for (int j = 0; j < formerSize; ++j){
            for (int k = 0; k < mapping[index].size(); ++k){
                res.push_back(res[j]+mapping[index][k]);
            }
        }
        for (int j = 0; j < formerSize; ++j){
            res.erase(res.begin());
        }
//        for (int j = 0; j < res.size(); ++j){
//            cout<<res[j]<<" ";
//        }
//        cout<<endl;
    }
    return res;
}
int main()
{
    string digits;
    cin>>digits;
    letterCombinations(digits);
}
