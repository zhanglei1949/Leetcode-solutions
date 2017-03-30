#include<iostream>

using namespace std;


int reverse(int x)
{
    int tmp = x;
    int data[10];
    for (int i = 0; i < 10; ++i){
        data[i] = 0;
    }
    int const1[10]={2,1,4,7,4,8,3,6,4,7};
    //1563847412
    int const2[10]={2,1,4,7,4,8,3,6,4,8};
    bool flag = 0;
    if (tmp < 0){
        tmp = -tmp;
        flag =1;
    }
    // 0 - 2^31-1 2147483647
    // -1 - 2^31
    // tmp is already positive
    int t = 0;
    int cnt = 0;
    while (tmp > 0){
        t = tmp%10;
        tmp = tmp/10;
        data[cnt++] = t;
    }
    bool overflow = 0;
    if (!flag){
        int i;
        for (i = 0; i < cnt; ++i){
            if (data[i]<const1[i]){
                overflow = 0;
                break;
            }
            else if (data[i]>const1[i]){
                overflow = 1;
                break;
            }
        }
        //cout<<i<<" "<<cnt<<endl;
        if (i==cnt) overflow = 0;
    }
    else {
        int i;
        for (i = 0; i < cnt; ++i){
            if (data[i]<const2[i]){
                overflow = 0;
                break;
            }
            else if (data[i]>const2[i]){
                overflow = 1;
                break;
            }
        }
        //cout<<i<<" "<<cnt<<endl;
        if (i==cnt) overflow = 0;
    }
    if (cnt<10) overflow = 0;
    int res = 0;
    //cout<<"overflow"<<overflow<<endl;
    if (overflow) return 0;
    else {
        for (int i = 0; i < cnt; ++i){
            res = res*10 + data[i];
        }
    }
    if (flag) return -res;
    return res;
}
int main()
{
    int x;
    cin>>x;

    cout<<reverse(x);
}
