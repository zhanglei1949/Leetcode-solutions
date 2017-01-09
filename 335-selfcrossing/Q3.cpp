#include<iostream>
#include<vector>
using namespace std;

bool isSelfCrossing(vector<int> &x)
{
    int len = x.size();
    if (len <= 3)
        return false;
    // length less than 3, no cross can appear
    for (int i = 3; i < len; ++i){
        // start from len=4
        //case one: current line cross with line i-3
        if (x[i]>=x[i-2] && x[i-1]<=x[i-3]){
            return true;
        }
        else if (i>=4 && x[i-1]==x[i-3] && x[i]+x[i-4] >= x[i-2]){
            //case two: current line cross with line i-4
            return true;
        }
        else if (i>=5){
            if (x[i-1] <= x[i-3] && x[i-1] >= x[i-3]-x[i-5] &&
                x[i-2] >= x[i-4] && x[i]+x[i-4] >= x[i-2])
            //case three: current line cross with line i-5
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> x;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i){
        int tmp;
        cin>>tmp;
        x.push_back(tmp);
    }
    cout<<isSelfCrossing(x);

}
