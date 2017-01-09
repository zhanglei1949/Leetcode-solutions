#include<iostream>
#include<vector>
#define _MAX 1e8
using namespace std;
int findMaxForm(vector<string> &strs, int m, int n)
{
    int dp[105][105]={0};//dp[m][n] indicate the number of strings obtains.
    int len = strs.size();
    int zeros, ones;
//    for (int i = 0; i < len; ++i){
//        int l = strs[i].length();
//        for (int j = 0; j < l; ++j){
//            if (strs[i][j] == '0')
//                info_str[i][0]+=1;
//            else
//                info_str[i][1]+=1;
//        }
//        //cout<<info_str[i][0]<<" "<<info_str[i][1]<<" "<<l<<endl;
//    }
//    //dp[0][0]=0;// m 0s and n 1s unused
    for (int i = 0; i < len; ++i){
        //every string
        zeros = 0;
        ones = 0;
        int l = strs[i].length();
        for (int j = 0; j < l; ++j){
            if (strs[i][j] == '0')
                zeros+=1;
            else
                ones+=1;
        }
        for (int j = m; j >= zeros; --j){
            for (int l = n; l >= ones; --l){
                dp[j][l] = max(dp[j-zeros][l-ones]+1, dp[j][l]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    vector<string> strs;
    strs.push_back("10");
    strs.push_back("0001");
    strs.push_back("111001");
    strs.push_back("1");
    strs.push_back("0");
    cout<<findMaxForm(strs,5,3);
}
