#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> > &res, vector<int> &tmp, int k, int target, int level)
{
    //cout<<"dfs :"<<k<<" "<<target<<" "<<level<<endl;
    for (int i = 0; i < tmp.size(); ++i){
        //cout<<tmp[i]<<" ";
    }
    //cout<<endl;
    if (target == 0&& k == 0){
        //cout<<"target == 0 push "<<endl;
        res.push_back(tmp);
        return ;
    }
    if (k == 0|| level == 10) return ;
    for (int i = level; i < 10; ++i){
        if (i > target) break;
        else {
            tmp.push_back(i);
            dfs(res, tmp, k-1, target - i, i+1);
            tmp.pop_back();
        }
    }
    return ;
}
vector<vector<int> > combinationSum3(int k, int n)
{
    //k numbers add up to n
    vector<vector<int> > res;
    vector<int> tmp;
    //only use 1~9
    dfs(res, tmp, k, n, 1);
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
    int k;
    int n;
    cin>>n>>k;
    combinationSum3(k, n);
}
