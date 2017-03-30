#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int combinationSum4(vector<int>& nums, int target)
{
    //find the number of solutions
    vector<int> dp(target+1);
    dp[0] = 1;
    //dp[i] = dp[i-nums[j]]+1
    for (int i = 1; i <= target; ++i){
        for (int j = 0; j < nums.size(); ++j){
            if (i >= nums[j]){
                dp[i] += dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}
int main()
{
    vector<int> candidates;
    int target;
    candidates.push_back(2);
    candidates.push_back(1);
    candidates.push_back(3);
    candidates.push_back(-1);
    //candidates.push_back(6);
    //candidates.push_back(7);
    target = 4;
    cout<<combinationSum4(candidates, target);
}
