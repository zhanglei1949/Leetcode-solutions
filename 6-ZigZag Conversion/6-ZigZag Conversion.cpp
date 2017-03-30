#include<iostream>

using namespace std;

 string convert(string s, int numRows)
 {
     string res;
     int len = s.size();
     int tmp = 0;
     if (numRows == 1){
        return s;
     }
     if (numRows == 2){
        for (int i = 0; i < len; i=i+2){
            res += s[i];
        }
        for (int i = 1; i < len; i=i+2){
            res += s[i];
        }
        return res;
     }
     while (tmp < len){
        res += s[tmp];
        tmp = tmp+2*(numRows-1);
     }
     for (int i = 1; i < numRows-1; ++i){
        int data[2]={2*(numRows-1-i), 2*i};
        int flag = 0;
        int j = i;
        while (j < len){
            res += s[j];
            j += data[flag];
            flag = (flag+1)%2;
        }
     }
     tmp = numRows-1;
     while (tmp < len){
        res += s[tmp];
        tmp = tmp+2*(numRows-1);
     }
     return res;
 }

int main()
{
    string s="ABC";
    int rows = 1;
    cout<<convert(s,rows);
}
