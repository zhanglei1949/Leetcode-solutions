#include<iostream>

using namespace std;

int divide(int dividend, int divisor)
{
    //1. sign
    //2. overflow
    int sign = 0;
    int overflow = 0;
    int res = 0;
    if (dividend==-2147483648 && divisor==-1) return 2147483647;
    if (dividend < 0){
        sign = 1-sign;
        dividend = -dividend;
    }
    if (divisor < 0){
        sign = 1-sign;
        divisor = -divisor;
    }
    if (divisor==1)
        if (sign) return -dividend;
        else return dividend;
    //cout<<dividend<<" "<<divisor<<endl;
    while (dividend >= divisor){
        if (res==2147483647 && !sign){
            overflow = 1;
            break;
        }
        if (res==2147483647 && sign){
            overflow = 2;
            break;
        }
        res+=1;
        dividend -= divisor;
    }
    //cout<<overflow<<" "<<res<<endl;
    if (sign) res = -res;
    if (overflow==0) return res;
    else if (overflow==1) return 214783647;
    else return -214783648;
}
//-2147483648 -1
int main()
{
    int dividend;
    int divisor;
    cin>>dividend>>divisor;
    cout<<divide(dividend, divisor);
}
