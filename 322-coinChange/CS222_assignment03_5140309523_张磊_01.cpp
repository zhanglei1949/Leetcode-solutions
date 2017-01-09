#include<iostream>
#include<cstring>

#define MAX_AMOUNT 2000
#define COINS_TYPE 20
#define MAXIMUM 111111
using namespace std;

int dp[MAX_AMOUNT];
int coins[COINS_TYPE];
int makeUpAmount(int n, int amount)
{
    for (int i = 0; i <= amount; ++i){
        dp[i] = MAXIMUM;
    }
    for (int i = 0; i < n; ++i){
        dp[coins[i]] = 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i){
        for (int j = 0; j < n && coins[j] < i ; ++j){
            dp[i] = min(dp[i-coins[j]]+1, dp[i]);
        }
    }
//    for (int i = 0; i <= amount; ++i){
//        cout<<dp[i]<<" ";
//    }
//    cout<<endl;
    if (dp[amount] < 100)
        return dp[amount];
    else return -1;
}
int main()
{
    int n;
    int amount;
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>coins[i];
    }
    cin>>amount;
    cout<<makeUpAmount(n, amount);
}
