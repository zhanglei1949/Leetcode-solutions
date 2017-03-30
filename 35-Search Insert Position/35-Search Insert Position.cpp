#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>& nums, int target)
{
    int l = 0;
    int h = nums.size()-1;
    int mid = (l+h)/2;
    while (l <= h){
        //cout<<l<<" "<<h<<endl;
        mid = (l+h)/2;
        if (nums[mid]==target) return mid;
        else if (nums[mid] < target) l = mid+1;
        else h = mid-1;
    }
    return l;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    int target = 2;
    cout<<searchInsert(nums,target);
}
