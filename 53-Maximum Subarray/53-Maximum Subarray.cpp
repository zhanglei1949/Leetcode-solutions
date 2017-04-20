#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    if (nums.size()==1) return nums[0];
    int res = -10000;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i){
        cout<<sum<<endl;
        if (sum > 0){
            sum = sum+nums[i];
        }
        else{
            sum = nums[i];
        }
        res = max(sum, res);
    }
    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout<<maxSubArray(nums);
}
