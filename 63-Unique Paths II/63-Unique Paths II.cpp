#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
{
    int res=0;
    if (obstacleGrid.size()==0) return 0;
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    //cout<<m<<" "<<n<<endl;
    int **dp = new int *[m];
    for (int i = 0; i < m; ++i) dp[i] = new int [n];
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (i==0 && j==0){
                if (!obstacle[i][j]) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else if (i==0){
                if (!obstacleGrid[i][j]) dp[i][j] = dp[i][j-1];
                else dp[i][j] = 0;
            }
            else if (j==0){
                if (!obstacleGrid[i][j]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = 0;
            }
            else {
                if (!obstacleGrid[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else dp[i][j] = 0;
            }
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<int> row;
    row.push_back(0);
    row.push_back(0);
    row.push_back(0);
    vector<vector<int> > obstacleGrid;
    obstacleGrid.push_back(row);
    obstacleGrid.push_back(row);
    obstacleGrid.push_back(row);
    obstacleGrid[1][1] = 1;
    cout<<uniquePathsWithObstacles(obstacleGrid);
}
