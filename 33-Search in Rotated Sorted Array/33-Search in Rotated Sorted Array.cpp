#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int>& nums, int start, int end, int target)
{
    //cout<<start<<" "<<end<<endl;
    if (start > end) return -1;
    if (start==end){
        if (nums[start]==target) return start;
        else return -1;
    }
    int mid = (start+end)/2;
    if (nums[mid]==target){
        return mid;
    }
    else if (nums[mid]<target){
        return binary_search(nums,mid+1, end, target);
    }
    else return binary_search(nums, start,mid-1, target);
}
int search(vector<int>& nums, int target)
{
    if (nums.size()==0) return -1;
    int pos = 0;
    for (int i = 0; i < nums.size()-1; ++i){
        if (nums[i] > nums[i+1]){
            pos = i;
            break;
        }
    }
    int res = binary_search(nums,0,pos,target);
    if (res==-1){
        return binary_search(nums,pos+1, nums.size()-1, target);
    }
    else return res;
}

int main()
{
    vector<int> nums;
    int target;
    int n;
    int tmp;
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    cin>>target;
    //cout<<binary_search(nums, 0,n-1, target);
    cout<<search(nums, target);
}
