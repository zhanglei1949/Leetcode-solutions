#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    vector<int>::iterator iter;
    for (iter = nums.begin(); iter!= nums.end();){
        if (*iter==val){
            iter = nums.erase(iter);
        }
        else ++iter;
    }
    return nums.size();
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
    int val;
    cin>>val;
    removeElement(nums, val);
    cout<<nums.size()<<endl;
    for (int i = 0; i < nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
}
