#include<iostream>
#include<string>
using namespace std;
// from back to front, dp[i] = min(dp[i], dp[j+1]+1}; arr[i]==arr[j]
// first store the palindrome information


int minCut(string s)
{
    int length = s.length();
    int **palindrome;
    int *dp;
    dp = new int [length+1];
    palindrome = new int *[length];
    for (int i = 0; i < length; ++i){
        palindrome[i] = new int [length];
    }
    for (int i = 0; i < length; ++i){
        dp[i] = length - i;
    }
    dp[length] = 0;
    for (int i = length - 1; i >= 0; --i){
        for (int j = i; j < length; ++j){
            if (s[i]==s[j]){
                if (j-i < 2 || palindrome[i+1][j-1]){
                    dp[i] = min(dp[i], dp[j+1]+1);
                    palindrome[i][j] = 1;
                }
                else {
                    palindrome[i][j] = 0;
                }
            }
            else {
                palindrome[i][j] = 0;
            }
        }
    }
//    for (int i = 0; i < length; ++i){
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    return dp[0]-1;
}
int main()
{
    string s;
    cin>>s;
    cout<<minCut(s);
    return 1;
}
