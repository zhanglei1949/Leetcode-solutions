#include<iostream>

using namespace std;

string longestPalindrome(string s)
{
    string res;
    int len = s.size();
    int maximum = 0;
    int res_i = 0;
    int res_j = 0;
    int **flag = new int *[eln];
    for (int i = 0; i < len; ++i){
        flag[i] = new int [len];
    }
    //cout<<flag[1][1];
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            flag[i][j] = 0;
        }
    }
    for (int i = 0; i < len; ++i){
        flag[i][i] = 1;
    }
    for (int i = 0; i+1 < len; ++i){
        if (s[i]==s[i+1]){
            flag[i][i+1] = 2;
        }
    }
    for (int l = 2; l < len; ++l){
        for (int i = 0; i+l < len; ++i){
            if (s[i] == s[i+l] && flag[i+1][i+l-1]){
                flag[i][i+l] = l+1;
            }
        }
    }
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            if (flag[i][j] && flag[i][j] > maximum){
                res_i = i;
                res_j = j;
                maximum = flag[i][j];
            }
        }
    }
//    for (int i = 0; i < len; ++i){
//        for (int j = 0; j < len; ++j){
//            cout<<flag[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    //cout<<res_i<<" "<<res_j<<endl;
    res = s.substr(res_i,maximum);
    return res;
}
int main()
{
    string s= "abcbs";
    cout<<s<<endl;
    int a[5][3];
    cout<<longestPalindrome(s);
}
