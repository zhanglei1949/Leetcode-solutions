#include<iostream>

using namespace std;

int uniquePaths(int m, int n)
{
    if (m==0 || n==0) return 0;
    int **dp = new int * [m];
    for (int i = 0; i < m; ++i){
        dp[i] = new int [n];
        if (i==0){
            for (int j = 0;j < n; ++j) dp[i][j] = 1;
            continue;
        }
        for (int j = 1; j < n; ++j){
            dp[i][j] = 0;
        }
        dp[i][0] = 1;
    }
    for (int i = 1; i < m; ++i){
        for (int j = 1; j < n; ++j){
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
//    for (int i = 0; i < m; ++i){
//        for (int j = 0; j < n; ++j){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[m-1][n-1];
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n);
}
