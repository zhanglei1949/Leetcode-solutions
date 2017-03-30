#include<iostream>
#include<vector>
using namespace std;

bool isValidSudoku(vector<vector<char> >& board)
{

    //row
    for (int i = 0; i < 9; ++i){
        vector<int> flag(10,0);
        for (int j = 0; j < 9; ++j){
            if (board[i][j]=='.')
                continue;
            else {
                int tmp = board[i][j]-'0';
                if (flag[tmp]==0) flag[tmp] = 1;
                else return false;
            }
        }
    }
    //col
    for (int i = 0; i < 9; ++i){
        vector<int> flag(10,0);
        for (int j = 0; j < 9; ++j){
            if (board[j][i]=='.')
                continue;
            else {
                int tmp = board[j][i]-'0';
                if (flag[tmp]==0) flag[tmp] = 1;
                else return false;
            }
        }
    }
    //square
    for (int row_base = 0; row_base <= 6; row_base+=3){
        for (int col_base = 0; col_base <= 6; col_base+=3){
            vector<int> flag(10,0);
            for (int i = row_base; i < row_base+3; ++i){
                for (int j = col_base; j < col_base+3; ++j){
                    if (board[i][j]=='.') continue;
                    else {
                        int tmp = board[i][j] - '0';
                        if (flag[tmp]==0) flag[tmp] = 1;
                        else return false;
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<char> > board;
    vector<char> tmp;
    char c;
    for (int i = 0; i < 9; ++i){
        tmp.clear();
        for (int j = 0; j < 9; ++j){
            cin>>c;
            tmp.push_back(c);
        }
        //cin>>c;
        board.push_back(tmp);
    }
    cout<<isValidSudoku(board);
}
//
