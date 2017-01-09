#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int minimumMove(vector<int>& nums)
{
    int size = nums.size();
    // 不论怎么选取target， 最大数和最小数之间差距弥补
    //cout<<average<<" "<<target<<endl;
    sort(nums.begin(),nums.end());
    int totalMoves = 0;
    int i,j;
    i = 0;
    j = size - 1;
    while (i<j){
        totalMoves += (nums[j--]-nums[i++]);
    }
    return totalMoves;
}
int main()
{
    int tmp;

    cin>>n;
    vector<int> nums;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }

    cout<<minimumMove(nums);


}
