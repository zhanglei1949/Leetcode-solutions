#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(vector<int> &nums, int visited[], int level, vector<int> &current, vector<vector<int> > &res);
vector<vector<int> > permuteUnique(vector<int> &nums)
{
    vector<vector<int> > res;
    vector<int> current;
    int *visited = new int[nums.size()];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) visited[i] = 0;
    dfs(nums, visited, 0, current, res);;
    return res;
}
void dfs(vector<int> &nums, int visited[], int level, vector<int> &current, vector<vector<int> > &res)
{
    if (level == nums.size()){
        res.push_back(current);
        return ;
    }
    for (int i = 0; i < nums.size(); ++i){
        if (visited[i] == 0){
            if (i>0 && nums[i]==nums[i-1] && visited[i-1]==0) continue;
            //此句的作用在于保证相同的元素以唯一的顺序出现
            current.push_back(nums[i]);
            visited[i] = 1;
            dfs(nums,visited, level+1, current, res);
            visited[i] = 0;
            current.pop_back();
        }
    }
}
int main()
{
    vector<int> nums;
    int n;
    int tmp;
    cin>>n;
    for (int i = 0; i < n; ++i){
        cin>>tmp;
        nums.push_back(tmp);
    }
    vector<vector<int> >res = permuteUnique(nums);
    for (int i = 0; i < res.size(); ++i){
        for (int j = 0; j < res[i].size(); ++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
