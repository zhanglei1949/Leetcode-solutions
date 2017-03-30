#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< vector<int> > res;

bool cmp(const int a, const int b)
{
    return a>b;
}
void dfs(vector<int> & sol, vector<int> & candidates, int target, int level)
{
    cout<<"dfs: target: "<<target<<" level: "<<level<<endl;
    cout<<"    current sol: ";
    for (int i = 0; i < sol.size(); ++i){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
    if (target == 0){
        res.push_back(sol);
        cout<<"push to res"<<endl;
        return ;
    }
    if (level == candidates.size()) return ;
    for (int i = level; i < candidates.size(); ++i){
        if (candidates[i] > target) continue;
        sol.push_back(candidates[i]);
        dfs(sol, candidates, target - candidates[i], i);
        sol.pop_back();
    }
}
vector<vector<int> > combinationSum(vector<int> & candidates ,int target)
{

    vector<int> sol;
    if (candidates.size()==0) return res;
    sort(candidates.begin(), candidates.end(), cmp);
    //if (candidates[0] < target) return res;
    //
    dfs(sol, candidates, target, 0);
    return res;
}
int main()
{
    vector<int> candidates;
    int target;
    //candidates.push_back(2);
    candidates.push_back(1);
    //candidates.push_back(3);
    //candidates.push_back(6);
    //candidates.push_back(7);
    target = 2;
    combinationSum(candidates, target);
}
