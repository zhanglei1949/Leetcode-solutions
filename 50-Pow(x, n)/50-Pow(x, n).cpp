#include<iostream>
#include<cmath>
using namespace std;

double myPow0(double x, int n)
{
    int pow_num = 0;
    int flag = 0;
    if (n==0) return 1;
    else if (n>0) pow_num = n;
    else{
        pow_num = -n;
        flag = 1;
    }
    double y = 1;
    for (int i = 0; i < pow_num; ++i){
        y = y*x;
    }
    if (flag==0) return y;
    else return 1.0/y;
}
double myPow(double x, int n)
{
    if (n==0) return 1;
    if (n==1) return x;
    if (n < 0) return myPow(1/x, long(-n));
    double tmp = myPow(x,n/2);
    if (n%2==1){
        return tmp*tmp*x;
    }
    else return tmp*tmp;
}
int main()
{
    cout<<myPow(2.0,-3);
}
