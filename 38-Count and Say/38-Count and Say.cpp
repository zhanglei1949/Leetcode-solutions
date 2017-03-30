#include<iostream>
#include<string>
using namespace std;
string return_str(string str);
string countAndSay(int n)
{
    string res = "1";
    for (int i = 0; i < n-1; ++i){
        res = return_str(res);
        //cout<<res<<endl;
    }
    return res;
}
string return_str(string str)
{
    string res = "";
    for (int i = 0; i < str.size();){
        //cout<<i<<" ";
        int j = i+1;
        while (j < str.size() && str[j]==str[i]) j++;
        if (j==i+1){
            res+='1';
            res+=str[i];
            //cout<<"1"<<str[i]<<endl;
            i++;
        }
        else {
            int times = j-i;
            res+=times+'0';
            res+=str[i];
            //cout<<times<<str[i]<<endl;
            i = j;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    cout<<countAndSay(n);
}
