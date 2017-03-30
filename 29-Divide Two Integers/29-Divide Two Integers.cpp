#include<iostream>

using namespace std;

int divide(int dividend, int divisor)
{
    int res = 0;
    int flag = 1;
    if (dividend<0){
        flag = 0;
        dividend = -dividend;
    }
    if (divisor<0){
        flag = 1-flag;
        divisor = -divisor;
    }
    while (dividend>=divisor){
        dividend  -= divisor;
        if (res==2147483647){
            if (!flag){
                return -res-1;
            }
            else {
                return 2147483647;
            }
        }
        res++;
    }
    //cout<<flag<<endl;
    if (!flag) return -res;
    return res;
}

int main()
{
    int dividend;
    int divisor;
    cin>>dividend>>divisor;
    cout<<divide(dividend, divisor);
}
