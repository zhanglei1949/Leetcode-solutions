#include<iostream>
using namespace std;

int a[205]={0};
bool dp[20005]={0};
int judge(int sum, int n);
int main()
{
    int n;
    cin>>n;
    int sum = 0;
    for (int i = 0; i < n; ++i){
        cin>>a[i];
        sum+=a[i];
    }
    if (judge(sum, n)){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}
int judge(int sum, int n)
{
    if (sum%2 == 1){
        return 0;
    }
    else {
        int target = sum/2;
        dp[0]=0;
        for (int i = 0; i < n; ++i){
            dp[a[i]]=true;
        }
        for (int i = 0; i < n; ++i){
            for (int j = target; j >= a[i]; --j){
                dp[j] = dp[j]||dp[j-a[i]];
            }
            if (dp[target]){
                return 1;
            }
        }
    }
    return 0;
}
