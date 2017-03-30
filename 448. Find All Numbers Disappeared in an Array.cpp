#include<iostream>
#include<vector>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int>::iterator iter;
    int length = nums.size();
    vector<int> res;
    int *flag = new int [length+1];
    for (int i = 1; i <= length; ++i)
        flag[i] = 0;
    for (int i = 0; i < length; ++i){
        flag[nums[i]] = 1;
    }
    for (int i = 1; i <= length; ++i){
        if (!flag[i])
            res.push_back(i);
    }
    return res;
}
int main()
{
    vector<int> a(6);
    for (int i = 0; i <= 5; ++i){
        a[i] = i+1;
    }
    a[5] = 5;
    a[3] = 1;
    for (int i = 0; i <= 5; ++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    findDisappearedNumbers(a);
}
