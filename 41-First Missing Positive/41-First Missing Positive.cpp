#include<iostream>
#include<vector>
using namespace std;
int firstMissingPositive(vector<int> &nums)
{
    int tmp;
    for (int i = 0; i < nums.size(); ++i){
//        cout<<i<<endl;
//        for (int j = 0; j < nums.size(); ++j){
//            cout<<nums[j]<<" ";
//        }
//        cout<<endl;
        if (nums[i] <= 0 || nums[i]==i+1) continue;
        while ( nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]){
            //保证nums[i]在ums[i]-1的位置上
            tmp = nums[i];
            nums[i] = nums[tmp-1];
            nums[tmp-1] = tmp;
        }

    }
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i]!= i+1) return i+1;
    }
    return nums.size()+1;
}
int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(1);
    cout<<firstMissingPositive(nums);
}
