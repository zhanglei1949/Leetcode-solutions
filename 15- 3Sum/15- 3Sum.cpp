#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 vector<vector<int> > threeSum(vector<int>& nums)
 {
    vector<vector<int> > res;
    sort(nums.begin(), nums.end());
    // reduct three sum to two sum
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] > 0)
            break;//
        if (i > 0 && nums[i] == nums[i-1])
            continue;

        int target = 0 - nums[i];
        int j = i+1;
        int k = nums.size()-1;
        while (j < k){
            if (nums[j]+nums[k] == target){
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                tmp.push_back(nums[k]);
                res.push_back(tmp);
                while (j < k && nums[j+1]==nums[j])
                    ++j;
                while (j < k && nums[k-1]==nums[k]){
                    --k;
                }
                ++j; --k;
            }
            else if (nums[j]+nums[k] < target){
                ++j;
            }
            else{
                --k;
            }
        }
    }
//    for (int i = 0; i < res.size(); ++i){
//        for (int j = 0; j < 3; ++j){
//            cout<<res[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return res;
 }
int main()
{
    vector<int> nums;
    int n;
    cin>>n;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    threeSum(nums);
}
//6 -1 0 -1 1 2 -4
