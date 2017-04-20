#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{

    vector<int> res;
    if (matrix.size()==0) return res;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < (min(m,n)+1)/2; ++i){
        cout<<1<<endl;
        for (int j = i; j < n-i; ++j){
            res.push_back(matrix[i][j]);
            cout<<"["<<i<<"] ["<<j<<"]: "<<matrix[i][j]<<endl;
        }
        cout<<2<<endl;
        for (int j = i+1; j < m-i; ++j){
            res.push_back(matrix[j][n-i-1]);
            cout<<"["<<j<<"] ["<<n-i-1<<"]: "<<matrix[j][n-i-1]<<endl;
        }
        cout<<3<<endl;
        for (int j = n-i-2; j >= i ; --j){
            if (m-i-1==i) break;
            res.push_back(matrix[m-i-1][j]);
            cout<<"["<<m-i-1<<"] ["<<j<<"]: "<<matrix[m-i-1][j]<<endl;
        }
        cout<<4<<endl;
        for (int j = m-i-2; j >=i+1 ; --j){
            if (i == n-i-1) break;
            res.push_back(matrix[j][i]);
            cout<<"["<<j<<"] ["<<i<<"]: "<<matrix[j][i]<<endl;
        }
    }
    return res;
}
int main()
{
    vector<vector<int> >matrix;
    vector<int> tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(4);
    tmp.push_back(5);
    tmp.push_back(6);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(7);
    tmp.push_back(8);
    tmp.push_back(9);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(11);
    tmp.push_back(12);
    tmp.push_back(13);
    matrix.push_back(tmp);
    tmp.clear();
    tmp.push_back(14);
    tmp.push_back(15);
    tmp.push_back(16);
    matrix.push_back(tmp);
    vector<int> res = spiralOrder(matrix);
    for (int i = 0; i < res.size(); ++i) cout<<res[i]<<" ";
}
