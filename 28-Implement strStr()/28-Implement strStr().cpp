#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int strStr(string haystack, string needle)
{
    //implement
    int len_h = haystack.size();
    int len_n = needle.size();
    if (len_h < len_n) return -1;
    if (len_n==0) return 0;
    if (len_h == 0) return -1;
    for (int i = 0; i <= len_h-len_n; ++i){
        if (haystack[i]==needle[0]){
            bool flag = true;
            for (int j = 1; j < len_n; ++j){
                if (needle[j]!=haystack[i+j]){
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
    }
    return -1;
}
int main()
{
    string haystack;
    string needle;
    cin>>haystack>>needle;
    cout<<strStr(haystack, needle);
}
