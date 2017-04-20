#include<iostream>
#include<vector>
using namespace std;
void swap(int i1, int j1, int i2, int j2, vector<vector<int> > &matrix);
void rotate(vector<vector<int> >& matrix)
{
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = i; j < matrix[i].size()-i-1; ++j){
            swap(i,j,j,matrix.size()-1-i,matrix);
            swap(i,j,matrix.size()-1-i,matrix.size()-1-j,matrix);
            swap(i,j,matrix.size()-1-j, i,matrix);
        }
    }
//    for (int i = 0; i < matrix.size(); ++i){
//        for (int j = 0; j < matrix[i].size(); ++j){
//            cout<<matrix[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
void swap(int i1, int j1, int i2, int j2, vector<vector<int> > &matrix)
{
    int tmp = matrix[i1][j1];
    matrix[i1][j1] = matrix[i2][j2];
    matrix[i2][j2] = tmp;
}

int main()
{
    vector<vector<int> > matrix;
    vector<int> tmp;
    int a;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i){
        tmp.clear();
        for (int j = 0; j < n; ++j){
            cin>>a;
            tmp.push_back(a);
        }
        matrix.push_back(tmp);
    }
    rotate(matrix);
}
