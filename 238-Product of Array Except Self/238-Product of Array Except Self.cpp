#include<iostream>
#include<vector>

using namespace std;
vector<int> productExceptSelf1(vector<int>& nums)
{
    vector<int> res;
    int len = nums.size();
    for (int i = 0; i < len-1; ++i){
        res.push_back(nums[i+1]);
    }
    res.push_back(nums[0]);
    for (int i = 1; i < len-1; ++i){
        for (int j = 0; j < len; ++j){
            res[j] = res[j]*nums[(j+i+1)%len];
            //cout<<res[j]<<" ";
        }
        //cout<<endl;
    }
    return res;
}
vector<int> productExceptSelf(vector<int>& nums)
{
    // divide the product into two parts, product of elements on the left hand and right hand.
    vector<int> res(nums.size());
    res[0] = 1;
    int len = nums.size();
    for (int i = 1; i < len; ++i){
        res[i] = res[i-1] * nums[i-1];
    }
//    for (int i = 0; i < len; ++i){
//        cout<<res[i]<<" ";
//    }
//    cout<<endl;
    int tmp = 1;
    for (int i = len - 2; i >= 0; --i){
        tmp = tmp*nums[i+1];
        res[i]  = res[i]*tmp;
    }
//    for (int i = 0; i < len; ++i){
//        cout<<res[i]<<" ";
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
    productExceptSelf(nums);
}
