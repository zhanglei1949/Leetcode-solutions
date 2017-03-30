#include<iostream>
#include<cmath>
using namespace std;

int divide(int dividend, int divisor)
{
    int sign = 1;
    long long res = 0;
    long long bits = 1;
    if (dividend < 0) sign = -sign;
    if (divisor < 0) sign = -sign;
    //cout<<sign<<endl;
    long long dividend2 = abs((long long) dividend);
    long long divisor2 = abs((long long) divisor);
    //cout<<dividend2<<" "<<divisor2<<endl;
    while (divisor2 < dividend2){
        bits = bits<<1;
        divisor2 = divisor2<<1;
    }
    //cout<<bits<<" "<<divisor2<<endl;
    while (dividend2 >= abs((long long) divisor)){
        while (dividend2 >= divisor2){
            dividend2 = dividend2 - divisor2;
            res += bits;
        }
        divisor2 = divisor2>>1;
        bits = bits>>1;
    }
    //cout<<res<<endl;
    res = sign*res;
    if (res > 2147483647) return 2147483647;
    else if (res < -2147483648) return -2147483648;
    else return res;
}
int main()
{
    int dividend;
    int divisor;
    cin>>dividend>>divisor;
    cout<<divide(dividend, divisor);
}
