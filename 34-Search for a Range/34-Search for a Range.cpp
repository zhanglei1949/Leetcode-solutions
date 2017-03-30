#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& nums, int target)
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
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> res;
    if (nums.size()==0 || binary_search(nums, target)==-1){
        res.push_back(-1);
        res.push_back(-1);
        //cout<<-1<<" "<<-1<<endl;
        return res;
    }
    else {
        int left = binary_search(nums,target);
        int right = left;
        while (left > 0 && nums[left-1]==target) left--;
        while (right < nums.size()-1 && nums[right+1]==target) right++;
        res.push_back(left);
        res.push_back(right);
        return res;
    }
}
int main()
{
    vector<int> nums;
    int n;
    int tmp;
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    int target;
    cin>>target;
    //cout<<binary_search(nums,target);
    vector<int> res = searchRange(nums, target);
    cout<<res[0]<<" "<<res[1];
}
