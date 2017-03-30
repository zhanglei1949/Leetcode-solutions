#include<iostream>

using namespace std;
//Only 1s and 2s are possible
//wrong answer
int magicalString(int n)
{
    if (n<=3) return 1;
    else if (n<=4) return 2;
    else if (n<=5) return 3;
    int group[100000]={0};//equal to 1 or 2
    int times[100000]={0};//apperance times
    int cnt = 0;
    string res;
    int len;
    bool flag;//0 for 1, 1 for 2
    //initialize
    group[0]=1; group[1]=2; group[2]=1;
    times[0]=1; times[1]=2; times[2]=2;
    res="12211";
    len = 5;
    cnt = 3;
    flag = 1;
    int ones = 3;
    while (len < n){
        cout<<res[cnt]-'0'<<endl;
        times[cnt] = res[cnt]-'0';
        if (flag) group[cnt] = 2;
        else{
            group[cnt] = 1;
            ones+=times[cnt];
        }
        for (int i = 0; i < times[cnt]; ++i){
            res+=('0'+group[cnt]);
        }
        len+=times[cnt];
        cnt++;
        flag=!flag;
        cout<<res<<endl;
    }
    return ones;
}

int main()
{
    int n;
    cin>>n;
    cout<<magicalString(n);
}
