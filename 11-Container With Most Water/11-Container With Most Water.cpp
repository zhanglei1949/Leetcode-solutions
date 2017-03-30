#include<iostream>
#include<vector>
using namespace std;

int maxarea(vector<int> &height)
{
    int len = height.size();
    int head = 0;
    int rear = len - 1;
    //two pointer
    int maximum = 0;
    int tmp;
    while (rear > head){

        maximum = max(min(height[head], height[rear])*(rear-head), maximum);
        // move the lower one
        //cout<<head<<" "<<rear<<" "<<maximum<<endl;
        if (height[rear] < height[head]){
            tmp = rear;
            while (tmp > head && height[tmp] <= height[rear]){
                tmp--;
            }
            rear = tmp;
        }
        else {
            tmp = head;
            while (tmp < rear && height[tmp] <= height[head]){
                tmp++;
            }
            head = tmp;
        }
    }
    return maximum;
}
int main()
{
    vector<int> height;
    int n;
    cin>>n;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        height.push_back(tmp);
    }
    cout<<maxarea(height);
}
