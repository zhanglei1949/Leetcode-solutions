#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<int> > fourSum(vector<int>& nums, int target)
{
    vector<vector<int> > res;
    //four layers
    int len = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < len; ++i){
        if (i > 0 && nums[i]==nums[i-1])
            continue;

        for (int j = i+1; j < len; ++j){
            if (j > i+1 && nums[j] == nums[j-1])
                continue;

            int head = j+1;
            int rear = len-1;
            int tmp_target = target - nums[i] - nums[j];
            while (head < rear){
                //cout<<i<<" "<<j<<" "<<head<<" "<<rear<<endl;
                if (nums[head]+nums[rear]==tmp_target){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[head]);
                    tmp.push_back(nums[rear]);
                    res.push_back(tmp);
                    //cout<<"push"<<nums[i]<<" "<<nums[j]<<" "<<nums[head]<<" "<<nums[rear]<<endl;
                    head++;

                    while (head < rear && nums[head]==nums[head-1]){
                        head++;
                    }
                    rear--;
                    while (head < rear && nums[rear]==nums[rear+1]){
                        rear--;
                    }
                }
                else if (nums[head] + nums[rear] < tmp_target){
                    head++;
                }
                else {
                    rear--;
                }
            }
        }
    }
//    for (int i = 0; i < res.size(); ++i){
//        for (int j = 0; j < res[i].size(); ++j){
//            cout<<res[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return res;

}
int main()
{
    int n;
    int target;
    vector<int> nums;
    cin>>n>>target;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    fourSum(nums, target);
}
