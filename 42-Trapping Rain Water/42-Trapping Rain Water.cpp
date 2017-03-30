#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int> &height)
{
    int res = 0;
    int len = height.size();
    int right = len-1;
    int max_left = 0;
    int max_right = 0;
    int left = 0;
    while (left < len-1 && height[left] <= height[left+1]) left++;
    while (right > left && height[right] <= height[right-1]) right--;


    while (left <= right){
        if (height[left] <= height[right]){
            if (height[left] >= max_left) max_left = height[left];
            else res+=max_left-height[left];
            left++;
        }
        else {
            if (height[right] >= max_right) max_right = height[right];
            else res+=max_right-height[right];
            right--;
        }
    }
    return res;
}
int main()
{
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    cout<<trap(height);
}
