#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int res = nums.size();
    for (int i = 1; i < nums.size(); ){
        if (nums[i]==nums[i-1]){
            res--;
            nums.erase(nums.begin()+i);
        }
        else i++;
    }
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
    cout<<removeDuplicates(nums)<<endl;
    for (int i = 0; i < nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
}
