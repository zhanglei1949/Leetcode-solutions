#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int tmp;
    int len = nums.size();
    // next permutation
    //first find the last ascending position
    //then find the last element that is greater than position, exchange positions;
    //finally reverse numbers after position

    int pos = len-1;
    while (pos > 0){
        if (nums[pos] > nums[pos-1]){
            pos = pos-1;
            break;
        }
        pos--;
        if (pos==0){
            reverse(nums.begin(), nums.end());
            return ;
        }
    }
    //cout<<pos<<endl;

    //ascending order exits;
    for (int i = len-1; i > pos; --i){
        if (nums[i] > nums[pos]){
            tmp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = tmp;
            break;
        }
    }
//    for (int i = 0; i < nums.size(); ++i){
//        cout<<nums[i]<<" ";
//    }
    reverse(nums.begin()+pos+1,nums.end());
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
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
}
